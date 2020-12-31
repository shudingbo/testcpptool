#include "dog.h"

using namespace Napi;

float Fight::base = 1.7;

Dog::Dog(const Napi::CallbackInfo& info)
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

Napi::Value Dog::Age(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, this->m_iAge);
}

Napi::Value Dog::FightVal(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  float fightV = Fight::calc( this->m_iAge );

  return Napi::Number::New(env, fightV);
}




Napi::Function Dog::GetClass(Napi::Env env) {
  return DefineClass(
      env,
      "Dog",
      {
        Dog::InstanceMethod("age", &Dog::Age),
        Dog::InstanceMethod("fightval", &Dog::FightVal),
      });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::String name = Napi::String::New(env, "Dog");
  exports.Set(name, Dog::GetClass(env));
  return exports;
}

NODE_API_MODULE(addon, Init)