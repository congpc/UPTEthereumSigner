//
//  UPTEthSigner.h
//  UPTEthereumSigner
//
//  Created by josh on 10/18/17.
//  Copyright © 2017 ConsenSys AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UPTProtectionLevel.h"

/// @description level param is not recognized by the system
/// @debugStrategy add support for new level value or fix possible typo or incompatibility error on react native js side
FOUNDATION_EXPORT NSString * const UPTSignerErrorCodeLevelParamNotRecognized;
FOUNDATION_EXPORT NSString * const UPTSignerErrorCodeLevelPrivateKeyNotFound;
FOUNDATION_EXPORT NSString * const UPTSignerErrorCodeLevelSigningError;

/// @param ethAddress   An Ethereum address with prefix '0x'. May be nil if error occured
/// @param publicKey    A Base64 encoded representation of the NSData public key. Note: encoded with no line
///                     breaks. May be nil if error occured.
/// @param error        Non-nil only if an error occured.
typedef void (^UPTEthSignerKeyPairCreationResult)(NSString *ethAddress, NSString *publicKey, NSError *error);

typedef void (^UPTEthSignerTransactionSigningResult)(NSDictionary *signature, NSError *error);
typedef void (^UPTEthSignerJWTSigningResult)(NSDictionary *signature, NSError *error);
typedef void (^UPTEthSignerDeleteKeyResult)(BOOL deleted, NSError *error);

@class VALValet;

@interface UPTEthSigner : NSObject

+ (void)createKeyPairWithStorageLevel:(UPTEthKeychainProtectionLevel)protectionLevel
                               result:(UPTEthSignerKeyPairCreationResult)result;
+ (NSDictionary*)createKeyPairWithStorageLevel:(UPTEthKeychainProtectionLevel)protectionLevel;

+ (void)saveKey:(NSData *)privateKey
protectionLevel:(UPTEthKeychainProtectionLevel)protectionLevel
         result:(UPTEthSignerKeyPairCreationResult)result;

// keys: ethAddress,publicKey
+ (NSDictionary*)saveKey:(NSData *)privateKey
         protectionLevel:(UPTEthKeychainProtectionLevel)protectionLevel;

// If you are supplying chainID, your tx payload contains 9 fields; otherwise it contains 6
+ (void)signTransaction:(NSString *)ethAddress
                   data:(NSString *)payload
             userPrompt:(NSString *)userPromptText
                 result:(UPTEthSignerTransactionSigningResult)result __attribute__((deprecated));
+ (NSDictionary*)signTransaction:(NSString *)ethAddress
                            data:(NSString *)payload
                      userPrompt:(NSString*)userPromptText;

+ (void)signTransaction:(NSString *)ethAddress
    serializedTxPayload:(NSData *)serializedTxPayload
                chainId:(NSData *)chainId
             userPrompt:(NSString *)userPromptText
                 result:(UPTEthSignerTransactionSigningResult)result;
+ (NSDictionary*)signTransaction:(NSString *)ethAddress
             serializedTxPayload:(NSData *)payloadData
                         chainId:(NSData *)chainId
                      userPrompt:(NSString*)userPromptText;

+ (void)signJwt:(NSString *)ethAddress
     userPrompt:(NSString *)userPromptText
           data:(NSData *)payload
         result:(UPTEthSignerJWTSigningResult)result;
+ (NSDictionary*)signJwt:(NSString *)ethAddress
              userPrompt:(NSString *)userPromptText
                    data:(NSData *)payload;

+ (void)deleteKey:(NSString *)ethAddress result:(UPTEthSignerDeleteKeyResult)result;
+ (BOOL)deleteKey:(NSString *)ethAddress;

+ (NSArray *)allAddresses;

#pragma mark - Utils
+ (UPTEthKeychainProtectionLevel)protectionLevelWithEthAddress:(NSString *)ethAddress;
+ (NSString *)ethAddressWithPublicKey:(NSData *)publicKey;
+ (NSString *)privateKeyLookupKeyNameWithEthAddress:(NSString *)ethAddress;
+ (NSString *)protectionLevelLookupKeyNameWithEthAddress:(NSString *)ethAddress;
+ (VALValet *)ethAddressesKeystore;
+ (NSString *)keychainCompatibleProtectionLevel:(UPTEthKeychainProtectionLevel)protectionLevel;
+ (UPTEthKeychainProtectionLevel)protectionLevelFromKeychainSourcedProtectionLevel:(NSString *)protectionLevel;
+ (NSSet *)addressesFromKeystore:(UPTEthKeychainProtectionLevel)protectionLevel;
+ (BTCKey *)keyPairWithEthAddress:(NSString *)ethAddress
                   userPromptText:(NSString *)userPromptText
                  protectionLevel:(UPTEthKeychainProtectionLevel)protectionLevel;
+ (VALValet *)privateKeystoreWithProtectionLevel:(UPTEthKeychainProtectionLevel)protectionLevel;

+ (UPTEthKeychainProtectionLevel)enumStorageLevelWithStorageLevel:(NSString *)storageLevel;

+ (NSData *)keccak256:(NSData *)input;

+ (NSString *)hexStringWithDataKey:(NSData *)dataPrivateKey;

+ (NSData *)dataFromHexString:(NSString *)originalHexString;

// TODO: Move to utility class (after checking if this is not available elsewhere).
+ (NSString *)base64StringWithURLEncodedBase64String:(NSString *)URLEncodedBase64String;

// TODO: Move to utility class (after checking if this is not available elsewhere).
+ (NSString *)URLEncodedBase64StringWithBase64String:(NSString *)base64String;

@end
