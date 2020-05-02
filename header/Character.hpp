#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class CharacterData;
class Character{
    CharacterData* ptr;

public:
    static vector<Character> character;
    Character(const int,const string&);
    Character(const int);
    int idreturn();
    int pointreturn();
    string namereturn();
    void cheatedset(const bool);
    void pointset(const int);
    bool cheatedreturn();
    static bool game(const int,Character&,const vector<bool>&);
    ~Character();
};
#endif