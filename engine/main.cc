#include "napi.h"
#include "main.h"

// namespace AddOn
// {


// 	// This is the implementation of the "add" method
// 	// Input arguments are passed using the
// 	// const FunctionCallbackInfo<Value>& args struct
// 	void exportFunction(const FunctionCallbackInfo<Value> &args)
// 	{

// 		Isolate *isolate = args.GetIsolate();
// 		// Check the number of arguments passed.
// 		if (args.Length() != 3)
// 		{
// 			// Throw an Error that is passed back to JavaScript
// 			isolate->ThrowException(Exception::TypeError(
// 				String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
// 			return;
// 		}

// 		Local<Array> barriers_ = Local<Array>::Cast(args[0]);
// 		int length = barriers_->Length();

// 		Local<Object> barriers__ = Local<Object>::Cast(barriers_);
// 		int barriers[length];
// 		for (int i = 0; i < length; i++)
// 		{
// 			Local<Value> element = Local<Object>::Get::barriers__(i);
// 			barriers[i] = element.ToInteger()->Value();
// 		}

// 		int dimension = args[0].As<Number>()->Value();
// 		createPath(dimension, barriers);

// 		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "1,2,5,6,9").ToLocalChecked());
// 	}

// 	void Init(Local<Object> exports)
// 	{
// 		NODE_SET_METHOD(exports, "createPath", exportFunction);
// 	}

// 	NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

// }

using namespace Napi;

Value exportFunction(const CallbackInfo& args) {

  Env env = args.Env();
  if (args.Length() < 2) {
    TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

	Array barriers_ = args[1].As<Array>();
	int length = barriers_.Length();
	int barriers[length];
	for (int i = 0; i < length; i++)
	{
		Value v = barriers_[i];
		barriers[i] = (int)v.As<Number>();
	}

	int dimension = args[0].As<Number>();
	createPath(dimension, barriers);

	// String result = String::NewFromUtf8(isolate, "1,2,5,6,9");
	return String::New(env, "1,2,5,6,9");
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "createPath"), Function::New(env, exportFunction));
  return exports;
}

NODE_API_MODULE(addon, Init)