#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "EthCore/BTC256.h"
#import "EthCore/BTCAddress.h"
#import "EthCore/BTCAddressSubclass.h"
#import "EthCore/BTCBase58.h"
#import "EthCore/BTCBigNumber.h"
#import "EthCore/BTCBlockchainInfo.h"
#import "EthCore/BTCCurvePoint.h"
#import "EthCore/BTCData.h"
#import "EthCore/BTCErrors.h"
#import "EthCore/BTCHashID.h"
#import "EthCore/BTCKey.h"
#import "EthCore/BTCKeychain.h"
#import "EthCore/BTCMnemonic.h"
#import "EthCore/BTCNetwork.h"
#import "EthCore/BTCOpcode.h"
#import "EthCore/BTCOutpoint.h"
#import "EthCore/BTCProtocolBuffers.h"
#import "EthCore/BTCProtocolSerialization.h"
#import "EthCore/BTCScript.h"
#import "EthCore/BTCScriptMachine.h"
#import "EthCore/BTCSignatureHashType.h"
#import "EthCore/BTCTransaction.h"
#import "EthCore/BTCTransactionBuilder.h"
#import "EthCore/BTCTransactionInput.h"
#import "EthCore/BTCTransactionOutput.h"
#import "EthCore/BTCUnitsAndLimits.h"
#import "EthCore/CoreBitcoin+Categories.h"
#import "EthCore/EthCore.h"
#import "EthCore/NS+BTCBase58.h"
#import "EthCore/NSData+BTCData.h"
#import "EthCore/SwiftBridgingHeader.h"
#import "openssl/include/openssl/aes.h"
#import "openssl/include/openssl/asn1.h"
#import "openssl/include/openssl/asn1err.h"
#import "openssl/include/openssl/asn1t.h"
#import "openssl/include/openssl/async.h"
#import "openssl/include/openssl/asyncerr.h"
#import "openssl/include/openssl/bio.h"
#import "openssl/include/openssl/bioerr.h"
#import "openssl/include/openssl/bn.h"
#import "openssl/include/openssl/bnerr.h"
#import "openssl/include/openssl/buffer.h"
#import "openssl/include/openssl/buffererr.h"
#import "openssl/include/openssl/camellia.h"
#import "openssl/include/openssl/cast.h"
#import "openssl/include/openssl/cmac.h"
#import "openssl/include/openssl/cms.h"
#import "openssl/include/openssl/cmserr.h"
#import "openssl/include/openssl/comp.h"
#import "openssl/include/openssl/comperr.h"
#import "openssl/include/openssl/conf.h"
#import "openssl/include/openssl/conferr.h"
#import "openssl/include/openssl/conf_api.h"
#import "openssl/include/openssl/crypto.h"
#import "openssl/include/openssl/cryptoerr.h"
#import "openssl/include/openssl/ct.h"
#import "openssl/include/openssl/cterr.h"
#import "openssl/include/openssl/des.h"
#import "openssl/include/openssl/des_old.h"
#import "openssl/include/openssl/dh.h"
#import "openssl/include/openssl/dherr.h"
#import "openssl/include/openssl/dsa.h"
#import "openssl/include/openssl/dsaerr.h"
#import "openssl/include/openssl/ebcdic.h"
#import "openssl/include/openssl/ec.h"
#import "openssl/include/openssl/ecdh.h"
#import "openssl/include/openssl/ecdsa.h"
#import "openssl/include/openssl/ecerr.h"
#import "openssl/include/openssl/engine.h"
#import "openssl/include/openssl/engineerr.h"
#import "openssl/include/openssl/err.h"
#import "openssl/include/openssl/evp.h"
#import "openssl/include/openssl/evperr.h"
#import "openssl/include/openssl/e_os2.h"
#import "openssl/include/openssl/hmac.h"
#import "openssl/include/openssl/kdf.h"
#import "openssl/include/openssl/kdferr.h"
#import "openssl/include/openssl/lhash.h"
#import "openssl/include/openssl/md5.h"
#import "openssl/include/openssl/modes.h"
#import "openssl/include/openssl/objects.h"
#import "openssl/include/openssl/objectserr.h"
#import "openssl/include/openssl/obj_mac.h"
#import "openssl/include/openssl/ocsp.h"
#import "openssl/include/openssl/ocsperr.h"
#import "openssl/include/openssl/opensslconf.h"
#import "openssl/include/openssl/opensslv.h"
#import "openssl/include/openssl/ossl_typ.h"
#import "openssl/include/openssl/pem.h"
#import "openssl/include/openssl/pem2.h"
#import "openssl/include/openssl/pemerr.h"
#import "openssl/include/openssl/pkcs12.h"
#import "openssl/include/openssl/pkcs12err.h"
#import "openssl/include/openssl/pkcs7.h"
#import "openssl/include/openssl/pkcs7err.h"
#import "openssl/include/openssl/pqueue.h"
#import "openssl/include/openssl/rand.h"
#import "openssl/include/openssl/randerr.h"
#import "openssl/include/openssl/rand_drbg.h"
#import "openssl/include/openssl/rc4.h"
#import "openssl/include/openssl/ripemd.h"
#import "openssl/include/openssl/rsa.h"
#import "openssl/include/openssl/rsaerr.h"
#import "openssl/include/openssl/safestack.h"
#import "openssl/include/openssl/seed.h"
#import "openssl/include/openssl/sha.h"
#import "openssl/include/openssl/stack.h"
#import "openssl/include/openssl/store.h"
#import "openssl/include/openssl/storeerr.h"
#import "openssl/include/openssl/symhacks.h"
#import "openssl/include/openssl/tls1.h"
#import "openssl/include/openssl/tserr.h"
#import "openssl/include/openssl/ui.h"
#import "openssl/include/openssl/uierr.h"
#import "openssl/include/openssl/x509.h"
#import "openssl/include/openssl/x509err.h"
#import "openssl/include/openssl/x509v3.h"
#import "openssl/include/openssl/x509v3err.h"
#import "openssl/include/openssl/x509_vfy.h"

FOUNDATION_EXPORT double EthCoreVersionNumber;
FOUNDATION_EXPORT const unsigned char EthCoreVersionString[];
