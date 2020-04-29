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
    void cheatedset(const bool);
    bool cheatedreturn();
    static bool game(const int,Character&,const bool *,const int);
    ~Character();
};
#endif