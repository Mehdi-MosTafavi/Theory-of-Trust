#include "header/GamePrediction.hpp"

GamePrediction::GamePrediction(int pr , int de , int gue , int chc[]) {
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
GamePrediction GamePrediction::startPreGame() {
  int pr , de , gue ;
  int chc[8] ;
  for (int i = 0 ; i < 8 ; i++) {
    cout << Character::character[i].namereturn() << " : " ; ///////////// niazmand Edit , Temp ////////////////
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
void GamePrediction::charHandle(int ted) {
  for (int i = 0 ; i<chars.size() ; i++) {
    for (int j = i+1 ; j<chars.size() ; j++) {
      if (chars[i].pointreturn()>chars[j].pointreturn()) {
        Character c = chars[i] ; // (jens) notSure
        chars[i] = chars[j] ;
        chars[j] = c ;
      }
    }
  }
  int size = chars.size();
  for (int i = size - ted ; i<size ; i++) {
    chars.push_back(Character(chars[i].idreturn())) ;
    charCount[chars[i].idreturn()] += 1 ;
  }
  for (int i = 0 ; i<ted ; i++) {
    charCount[chars[i].idreturn()] -= 1 ;
    chars.erase(chars.begin() + i) ;
  }
}
void GamePrediction::move(int cnt) {
  for (int i = 0 ; i<cnt ; i++) {
    for (int j = 0 ; j<chars.size() ; j++) {
      for (int r = j+1 ;r<chars.size() ; r++) {
      GameCompetition::bazi(chars[j],chars[r]);
      }
    }
    charHandle(del) ;
  }
}
void GamePrediction::print(int rn) {
  if (rn == 0){
    cout << "Vaziate ebtedaei" << endl;
  } else {
    cout <<  "Rande " ;
    if (rn == preRound) {
      cout << rn << endl;
    } else {
      cout << rn << endl;
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
    if (charCount[i]==lastCharCount[i]) {
        cout << Character::character[i].namereturn() << " : " << charCount[i];
    } else if (charCount[i]>lastCharCount[i]) {
        cout << Character::character[i].namereturn() << " : " << charCount[i] ;
    } else if (charCount[i]<lastCharCount[i]) {
        cout << Character::character[i].namereturn() << " : " << charCount[i] ;
    }
  }
  cout << endl ;
  for (int i = 0 ; i<8 ; i++) {
    lastCharCount[i]=charCount[i];
  }
}
void GamePrediction::preGame(){
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
  cout << "The game has been finished !" << endl;
  cout << "Winner : " ;
  cout << Character::character[maxi].namereturn()  << endl;
  cout << "Your Guess : " ;
  if (guess == maxi) {
    cout << Character::character[guess].namereturn() << endl;
  } else {
    cout << Character::character[guess].namereturn() << endl;
  }
}
