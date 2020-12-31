#pragma once

#include <napi.h>
#include <animal.h>
#include <fight.h>



class Cat : public Napi::ObjectWrap<Cat>,
  public IAni

{
 public:
  Cat(const Napi::CallbackInfo&);

  Napi::Value Age(const Napi::CallbackInfo&);
  Napi::Value FightVal(const Napi::CallbackInfo&);

  static Napi::Function GetClass(Napi::Env);

 private:
  std::string _greeterName;
};