//
//  UPTHDSigner.h
//  UPTEthereumSigner
//
//  Created by josh on 1/5/18.
//  Copyright © 2018 ConsenSys AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UPTProtectionLevel.h"

/// @param ethAddress    an Ethereum adderss with prefix '0x'. May be nil if error occured
/// @param publicKey    a base 64 encoded representation of the NSData public key. Note: encoded with no line
///                     breaks. May be nil if error occured.
/// @param error        non-nil only if an error occured
typedef void (^UPTHDSignerSeedCreationResult)(NSString *ethAddress, NSString *publicKey, NSError *error);

/// @param  phrase      12 space delimited words
typedef void (^UPTHDSignerSeedPhraseResult)(NSString *phrase, NSError *error);

typedef void (^UPTHDSignerTransactionSigningResult)(NSDictionary *signature, NSError *error);
typedef void (^UPTHDSignerJWTSigningResult)(NSDictionary *signature, NSError *error);

/// param privateKey is a base64 string
typedef void (^UPTHDSignerPrivateKeyResult)(NSString *privateKeyBase64, NSError *error);

typedef void (^UPTEthSignerDeleteSeedResult)(BOOL deleted, NSError *error);

FOUNDATION_EXPORT NSString * const UPTHDSignerErrorCodeLevelParamNotRecognized;
FOUNDATION_EXPORT NSString * const UPTHDSignerErrorCodeLevelPrivateKeyNotFound;
FOUNDATION_EXPORT NSString * const UPTHDSignerErrorCodeInvalidSeedWords;
FOUNDATION_EXPORT NSString * const UPTHDSignerErrorCodeLevelSigningError;

FOUNDATION_EXPORT NSString * const UPORT_ROOT_DERIVATION_PATH;
FOUNDATION_EXPORT NSString * const METAMASK_ROOT_DERIVATION_PATH;

@interface UPTHDSigner : NSObject

+ (BOOL)hasSeed;
+ (NSArray *)listSeedAddresses;

/// @param  callback contains phrase
+ (void)showSeed:(NSString *)rootAddress prompt:(NSString *)prompt callback:(UPTHDSignerSeedPhraseResult)callback;
+ (NSString*)showSeed:(NSString *)rootAddress prompt:(NSString *)prompt;

/// @param  callback     a root account Ethereum address and root account public key
// keys: ethAddress,publicKey
+ (void)createHDSeed:(UPTHDSignerProtectionLevel)protectionLevel
            callback:(UPTHDSignerSeedCreationResult)callback __attribute__((deprecated));
+ (NSDictionary*)createHDSeed:(UPTHDSignerProtectionLevel)protectionLevel;

+ (void)createHDSeed:(UPTHDSignerProtectionLevel)protectionLevel
  rootDerivationPath:(NSString *)rootDerivationPath
            callback:(UPTHDSignerSeedCreationResult)callback;
+ (NSDictionary*)createHDSeed:(UPTHDSignerProtectionLevel)protectionLevel
    rootDerivationPath:(NSString *)rootDerivationPath;

/// @param  callback     a root account Ethereum address and root account public key
+ (void)importSeed:(UPTHDSignerProtectionLevel)protectionLevel phrase:(NSString *)phrase
          callback:(UPTHDSignerSeedCreationResult)callback __attribute__((deprecated));
+ (NSDictionary*)importSeed:(UPTHDSignerProtectionLevel)protectionLevel phrase:(NSString *)phrase;

+ (void)importSeed:(UPTHDSignerProtectionLevel)protectionLevel
            phrase:(NSString *)phrase
rootDerivationPath:(NSString *)rootDerivationPath
          callback:(UPTHDSignerSeedCreationResult)callback;
+ (NSDictionary*)importSeed:(UPTHDSignerProtectionLevel)protectionLevel
            phrase:(NSString *)phrase
rootDerivationPath:(NSString *)rootDerivationPath;

+ (void)importSeed:(UPTHDSignerProtectionLevel)protectionLevel
             words:(NSArray<NSString *> *)words
rootDerivationPath:(NSString *)rootDerivationPath
          callback:(UPTHDSignerSeedCreationResult)callback;
+ (NSDictionary*)importSeed:(UPTHDSignerProtectionLevel)protectionLevel
                      words:(NSArray<NSString *> *)words
         rootDerivationPath:(NSString *)derivationPath;

/// @param  address     a root account Ethereum address
/// @param  callback    the derived Ethereum address and derived public key
+ (void)computeAddressForPath:(NSString *)address
               derivationPath:(NSString *)derivationPath
                       prompt:(NSString *)prompt
                     callback:(UPTHDSignerSeedCreationResult)callback;
+ (NSDictionary *)computeAddressForPath:(NSString *)address
               derivationPath:(NSString *)derivationPath
                       prompt:(NSString *)prompt;

// If you are supplying chainID, your tx payload contains 9 fields; otherwise it contains 6
/// @param  ethereumAddress     a root account Ethereum address
+ (void)signTransaction:(NSString *)ethereumAddress
         derivationPath:(NSString *)derivationPath
              txPayload:(NSString *)txPayload
                 prompt:(NSString *)prompt
               callback:(UPTHDSignerTransactionSigningResult)callback __attribute__((deprecated));
+ (NSDictionary *)signTransaction:(NSString *)rootAddress
                   derivationPath:(NSString *)derivationPath
                        txPayload:(NSString *)txPayload
                           prompt:(NSString *)prompt;

+ (void)signTransaction:(NSString *)rootAddress
         derivationPath:(NSString *)derivationPath
    serializedTxPayload:(NSData *)serializedTxPayload
                chainId:(NSData *)chainId
                 prompt:(NSString *)prompt
               callback:(UPTHDSignerTransactionSigningResult)callback;
+ (NSDictionary*)signTransaction:(NSString *)rootAddress
                  derivationPath:(NSString *)derivationPath
             serializedTxPayload:(NSData *)payloadData
                         chainId:(NSData *)chainId
                          prompt:(NSString *)prompt;

/// @param  ethereumAddress     a root account Ethereum address
+ (void)signJWT:(NSString *)ethereumAddress
 derivationPath:(NSString *)derivationPath
           data:(NSString *)data
         prompt:(NSString *)prompt
       callback:(UPTHDSignerJWTSigningResult)callback;
+ (NSDictionary*)signJWT:(NSString *)rootAddress
          derivationPath:(NSString *)derivationPath
                    data:(NSString *)data
                  prompt:(NSString *)prompt;

/// @param rootAddress  a root account Ethereum address
+ (void)privateKeyForPath:(NSString *)rootAddress
           derivationPath:(NSString *)derivationPath
                   prompt:(NSString *)prompt
                 callback:(UPTHDSignerPrivateKeyResult)callback;
+ (NSString*)privateKeyForPath:(NSString *)rootAddress
                derivationPath:(NSString *)derivationPath
                        prompt:(NSString *)prompt;

+ (void)deleteSeed:(NSString *)phrase callback:(UPTEthSignerDeleteSeedResult)callback;
+ (BOOL)deleteSeed:(NSString *)rootEthereumAddress;

#pragma mark - Utils
+ (NSString *)ethereumAddressWithPublicKey:(NSData *)publicKey;
+ (UPTHDSignerProtectionLevel)protectionLevelWithEthAddress:(NSString *)ethAddress;
+ (UPTHDSignerProtectionLevel)protectionLevelFromKeychainSourcedProtectionLevel:(NSString *)protectionLevel;
+ (VALValet *)privateKeystoreWithProtectionLevel:(UPTHDSignerProtectionLevel)protectionLevel;
+ (VALValet *)keystoreForProtectionLevels;
+ (NSString *)entropyLookupKeyNameWithEthAddress:(NSString *)ethAddress;
+ (NSString *)protectionLevelLookupKeyNameWithEthAddress:(NSString *)ethAddress;
+ (VALValet *)ethAddressesKeystore;
+ (NSString *)keychainCompatibleProtectionLevel:(UPTHDSignerProtectionLevel)protectionLevel;
+ (NSMutableData*)compressedPublicKey:(EC_KEY *)key;

+ (NSArray<NSString *> *)wordsFromPhrase:(NSString *)phrase;

+ (NSData*)randomEntropy;

+ (UPTHDSignerProtectionLevel)enumStorageLevelWithStorageLevel:(NSString *)storageLevel;

// TODO: Move to utility class (after checking if this is not available elsewhere).
+ (NSString *)base64StringWithURLEncodedBase64String:(NSString *)URLEncodedBase64String;

// TODO: Move to utility class (after checking if this is not available elsewhere).
+ (NSString *)URLEncodedBase64StringWithBase64String:(NSString *)base64String;

@end
