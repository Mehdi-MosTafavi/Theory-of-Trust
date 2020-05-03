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
    case 1: cout<<"Register: "<<endl; User::signup(); break;
    case 2: cout<<"Play with a character: "<<endl; GameCompetition::GameCompetition_funcinit(); break;
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
