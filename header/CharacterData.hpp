#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP
class CharacterData{
    const int id;
    const string name;
    bool cheated;
    public:
    CharacterData(const int id,const string& name){
        this -> name = name;
        this -> id = id;
        cheated = false;
    }
    int idreturn() const {
        return id;
    }
    string namereturn() const {
        return name;
    }
    //bool game()
    ~CharacterData(){}
};

#endif