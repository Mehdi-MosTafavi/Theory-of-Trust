#ifndef GAMEPREDICTION_H
#define GAMEPREDICTION_H
// libs and namespaces
/*
#include <iostream>
#include <vector>
using namespace std ;
*/
//help Mehdi
/*
class Character{
public:
  int id ;
  string name ;
  int point ;
  friend class GameCompetition ;
  static vector <Character> character ;
  Character(int i , string n) {
    id = i ;
    name = n ;
    point = 0 ;
  }
  Character(int i) {
    id = i ;
    name = Character::character[i].name ;
    point = 0 ;
  }
};
vector <Character> Character::character ;
void Character_init(){
  Character::character.push_back(Character(1,"Masoom")) ;
  Character::character.push_back(Character(2,"Moqaled")) ;
  Character::character.push_back(Character(3,"Moqaled mehraboon")) ;
  Character::character.push_back(Character(4,"kinei")) ;
  Character::character.push_back(Character(5,"Kargah")) ;
  Character::character.push_back(Character(6,"Shansi")) ;
  Character::character.push_back(Character(7,"Sade")) ;
  Character::character.push_back(Character(8,"Moteqaleb")) ;
}
*/
// help Hosein
/*
class GameCompetition{
  friend class GamePrediction ;
  static void bazi(Character& a , Character& b) {
    a.point +=  yek adad ;
    b.point +=  yek adad  ;
  }
};
*/
// My Main
/*
int main() {
  Character_init();
  GamePrediction gp = GamePrediction::startPreGame();
  gp.preGame() ;
  return 0 ;
}
*/

class GamePrediction{
public:
  vector<Character> chars ;
  int lastCharCount[8] ;
  int charCount[8] ;
  int preRound ;
  int del ;
  int guess ;
  GamePrediction(int pr , int de , int gue , int chc[]) {
    preRound = pr ;
    del = de ;
    guess = gue ;
    for (int i = 0 ; i<8 ; i++) {
      charCount[i]=chc[i] ;
      lastCharCount[i]=charCount[i];
    }
    for (int i = 0 ; i<8 ; i++) {
      for (int j = 0 ; j < charCount[i] ; j++) {
        chars.push_back(Character(i)) ; /// niazmande edit (jens)
      }
    }
  }
  static GamePrediction startPreGame() {
    int pr , de , gue ;
    int chc[8] ;
    for (int i = 0 ; i < 8 ; i++) {
      cout << Character::character[i].name << " : " ; ///////////// niazmand Edit , Temp ////////////////
      cin >> chc[i] ;
    }
    cout << "RoundCount : " ;
    cin >> pr ;
    cout << "Delete Count : " ;
    cin >> de ;
    cout << "your guess Id : " ;
    cin >> gue ;
    GamePrediction gp = GamePrediction(pr , de , gue , chc) ;
    return gp ;
  }
  void charHandle(int ted) {
    for (int i = 0 ; i<chars.size() ; i++) {
      for (int j = i+1 ; j<chars.size() ; j++) {
        if (chars[i].point>chars[j].point) {
          Character c = chars[i] ; // (jens) notSure
          chars[i] = chars[j] ;
          chars[j] = c ;
        }
      }
    }
    int size = chars.size();
    for (int i = size - ted ; i<size ; i++) {
      chars.push_back(Character(chars[i].id)) ;
      charCount[chars[i].id -1] += 1 ;
    }
    for (int i = 0 ; i<ted ; i++) {
      charCount[chars[i].id -1] -= 1 ;
      chars.erase(chars.begin() + i) ;
    }
  }
  void move(int cnt) {
    for (int i = 0 ; i<cnt ; i++) {
      for (int j = 0 ; j<chars.size() ; j++) {
        for (int r = j+1 ;r<chars.size() ; r++) {
          GameCompetition::bazi(chars[j],chars[r]) ; //// temp , code dar kelas madar neveshte mishavad ///
        }
      }
      charHandle(del) ;
    }
  }
  // bayad design shavad , ebtedaei
  void print(int rn) {
    if (rn == 0){
      cout << "\033[36m" << "Vaziate ebtedaei" << "\033[0m" << endl;
    } else {
      cout << "\033[36m" << "Rande " << "\033[0m";
      if (rn == preRound) {
        cout << "\033[35m" << rn << "\033[0m" << endl;
      } else {
        cout << "\033[36m" << rn << "\033[0m" << endl;
      }
    }
    for (int i = 0 ; i<8 ; i++) {
      if (i==4) {
        cout << endl ;
      } else if (i==0) {
      } else if (i==3) {
        cout << "\t" ;
      } else {
        cout << "\t\t" ;
      }
      if (charCount[i]==lastCharCount[i]) { // name not sure again
        	cout << "\033[33m" << Character::character[i].name << " : " << charCount[i] << "\033[0m";
      } else if (charCount[i]>lastCharCount[i]) {
        	cout << "\033[32m" << Character::character[i].name << " : " << charCount[i] << "\033[0m";
      } else if (charCount[i]<lastCharCount[i]) {
        	cout << "\033[31m" << Character::character[i].name << " : " << charCount[i] << "\033[0m";
      }
    }
    cout << endl ;
    for (int i = 0 ; i<8 ; i++) {
      lastCharCount[i]=charCount[i];
    }
  }
  void preGame(){
    int command = 0 ; // 0 or Wrong-One Step //1-Until End
    int randeFeli = 0 ;
    print(0) ;
    while (randeFeli < preRound) {
      cout << "What is your command : " ;
      cin >> command ;
      if (command == 1) {
        move(preRound - randeFeli) ;
        randeFeli = preRound  ;
        print(preRound);
      } else {
        move(1) ;
        randeFeli++ ;
        print(randeFeli);
      }
    }
    int max = -1 ;
    int maxi;
    for (int i = 0 ; i<8 ; i++) {
      if (charCount[i] > max) {
        max = charCount[i] ;
        maxi = i ;
      }
    }
    cout << "\033[36m" << "The game has been finished !" << "\033[0m" << endl;
    cout << "Winner : " ;
    cout << "\033[32m" << Character::character[maxi].name << "\033[0m" << endl;
    cout << "Your Guess : " ;
    if (guess == maxi) {
      cout << "\033[32m" << Character::character[guess].name << "\033[0m" << endl;
    } else {
      cout << "\033[31m" << Character::character[guess].name << "\033[0m" << endl;
    }
  }
};

#endif //GAMEPREDICTION_H
