#include <napi.h>

// add
Napi::Number Add(const Napi::CallbackInfo& info) {
  double a = info[0].As<Napi::Number>();
  double b = info[1].As<Napi::Number>();
  return Napi::Number::New(info.Env(), a + b);
}

// subtract
Napi::Number Sub(const Napi::CallbackInfo& info) {
  double a = info[0].As<Napi::Number>();
  double b = info[1].As<Napi::Number>();
  return Napi::Number::New(info.Env(), a - b);
}

// multiply
Napi::Number Mul(const Napi::CallbackInfo& info) {
  double a = info[0].As<Napi::Number>();
  double b = info[1].As<Napi::Number>();
  return Napi::Number::New(info.Env(), a * b);
}

// divide
Napi::Number Div(const Napi::CallbackInfo& info) {
  double a = info[0].As<Napi::Number>();
  double b = info[1].As<Napi::Number>();

  if (b == 0) {
    Napi::TypeError::New(info.Env(), "Division by zero")
      .ThrowAsJavaScriptException();
    return Napi::Number::New(info.Env(), 0);
  }

  return Napi::Number::New(info.Env(), a / b);
}

// init
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("add", Napi::Function::New(env, Add));
  exports.Set("sub", Napi::Function::New(env, Sub));
  exports.Set("mul", Napi::Function::New(env, Mul));
  exports.Set("div", Napi::Function::New(env, Div));
  return exports;
}

NODE_API_MODULE(calculator, Init)