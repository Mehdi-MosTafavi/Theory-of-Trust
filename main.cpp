#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "User.cpp"
#include "Character.cpp"
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

void signup()
{
  string name,family,phone;
  cin>>name>>family>>phone;
  if(isstring(name) && isstring(family) && isNumber(phone))
  {
    tester.push_back(User(name,family,phone));
    cout<<"Registriation successful"<<endl;
  }
  else
    cout<<"Register failed"<<endl;
}
int main()
{
  //Initializing Characters
  Character::character.emplace_back(1,"Masoom");
  Character::character.emplace_back(2,"Moqaled");
  Character::character.emplace_back(3,"Moqaled Mehraboon");
  Character::character.emplace_back(4,"Kine ei");
  Character::character.emplace_back(5,"Kargah");
  Character::character.emplace_back(6,"Shansi");
  Character::character.emplace_back(7,"Sade");
  Character::character.emplace_back(8,"Moteqaleb");

  signup();
  return 0;
}
