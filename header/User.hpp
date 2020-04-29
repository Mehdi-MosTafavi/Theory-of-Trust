#ifndef USER_HPP
#define USER_HPP
class User
{
public:
  User(string, string , string);
  void setname(string);
  void setfamily(string);
  void setphone(string);
  void setpoint(int);
  string getname();
  string getfamily();
  string getphone();
  int getpoint();


private:
  string name;
  string family;
  string phonenumber;
  int point;

};
#endif
