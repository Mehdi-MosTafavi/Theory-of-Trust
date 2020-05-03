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
#include "menu.cpp"
int main()
{
  srand(time(0));
  printmenu();
  Character::CharacterInit();
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
      case 4:User::Highscore(); break;
      case 5: cout<<"Settings: "<<endl; int menu2;
        cout<<"0. First menu"<<endl<<"1. Delete scores"<<endl<<"2. Change point"<<endl<<"3. Change the round count of a single game"<<endl;
        cout << "4. reset Settings" << endl;
        cout << "command : " ;
        cin>>menu2;
        switch(menu2){
          case 0: menu = 0; printmenu(); break;
          case 1: User::file_clear(); break;
          case 2: GameCompetition::change_point();break;
          case 3: GameCompetition::change_round();break;
          case 4: resetSettings() ; cout << "Settings have been reset"<<endl ; break ;
          default:
            cout<<"ERROR!"<<endl;break;
        }
      break;
      default: cout<<"ERROR!"<<endl; break;
    }
    printmenu();
  }

  return 0;
}
