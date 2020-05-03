#ifndef GAMECOMPETITION_H
#define GAMECOMPETITION_H

class GameCompetition
{
  friend class GamePrediction;
public:
  std::vector<bool> action_history;
  GameCompetition(User , Character ,int  );
  GameCompetition();
  void setround(int);
  int getround();
  void game();
  void print();
  void settester(User u);
  void setbot(Character c);
  Character getbot();
  bool action();
  void bazi(Character &, Character &);

private:
  int round;
  User tester;
  Character bot;
  int bot_id;

};
#endif
