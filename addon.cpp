#include <node.h>
#include <v8.h>

void Add(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    double a = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    double b = args[1]->NumberValue(isolate->GetCurrentContext()).FromJust();

    args.GetReturnValue().Set(v8::Number::New(isolate, a + b));
}

void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)