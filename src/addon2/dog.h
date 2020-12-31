#pragma once

#include <napi.h>
#include <animal.h>

class Fight{
public:
  static float base;
  static float calc( int age ) {
    return base * age +1;
  }
};


class Dog : public Napi::ObjectWrap<Dog>,
  public IAni

{
 public:
  Dog(const Napi::CallbackInfo&);

  Napi::Value Age(const Napi::CallbackInfo&);
  Napi::Value FightVal(const Napi::CallbackInfo&);

  static Napi::Function GetClass(Napi::Env);

 private:
  std::string _greeterName;
};