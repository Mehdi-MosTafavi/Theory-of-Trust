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
