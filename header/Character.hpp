#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class CharacterData;
class Character{
    CharacterData* character;

public:
    Character(const int,const string&);
    int idreturn();
    string namereturn();
    ~Character();
};
#endif