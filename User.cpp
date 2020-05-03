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
void User::file_clear()
{
  ofstream f1("file/Highscore.dat",ios::trunc);
  f1.close();
  cout << "Scores have been successfully deleted !!" << endl ;
}
void User::Highscore()
{
  ifstream f1("file/Highscore.dat");
  int a,max=0;
  bool ok=false;
  if(!f1)
    exit(0);
  while(f1>>a)
  {
    ok=true;
    if(a>max)
      max=a;
  }
  if(ok)
  cout<<"HighScore is " << max<<endl;
  else
    cout<<"Not exists"<<endl;
    if(ok)
    {
    cout<<"Enter Your PhoneNumber: ";
    string phone;
    cin>>phone;
    for(int i=0;i<tester.size();i++)
    {
      if((tester[i].getphone())==phone)
      {
        cout<<"Your point :"<<tester[i].getpoint()<<endl;
        break;
      }
    }
}
  return;
}
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
  ofstream f1("file/user.dat",ios::app);
  if(!f1)
    exit(0);
f1<<a.getname()<<' '<<a.getfamily()<<' '<<a.getphone()<<endl;
  f1.close();
}
void file_init()
{
  ifstream f1("file/user.dat",ios::in);
  if(!f1)
  {
    exit(0);
  }
    string name,family,phone;
    while(f1>>name>>family>>phone)
{

  tester.push_back(User(name,family,phone));
  // tester.push_back(a);
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
  bool exist=false;
  for(int i=0;i<tester.size();i++)
  {
    if(tester[i].getphone()==phone)
    {
      exist=true;
    }
  }

  if(isstring(name) && isstring(family) && isNumber(phone) && !exist)
  {
    tester.push_back(User(name,family,phone));
    file_write(tester[tester.size()-1]);
    cout<<"Registriation successful !!"<<endl;
  }
  else
    cout<<"Registration failed !!"<<endl;
}
void User::operator+(int a)
{
  this->point+=a;
}
