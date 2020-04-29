#include "header/Character.hpp"
#include "header/CharacterData.hpp"

Character::Character(const int id,const string& name): character(new CharacterData(id,name)){

}
Character::~Character(){}

int
Character::idreturn(){
    return character -> idreturn();
}
string
Character::namereturn(){
    return character -> namereturn();
}