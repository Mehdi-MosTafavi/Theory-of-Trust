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
std::vector<User> tester;
bool isNumber(string s)//check inputed string is number or else
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)   //function isdigit is char is number or else
            return false;

    return true;
}
bool isstring(string s)//check inputed string is number or else
{
    for (int i = 0; i < s.length(); i++)
        if (isalpha(s[i]) == false || isdigit(s[i]))
            return false;

    return true;
}

void file_write(User a)
{
  ofstream f1("file/user.dat",ios::binary | ios::app);
  if(!f1)
    exit(0);
  f1.write(reinterpret_cast<const char*>(&a),sizeof(User));
  f1.close();
}
void file_init()
{
  ifstream f1("file/user.dat",ios::binary | ios::in);
  if(!f1)
  {
    exit(0);
  }
    User a;
    while(f1 && !f1.eof())
    {

      f1.read(reinterpret_cast<char*>(&a),sizeof(User));
  // tester.push_back(User(a.getname(),a.getfamily(),a.getphone()));
  tester.push_back(a);
}
  f1.close();
  return;

}

void User::signup()
{
  string name,family,phone;
  cout<<"Your name: ";
  cin>>name;
  cout<<"Your family: ";
  cin>>family;
  cout<<"Your Phone: ";
  cin>>phone;
  if(isstring(name) && isstring(family) && isNumber(phone))
  {
    tester.push_back(User(name,family,phone));
    file_write(tester[tester.size()-1]);
    cout<<"Registriation successful"<<endl;
  }
  else
    cout<<"Register failed"<<endl;
}
