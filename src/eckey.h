#ifndef ECC_ECKEY_H
#define ECC_ECKEY_H
#include <node.h>
#include <openssl/ec.h>

using namespace v8;
using namespace node;

class ECKey : public ObjectWrap {
	public:
		static void Init(Handle<Object> exports);

	private:
		ECKey(int curve);
		~ECKey();

		const char *mLastError;
		int mCurve;
		EC_KEY *mKey;
		bool mHasPrivateKey;

		// Node constructor
		static Handle<Value> New(const Arguments &args);

		// Node properties
		static Handle<Value> GetLastError(Local<String> property, const AccessorInfo &info);
		static Handle<Value> GetHasPrivateKey(Local<String> property, const AccessorInfo &info);
		static Handle<Value> GetPublicKey(Local<String> property, const AccessorInfo &info);
		static Handle<Value> GetPrivateKey(Local<String> property, const AccessorInfo &info);

		// Node methods
		static Handle<Value> Sign(const Arguments &args); // sign(digest)
		static Handle<Value> VerifySignature(const Arguments &args); // verifySignature(digest, signature)
		static Handle<Value> DeriveSharedSecret(const Arguments &args); // deriveSharedSecret(ECKey other)
};


#endif