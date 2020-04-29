#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP
class CharacterData{
    const int id;
    const string name;
    bool cheated;
    public:
    CharacterData(const int i,const string& n): id(i),name(n){
        cheated = false;
    }
    int idreturn() const {
        return id;
    }
    string namereturn() const {
        return name;
    }
    void
    cheatedset(const bool b = true){
        cheated = b;
    }
    bool cheatedreturn(){
        return cheated;
    }
    //bool game()
    ~CharacterData(){}
};

#endif