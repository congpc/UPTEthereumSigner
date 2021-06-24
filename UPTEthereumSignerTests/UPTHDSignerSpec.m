//
//  UPTHDSignerSpec.m
//  UPTEthereumSignerTests
//
//  Created by William Morriss on 7/5/18.
//  Copyright © 2018 ConsenSys. All rights reserved.
//

#import <XCTest/XCTest.h>
//#import "Specta/Specta.h"
@import Specta;
//@import UPTEthereumSigner;
@import CoreEth;
@import Foundation;
//#import "EthCore/EthCore.h"

#import "UPTHDSigner.h"


SpecBegin(UPTHDSigner)

describe(@"key creation, address retrieval", ^{
    
    it(@"can create keys", ^{
        [UPTHDSigner createHDSeed:UPTHDSignerProtectionLevelPromptSecureEnclave
            rootDerivationPath:UPORT_ROOT_DERIVATION_PATH
            callback:^(NSString *ethAddress, NSString *publicKey, NSError *error) {
            NSLog(@"eth address: %@ . for public key: %@", ethAddress, publicKey);
            XCTAssertNil(error);
            XCTAssertEqual(ethAddress.length, 42);
        }];
    });

    it(@"creates deterministic keys", ^{
        NSString *phrase = @"army girl debate clog ensure crumble amused casual hard vapor review release";
        [UPTHDSigner
            importSeed:UPTHDSignerProtectionLevelPromptSecureEnclave
            phrase:phrase
            rootDerivationPath:METAMASK_ROOT_DERIVATION_PATH
            callback:^(NSString *rootEthAddress, NSString *publicKey, NSError *error) {
                XCTAssertNil(error);
                XCTAssertEqualObjects(rootEthAddress, @"0x108ceb4960947426ae50ded628a49df6856ce851");
//                expect(error).to.beNil();
//                expect(rootEthAddress).to.equal(@"0x108ceb4960947426ae50ded628a49df6856ce851");
                #define checkChild(index, expectedAddress) \
                [UPTHDSigner\
                    computeAddressForPath:rootEthAddress\
                    derivationPath:[METAMASK_ROOT_DERIVATION_PATH stringByAppendingString:@"/" index]\
                    prompt:@""\
                    callback:^(NSString *account0Address, NSString *account0PublicKey, NSError *error) {\
                        expect(account0Address).to.equal(expectedAddress);\
                    }\
                ];
//                checkChild("0", @"0x171d67ebf279e85aff100cdb96506d835d133589");
//                checkChild("1", @"0x9d24423d7bde30e69b0e4adcea5d94c53625bcb7");
//                checkChild("2", @"0xad0e692b1022a461e2c8ac68c4e8b3b243481d9a");
                #undef checkChild
            }
        ];
        [UPTHDSigner
            importSeed:UPTHDSignerProtectionLevelPromptSecureEnclave
            phrase:phrase
            rootDerivationPath:UPORT_ROOT_DERIVATION_PATH
            callback:^(NSString *rootEthAddress, NSString *publicKey, NSError *error) {
            XCTAssertNil(error);
                XCTAssertEqualObjects(rootEthAddress, @"0x1f03a97add0d17538c88ab058b472015094a45e7");
//                expect(error).to.beNil();
//                expect(rootEthAddress).to.equal(@"0x1f03a97add0d17538c88ab058b472015094a45e7");
            }
        ];
    });

    it(@"rejects invalid phrases", ^{
        [UPTHDSigner
            importSeed:UPTHDSignerProtectionLevelPromptSecureEnclave
            phrase:@"then cat cat cat cat cat cat cat cat cat cat cat"
            rootDerivationPath:UPORT_ROOT_DERIVATION_PATH
            callback:^(NSString *rootEthAddress, NSString *publicKey, NSError *error) {
                XCTAssertEqualObjects(rootEthAddress, nil);
                XCTAssertEqualObjects(publicKey, nil);
                XCTAssertEqual(error.code, UPTHDSignerErrorCodeInvalidSeedWords.integerValue);
//                expect(rootEthAddress).to.beNil();
//                expect(publicKey).to.beNil();
//                expect(error.code).to.equal(UPTHDSignerErrorCodeInvalidSeedWords.integerValue);
            }
        ];
    });
    
    
    describe(@"Deletion", ^{
        it(@"Can delete", ^{
            [UPTHDSigner createHDSeed:UPTHDSignerProtectionLevelPromptSecureEnclave
                   rootDerivationPath:UPORT_ROOT_DERIVATION_PATH
                             callback:^(NSString *ethAddress, NSString *publicKey, NSError *error) {
                                 NSLog(@"Deletion eth address: %@ . for public key: %@", ethAddress, publicKey);
                                 XCTAssertNil(error);
//                                 expect(error).to.beNil();
                                 [UPTHDSigner deleteSeed:ethAddress callback:^(BOOL deleted, NSError *error) {
                                     XCTAssertTrue(deleted);
                                     XCTAssertNil(error);
                                     [UPTHDSigner showSeed:ethAddress prompt:@"Test if seed still exists" callback:^(NSString *phrase, NSError *error2) {
                                         XCTAssertNil(phrase);
                                         XCTAssertNotNil(error2);
                                     }];
                                 }];
                             }];
        });
    });
    

});

SpecEnd
