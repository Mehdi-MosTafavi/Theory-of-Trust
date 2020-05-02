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
Character::game(const int id,Character& character,const bool *action,const int size){
    switch (id)
    {
        //Masoom
    case 0:
        return true;
        break;
        //Moqaled
    case 1:
        return action[size-2];
    break;
        //Moqaled mehraboon
    case 2:
        if(!action[size-2] && !action[size-3]){
            return false;
        }else{
            return true;
        }
    break;
    //Kinei
    case 3:
    if(character.cheatedreturn() == false){
        if(action[size-2] == false){
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
        switch(size){
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
                    return action[size-2];
                }
            }
            break;
        }
    break;
    //Shansi
    case 5:
        srand(time(NULL));
        if(rand()%2 == 0){
            return true;
        }else{
            return false;
        }
    break;
    //Sade
    case 6:
        if(size == 1){
            return true;
        }else{
            if(action[size-2]){
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
