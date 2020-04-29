#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP
class CharacterData{
    int id;
    string name;
    bool cheated;
    public:
    CharacterData(const int id,const string& name){
        this -> name = name;
        this -> id = id;
        cheated = false;
    }
    int idreturn(){
        return id;
    }
    string namereturn(){
        return name;
    }
    ~CharacterData(){}
}

#endif