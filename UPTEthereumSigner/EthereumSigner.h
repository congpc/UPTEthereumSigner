//
//  EthereumSigner.m
//  UPTEthereumSigner
//
//  Created by Cornelis van der Bent on 19/01/2019.
//  Copyright © 2019 ConsenSys. All rights reserved.
//

@import Foundation;
@import CoreEth;

NSMutableData *compressedPublicKey(EC_KEY *key);
NSDictionary *ethereumSignature(BTCKey *keypair, NSData *hash, NSData *chainId);
NSDictionary *jwtSignature(BTCKey *keypair, NSData *hash);
NSDictionary *genericSignature(BTCKey *keypair, NSData *hash, BOOL lowS);
NSData *simpleSignature(BTCKey *keypair, NSData *hash);
#ifdef NOT_USED
static int ECDSA_SIG_recover_key_GFp(EC_KEY *eckey, BIGNUM *r, BIGNUM *s, const unsigned char *msg, int msglen, int recid, int check);
#endif
