#ifndef GAMEPREDICTION_H
#define GAMEPREDICTION_H
class GamePrediction : public GameCompetition {
public:
  vector<Character> chars ; ///// (jens)notSure
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
  void charHandle(int ted) {
    for (int i = 0 ; i<chars.size() ; i++) {
      for (int j = i+1 ; j<chars.size() ; j++) {
        if (chars[i].point()>chars[j].point()) {
          Character c = chars[i] ; // (jens) notSure
          chars[i] = chars[j] ;
          chars[j] = c ;
        }
      }
    }
    for (int i = chars.size() - ted ; i<chars.size() ; i++) {
      chars.push_back(Character(chars[i].id)) ;
      charCount[chars[i].id] += 1 ;
    }
    for (int i = 0 ; i<ted ; i++) {
      charCount[chars[i].id] -= 1 ;
      chars.erase(chars.begin() + i) ;
    }
  }
  void move(int cnt) {
    for (int i = 0 ; i<cnt ; i++) {
      for (int j = 0 ; j<chars.size() ; j++) {
        for (int r = j+1 ;r<chars.size() ; r++) {
          bazi(chars[j],chars[r]) ; //// temp , code dar kelas madar neveshte mishavad ///
        }
      }
      charHandle(del) ;
    }
  }
  // bayad design shavad , ebtedaei
  void print() {
    for (int i = 0 ; i<8 ; i++) {
      if (i==4) {
        cout << endl ;
      } else if (i==0) {
      } else {
        cout << "\t" ;
      }
      if (charCount[i]==lastCharCount[i]) { // name not sure again
        	cout << "\033[33m" << Character::character[i].name << " : " << charCount[i] << "\033[0m" << endl;
      } else if (charCount[i]>lastCharCount[i]) {
        	cout << "\033[32m" << Character::character[i].name << " : " << charCount[i] << "\033[0m" << endl;
      } else (charCount[i]<lastCharCount[i]) {
        	cout << "\033[31m" << Character::character[i].name << " : " << charCount[i] << "\033[0m" << endl;
      }
    }
    for (int i = 0 ; i<8 ; i++) {
      lastCharCount[i]=charCount[i];
    }
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
