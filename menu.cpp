void printmenu(){
  cout<<"0. First menu"<<endl
  <<"1. Singup"<<endl
  <<"2. Play with a character"<<endl
  <<"3. Play with simulator"<<endl
  <<"4. Highscore"<<endl
  <<"5. Settings"<<endl
  <<"Enter menu code: ";
}

void resetSettings() {
  GameCompetition::setwin(3);
  GameCompetition::setover(-1);
  GameCompetition::setdraw(2);
  GameCompetition::setroundprediction((rand()%4)+5);
}
