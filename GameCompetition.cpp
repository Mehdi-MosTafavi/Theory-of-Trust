
#include "header/GameCompetition.hpp"
GameCompetition::GameCompetition()
{
  setround(10);
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
this->print();
}

void GamePrediction::bazi(Character &a,Character &b)
{
  std::vector<bool> a_history;
  std::vector<bool> b_history;
  int a_point=0,b_point=0;
  for(int i=0;i<round;i++)
  {

  bool a_action,b_action;
  a_action=a.game(a.idreturn(),a,b_history);
  b_action=b.game(b.idreturn(),b,a_history);
  a_history.push_back(a_action);
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




  a.setpoint(a_point);
  b.setpoint(b_point);
}
void GameCompetition::print()
{
  cout<<"\033[31m"<<"You played with "<<bot.namereturn()<<"'s character"<<"\033[0m"<<endl;
  cout << "\033[36m" <<"Your point = "<<tester.getpoint()<<" Bot point = "<<bot.pointreturn()<< "\033[0m" <<endl;
}
