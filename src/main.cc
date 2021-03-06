#include <node.h>
#include <openssl/obj_mac.h>

#include "eckey.h"

using namespace v8;

void InitCurves(Handle<Object> exports) {
	Local<Object> obj = Object::New();
	obj->Set(String::NewSymbol("secp112r1"), Number::New(NID_secp112r1));
	obj->Set(String::NewSymbol("secp112r2"), Number::New(NID_secp112r2));
	obj->Set(String::NewSymbol("secp128r1"), Number::New(NID_secp128r1));
	obj->Set(String::NewSymbol("secp128r2"), Number::New(NID_secp128r2));
	obj->Set(String::NewSymbol("secp160k1"), Number::New(NID_secp160k1));
	obj->Set(String::NewSymbol("secp160r1"), Number::New(NID_secp160r1));
	obj->Set(String::NewSymbol("secp160r2"), Number::New(NID_secp160r2));
	obj->Set(String::NewSymbol("secp192r1"), Number::New(NID_X9_62_prime192v1));
	obj->Set(String::NewSymbol("secp192k1"), Number::New(NID_secp192k1));
	obj->Set(String::NewSymbol("secp224k1"), Number::New(NID_secp224k1));
	obj->Set(String::NewSymbol("secp224r1"), Number::New(NID_secp224r1));
	obj->Set(String::NewSymbol("secp256r1"), Number::New(NID_X9_62_prime256v1));
	obj->Set(String::NewSymbol("secp256k1"), Number::New(NID_secp256k1));
	obj->Set(String::NewSymbol("secp384r1"), Number::New(NID_secp384r1));
	obj->Set(String::NewSymbol("secp521r1"), Number::New(NID_secp521r1));
	obj->Set(String::NewSymbol("sect113r1"), Number::New(NID_sect113r1));
	obj->Set(String::NewSymbol("sect113r2"), Number::New(NID_sect113r2));
	obj->Set(String::NewSymbol("sect131r1"), Number::New(NID_sect131r1));
	obj->Set(String::NewSymbol("sect131r2"), Number::New(NID_sect131r2));
	obj->Set(String::NewSymbol("sect163k1"), Number::New(NID_sect163k1));
	obj->Set(String::NewSymbol("sect163r1"), Number::New(NID_sect163r1));
	obj->Set(String::NewSymbol("sect163r2"), Number::New(NID_sect163r2));
	obj->Set(String::NewSymbol("sect193r1"), Number::New(NID_sect193r1));
	obj->Set(String::NewSymbol("sect193r2"), Number::New(NID_sect193r2));
	obj->Set(String::NewSymbol("sect233k1"), Number::New(NID_sect233k1));
	obj->Set(String::NewSymbol("sect233r1"), Number::New(NID_sect233r1));
	obj->Set(String::NewSymbol("sect239k1"), Number::New(NID_sect239k1));
	obj->Set(String::NewSymbol("sect283k1"), Number::New(NID_sect283k1));
	obj->Set(String::NewSymbol("sect283r1"), Number::New(NID_sect283r1));
	obj->Set(String::NewSymbol("sect409k1"), Number::New(NID_sect409k1));
	obj->Set(String::NewSymbol("sect409r1"), Number::New(NID_sect409r1));
	obj->Set(String::NewSymbol("sect571k1"), Number::New(NID_sect571k1));
	obj->Set(String::NewSymbol("sect571r1"), Number::New(NID_sect571r1));

	// Intimidated? Can't go wrong with NIST recommended curves

	obj->Set(String::NewSymbol("nistp192"), Number::New(NID_X9_62_prime192v1));
	obj->Set(String::NewSymbol("nistp224"), Number::New(NID_secp224r1));
	obj->Set(String::NewSymbol("nistp256"), Number::New(NID_X9_62_prime256v1));
	obj->Set(String::NewSymbol("nistp384"), Number::New(NID_secp384r1));
	obj->Set(String::NewSymbol("nistp521"), Number::New(NID_secp521r1));

	exports->Set(String::NewSymbol("ECCurves"), obj);
}

void InitModule(Handle<Object> exports) {
	ECKey::Init(exports);
	InitCurves(exports);
}

NODE_MODULE(native, InitModule)
