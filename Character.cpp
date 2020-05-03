#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "header/Character.hpp"
#include "header/CharacterData.hpp"

//Constructor for playing with user
Character::Character(const int id,const string & name){
    ptr = new CharacterData(id,name);
}
//Playing without user
Character::Character(const int id){
    ptr = new CharacterData(id);
}
Character::~Character(){}

int
Character::idreturn(){
    return ptr -> idreturn();
}
string
Character::namereturn(){
    return ptr -> namereturn();
}
void
Character::cheatedset(const bool b = true){
    ptr -> cheatedset(b);
}
bool
Character::cheatedreturn(){
    return ptr -> cheatedreturn();
}
int
Character::pointreturn(){
    return ptr -> pointreturn();
}
void
Character::pointset(const int p){
    ptr -> pointset(p);
}
bool
Character::game(const int id,Character& character,const vector<bool>& action){
    switch (id)
    {
        //Masoom
    case 0:
        return true;
        break;
        //Moqaled
    case 1:
    if(action.size() == 1){
        return true;
    }
        return action[action.size()-2];
    break;
        //Moqaled mehraboon
    case 2:
        if(!action[action.size()-2] && !action[action.size()-3]){
            return false;
        }else{
            return true;
        }
    break;
    //Kinei
    case 3:
    if(character.cheatedreturn() == false){
        if(action[action.size()-2] == false){
            character.cheatedset();
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
    break;
    //Kargah
    case 4:
        switch(action.size()){
            case 1: case 3: case 4:
                return true;
            break;
            case 2:
                return false;
            break;
            default:
            if(character.cheatedreturn() == true){
                return false;
            }else{
                if(action[2]==true){
                    character.cheatedset();
                    return false;
                }else{
                    return action[action.size()-2];
                }
            }
            break;
        }
    break;
    //Shansi
    case 5:
        if(rand()%2 == 0){
            return true;
        }else{
            return false;
        }
    break;
    //Sade
    case 6:
        if(action.size() == 1){
            return true;
        }else{
            if(action[action.size()-2]){
                return !character.cheatedreturn();
            }else{
                character.cheatedset(!character.cheatedreturn());
                return !character.cheatedreturn();
            }
        }
    break;
    //Moteqaleb
    case 7:
        return false;
    break;
    default:
        cout<<"ERROR";
        break;
    }

}
vector<Character> Character::character;
void Character::CharacterInit() {
  Character::character.emplace_back(0,"Masoom");
  Character::character.emplace_back(1,"Moqaled");
  Character::character.emplace_back(2,"Moqaled Mehraboon");
  Character::character.emplace_back(3,"Kine ei");
  Character::character.emplace_back(4,"Kargah");
  Character::character.emplace_back(5,"Shansi");
  Character::character.emplace_back(6,"Sade");
  Character::character.emplace_back(7,"Moteqaleb");
}
