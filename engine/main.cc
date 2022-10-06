#include <node.h>

namespace AddOn {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

// This is the implementation of the "add" method
// Input arguments are passed using the
// const FunctionCallbackInfo<Value>& args struct
void createPath(const FunctionCallbackInfo<Value>& args) {

  Isolate* isolate = args.GetIsolate();
  // Check the number of arguments passed.
  if (args.Length() > 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
    return;
  }

  // // Check the argument types
  // if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
  //   isolate->ThrowException(Exception::TypeError(
  //       String::NewFromUtf8(isolate,
  //                           "Wrong arguments").ToLocalChecked()));
  //   return;
  // }

  // // Perform the operation
  // double value =
  //     args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
  // Local<Number> num = Number::New(isolate, value);

  // Set the return value (using the passed in
  // FunctionCallbackInfo<Value>&)
  // args.GetReturnValue().Set(String::NewFromUtf8("1,2,3,4,5,6"));
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "createPath", createPath);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}