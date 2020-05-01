#ifndef GAMEPREDICTION_H
#define GAMEPREDICTION_H

class GamePrediction{
public:
  vector<Character> chars ;
  int lastCharCount[8] ;
  int charCount[8] ;
  int preRound ;
  int del ;
  int guess ;
  GamePrediction(int pr , int de , int gue , int chc[]) ;
  static GamePrediction startPreGame();
  void charHandle(int ted) ;
  void move(int cnt) ;
  void print(int rn) ;
  void preGame();
};

#endif //GAMEPREDICTION_H


// libs and namespaces
/*
#include <iostream>
#include <vector>
using namespace std ;
*/


//help Mehdi
//////////////////////// ba tavajoh be line 38 va 39 file GamePrediction.cpp
//////////////////////// va niaz be anjame swap int va sting nemitavanand const tarif shavand
//////////////////////// leza barkhi taghirat dar file CharacterData Eemal shod , Barresi Shavad
//////////////////////// Hamchenin id ha be jaye 1 ta 8 be dalile ijad eshkal dar code predict be
//////////////////////// 0 ta 7 taghir yaft va tamame taghirate lazem niz Eemal shod
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
  Character::character.push_back(Character(0,"Masoom")) ;
  Character::character.push_back(Character(1,"Moqaled")) ;
  Character::character.push_back(Character(2,"Moqaled mehraboon")) ;
  Character::character.push_back(Character(3,"kinei")) ;
  Character::character.push_back(Character(4,"Kargah")) ;
  Character::character.push_back(Character(5,"Shansi")) ;
  Character::character.push_back(Character(6,"Sade")) ;
  Character::character.push_back(Character(7,"Moteqaleb")) ;
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
