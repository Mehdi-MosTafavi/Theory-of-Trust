#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "User.cpp"
#include "Character.cpp"
#include "GameCompetition.cpp"
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
  cout<<"Your name: ";
  cin>>name;
  cout<<"Your family: ";
  cin>>family;
  cout<<"Your Phone: ";
  cin>>phone;
  if(isstring(name) && isstring(family) && isNumber(phone))
  {
    tester.push_back(User(name,family,phone));
    cout<<"Registriation successful"<<endl;
  }
  else
    cout<<"Register failed"<<endl;
}
void GameCompetition_funcinit(){
  string phone;
  cout<<"Your Phone: ";
  cin>>phone;
  bool game=true;
  User tester_online;
  if(isNumber(phone))
  {
    for(int i=0;i<tester.size();i++)
    {
      if(tester[i].getphone()==phone)
        tester_online=tester[i];
    }
  }
  else
    game=false;
  int j=rand()%8;
  if(game)
  for(int i=0;i<Character::character.size();i++)
  {
    if(Character::character[i].idreturn()==j)
    {
      GameCompetition game_face=GameCompetition(tester_online,Character::character[i],j);
      game_face.game();
      break;
    }
  }
  else
    cout<<"not found";
  return;
}
void printmenu(){
  cout<<"Enter menu:"<<endl
  <<"0. First menu"<<endl
  <<"1. Singup"<<endl
  <<"2. Play with a character"<<endl
  <<"3. Play with simulator"<<endl
  <<"4. Highscores"<<endl
  <<"5. Settings"<<endl
  <<"Enter menu code: ";
}
void GameCompetition_func(){

}
int main()
{
  //Initializing Characters
  Character::character.emplace_back(0,"Masoom");
  Character::character.emplace_back(1,"Moqaled");
  Character::character.emplace_back(2,"Moqaled Mehraboon");
  Character::character.emplace_back(3,"Kine ei");
  Character::character.emplace_back(4,"Kargah");
  Character::character.emplace_back(5,"Shansi");
  Character::character.emplace_back(6,"Sade");
  Character::character.emplace_back(7,"Moteqaleb");

  int menu = 0;
  while(cin>>menu){
  switch(menu){
    case 0: printmenu(); cin>>menu; break;
    case 1: cout<<"Register: "<<endl; signup(); break;
    case 2: cout<<"Play with a character: "<<endl; GameCompetition_funcinit(); break;
    case 3: cout<<"Play with simulator: "<<endl; break;
    case 4: cout<<"Highscores: "<<endl; break;
    case 5: cout<<"Settings: "<<endl; int menu2; cin>>menu2; 
      cout<<"0. First menu"<<endl<<"1. Delete scores"<<endl;
      switch(menu2){
        case 0: menu = 0; break;
        case 1:  break;
      }
    break;
    default: cout<<"ERROR!"<<endl; break;
  }
  }

  return 0;
}