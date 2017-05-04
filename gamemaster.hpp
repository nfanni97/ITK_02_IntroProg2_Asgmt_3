#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include <vector>

class GameMaster {
public:
    GameMaster();//v: given values (will be stored in _field later on)
    bool is_correct(int c, int v, std::vector<int> field) const;//decides whether the value v in cell c is correct (at the time) and commits it to _field
};
#endif // GAMEMASTER_HPP_INCLUDED