#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "header/Character.hpp"
#include "header/CharacterData.hpp"

Character::Character(const int id,const string& name): ptr(new CharacterData(id,name)){
cout<<"done";
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
    return ptr -> cheatedset(b);
}
bool
Character::cheatedreturn(){
    return ptr -> cheatedreturn();
}
bool
Character::game(const int id,Character& character,const bool *action,const int size){
    switch (id)
    {
        //Masoom
    case 1:
        return true;
        break;
        //Moqaled
    case 2: 
        return action[size-2];
    break;
        //Moqaled mehraboon
    case 3:
        if(!action[size-2] && !action[size-3]){
            return false;
        }else{
            return true;
        }
    break;
    //Kinei
    case 4:
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
    case 5:
        switch(size){
            case 1: case 3: case 4:
                return true;
            break;
            case 2:
                return false;
            break; 
            default:
                
            break;
        }
    break;
    //Shansi
    case 6:
        srand(time(NULL));
        if(rand()%2 == 0){
            return true;
        }else{
            return false;
        }
    break;
    //Sade
    case 7:
        if(size < 2){
            return true;
        }else{
            if(action[size-2] == false){
                character.cheatedset(true);
            }else{

            }
        }
    break;
    //Moteqaleb
    case 8:
        return false;
    break;
    default:
        cout<<"ERROR";
        break;
    }

}
vector<Character> Character::character;
int main(){
    return 0;
}