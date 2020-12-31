#include <napi.h>
#include <string>
using namespace std;


class IAni
{
protected:
  string m_szName;
  int m_iAge;
  int m_iType;

public:

  void init( string name, int age, int type ) {
    m_szName = name;
    m_iAge = age;
    m_iType = type;
  }

  virtual const char *name() {
    return m_szName.c_str();
  } 

  virtual int age() {
    return m_iAge;
  }

  virtual int type(){
    return m_iType;
  }

};