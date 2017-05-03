#ifndef GAMEMASTER_HPP_INCLUDED 
#define GAMEMASTER_HPP_INCLUDED 
 
class GameMaster { 
    std::vector<int> _given;//coordinates of given cells 
    std::map<int,int> _field;//coordinates and values of all cells 
public: 
    GameMaster(vector<int> g,vector<int> v);//v: values (will be stored in _field later on) 
    bool is_correct(int c,int v);//decides whether the value v in cell c is correct (at the time) and commits it to _field 
}; 
 
#endif // GAMEMASTER_HPP_INCLUDED 