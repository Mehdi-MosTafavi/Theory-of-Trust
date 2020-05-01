#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP
class CharacterData{
    int id;
    string name;
    int point;
    bool cheated;
    public:
    CharacterData(int i,string& n) {
        id = i ;
        name = n ;
        cheated = false;
        point = 0;
    }
    //Play without user
    CharacterData(int i) {
        id = i ;
        name = Character::character[i].name ;
        point = 0;
    }
    int idreturn() const {
        return id;
    }
    int pointreturn(){
        return point;
    }
    void pointset(const int p){
        point+=p;
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
