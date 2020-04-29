#include <iostream>
#include <vector>
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
bool
Character::game(const int id,const bool action,const int lastaction = true){

}
vector<Character> Character::character;