#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class CharacterData;
class Character{
    CharacterData* ptr;

public:
    static vector<Character> character;
    Character(const int,const string&);
    int idreturn();
    string namereturn();
    static bool game(const int,const bool,const bool);
    ~Character();
};
#endif