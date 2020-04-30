#ifndef GAMEPREDICTION_H
#define GAMEPREDICTION_H
class GamePrediction : public GameCompetition {
public:
  vector<Character> chars ;
  int charCount[8] ;
  int preRound ;
  int del ;
  int guess ;
  GamePrediction(int pr , int de , int gue , int chc[]) {
    preRound = pr ;
    del = de ;
    guess = gue ;
    charCount = chc ;
    for (int i = 0 ; i<8 ; i++) {
      for (int j = 0 ; j < charCount[i] ; j++) {
        chars.push_back(CharacterData(i)) ;
      }
    }
  }
  static void startPreGame() {
    int pr , int de , int gue ;
    int chc[8] ;
    /*
    cout << "Masoom : " ;
    cin >> chc[0] ;
    cout << "Moqaled : " ;
    cin >> chc[1] ;
    cout << "Moqaled mehraboon : " ;
    cin >> chc[2] ;
    cout << "Kinei : " ;
    cin >> chc[3] ;
    cout << "Kargah : " ;
    cin >> chc[4] ;
    cout << "Shansi : " ;
    cin >> chc[5] ;
    cout << "Sade : " ;
    cin >> chc[6] ;
    cout << "Moteqaleb : " ;
    cin >> chc[7] ;
    */
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
    GamePrediction(pr , de , gue , chc) ;
  }
  void move(int cnt) {
    for (int i = 0 ; i<cnt ; i++) {
      for (int j = 0 ; j<chars.size() ; j++) {
        for (int r = j+1 ;r<chars.size() ; r++) {
          bazi(chars[j],chars[r]) ; //// temp , code dar kelas madar neveshte mishavad ///
        }
      }
    }
  }
  // bayad design shavad , ebtedaei
  void print() {
    
  }
  void preGame(){
    int command = 0 ; // 0 or Wrong-One Step //1-Until End
    int randeFeli = 0 ;
    print() ;
    while (randeFeli < preRound) {
      cout << "What is your command : " ;
      cin >> command ;
      if (command == 1) {
        move(preRound - randeFeli) ;
        randeFeli = preRound  ;
        print();
      } else {
        move(1) ;
        randeFeli++ ;
        print();
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
    cout "Winner : " << Character::character[maxi].name << endl ;
    cout << "Your Guess : " << Character::character[guess].name << " ";
    if (guess == maxi) {
      cout << "Correct" << endl ;
    } else {
      cout << "Wrong" << endl ;
    }
  }
};

#endif //GAMEPREDICTION_H
