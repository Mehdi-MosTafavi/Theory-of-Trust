
#include "header/GameCompetition.hpp"
GameCompetition::GameCompetition()
{
  setround(8);
}
GameCompetition::GameCompetition(User u,Character c ,int i):tester(u),bot(c)
{
  // settester(u);
  // setbot(c);
  setround(rand()%4+5);
  bot_id=i;
}
void GameCompetition::setround(int r)
{
  round=r;
}

int GameCompetition::getround()
{
  return round;
}
Character GameCompetition::getbot()
{
  return bot;
}
bool GameCompetition::action()
{
  int a;
  cout<<"action? ";
  cin>>a;
  if(a==0)
    return false;
  else
    return true;

}
void GameCompetition::game()
{
  int tester_point=0,bot_point=0;
  action_history.push_back(true);
  for(int i=0;i<round;i++)
  {
    bool tester_action,bot_action;

    tester_action=this->action();
    action_history.push_back(tester_action);
    bot_action=bot.game(bot_id,bot,action_history);
    if(tester_action && bot_action)
    {
      tester_point+=2;
      bot_point+=2;
    }
    else if(tester_action && !bot_action)
    {
      tester_point-=1;
      bot_point+=3;
    }
    else if(!tester_action && bot_action)
    {
      tester_point+=3;
      bot_point-=1;
    }

  }
bot.pointset(bot_point);
tester.setpoint(tester_point);
this->file_write(tester_point);
this->print();
}

void GameCompetition::bazi(Character &a,Character &b)
{
  std::vector<bool> a_history;
  std::vector<bool> b_history;
  a_history.push_back(true);
  a_history.push_back(true);
  b_history.push_back(true);
  b_history.push_back(true);
  int a_point=0,b_point=0;
  for(int i=0;i<round_prediction;i++)
  {

  bool a_action,b_action;
  a_action=a.game(a.idreturn(),a,b_history);
  a_history.push_back(a_action);
  b_action=b.game(b.idreturn(),b,a_history);
  b_history.push_back(b_action);

  if(a_action && b_action)
  {
    a_point+=2;
    b_point+=2;
  }
  else if(a_action && !b_action)
  {
    a_point-=1;
    b_point+=3;
  }
  else if(!a_action && b_action)
  {
    a_point+=3;
    b_point-=1;
  }

}




  a.pointset(a_point);
  b.pointset(b_point);
}
void GameCompetition::print()
{
  cout<<"You played with "<<bot.namereturn()<<"'s character"<<endl;
  cout <<"Your point = "<<tester.getpoint()<<" Bot point = "<<bot.pointreturn()<<endl;
}
int GameCompetition::round_prediction=8;
void GameCompetition::file_write(int a)
{
  ofstream f1("file/Highscore.dat",ios::out | ios::app);
  f1<<a<<endl;
  f1.close();
}
