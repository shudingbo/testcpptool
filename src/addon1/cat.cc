#include "cat.h"

using namespace Napi;

float Fight::base = 1.1;

Cat::Cat(const Napi::CallbackInfo& info)
    : ObjectWrap(info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "You need to name yourself")
        .ThrowAsJavaScriptException();
    return;
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "You need to age is number")
        .ThrowAsJavaScriptException();
    return;
  }

  
  this->init( info[0].As<Napi::String>().Utf8Value(), 
    info[1].As<Napi::Number>().Uint32Value(), 
    0 
  );

}

Napi::Value Cat::Age(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, this->m_iAge);
}

Napi::Value Cat::FightVal(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  float fightV = Fight::calc( this->m_iAge );

  return Napi::Number::New(env, fightV);
}




Napi::Function Cat::GetClass(Napi::Env env) {
  return DefineClass(
      env,
      "Cat",
      {
        Cat::InstanceMethod("age", &Cat::Age),
        Cat::InstanceMethod("fightval", &Cat::FightVal),
      });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::String name = Napi::String::New(env, "Cat");
  exports.Set(name, Cat::GetClass(env));
  return exports;
}

NODE_API_MODULE(addon, Init)