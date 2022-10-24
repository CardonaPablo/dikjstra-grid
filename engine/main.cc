#include "napi.h"
#include "main.h"

using namespace Napi;

Value exportFunction(const CallbackInfo& info) {

	Env env = info.Env();
	if (info.Length() < 4) {
		TypeError::New(env, "Wrong number of arguments")
			.ThrowAsJavaScriptException();
		return env.Null();
	}

	Array barriers_ = info[1].As<Array>();
	int length = barriers_.Length();
	vector<int> barriers(length);
	for (int i = 0; i < length; i++)
	{
		Value v = barriers_[i];
		int val = (int)v.As<Number>();
		cout << "Inserting value" << val <<endl;
		barriers[i] = val;
	}

	int dimension = info[0].As<Number>();
	int initial = info[2].As<Number>();
	int final = info[3].As<Number>();

	string result = createPath(dimension, barriers, initial, final);
	cout << "Result: " << result << endl;

	return String::New(env, result);
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "createPath"), Function::New(env, exportFunction));
  return exports;
}

NODE_API_MODULE(addon, Init)