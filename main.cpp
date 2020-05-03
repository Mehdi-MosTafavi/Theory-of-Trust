#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;
#include "User.cpp"
#include "Character.cpp"
#include "GameCompetition.cpp"
#include "GamePrediction.cpp"
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
    file_write(tester[tester.size()-1]);
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
  bool exist=false;
  User tester_online;
  if(isNumber(phone))
  {
    for(int i=0;i<tester.size();i++)
    {
      if(tester[i].getphone()==phone)
      {
        tester_online=tester[i];
        exist=true;
      }
    }
  }
  else
    game=false;
    if(!exist)
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
    cout<<"Some problem is exist"<<endl;
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
void Highscore()
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
  cout<<"HighScore is : " << max<<endl;
  else
    cout<<"Not exists"<<endl;
  return;
}
int main()
{
  srand(time(0));
  printmenu();
  // file_init();
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
    case 0: printmenu(); break;
    case 1: cout<<"Register: "<<endl; signup(); break;
    case 2: cout<<"Play with a character: "<<endl; GameCompetition_funcinit(); break;
    case 3: {
      cout<<"Playing with a simulator" <<endl;
      GamePrediction gp = GamePrediction::startPreGame();
      gp.preGame() ;
      break;
    }
    case 4:Highscore(); break;
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
