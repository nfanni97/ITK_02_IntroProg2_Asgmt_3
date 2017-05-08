#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include <vector>
#include <string>

class GameMaster {
public:
    GameMaster();//v: given values (will be stored in _field later on)
    bool is_correct(int c, int v, std::vector<int> field) const;//decides whether the value v in cell c is correct
    bool is_finished(std::vector<int> field) const;
    std::vector<int> load_field(std::string filename) const;
};
#endif // GAMEMASTER_HPP_INCLUDED