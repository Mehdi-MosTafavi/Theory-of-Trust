#include "header/User.hpp"
User::User(string n,string f,string p)
{
  setname(n);
  setfamily(f);
  setphone(p);
  setpoint(0);
}
void User::setname(string n)
{
  name=n;
}
void User::setfamily(string f)
{
  family=f;
}
void User::setphone(string p)
{
  phonenumber=p;
}
void User::setpoint(int p)
{
  point=p;
}
string User::getname()
{
  return name;
}
string User::getfamily()
{
  return family;
}
string User::getphone()
{
  return phonenumber;
}
int User::getpoint()
{
  return point;
}
