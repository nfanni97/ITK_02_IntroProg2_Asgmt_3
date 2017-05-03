#include "gamemaster.hpp"
#include <vector>

//#include <iostream>
GameMaster::GameMaster() {
}

bool GameMaster::is_correct(int c,int v,std::vector<int> field) const {
    bool good=true;
    for(int i=0;i<9&&good;i++) {
        int row=c/9/3;
        int col=c%9/3;//position of v in its division
        int div=row*3+col;//coordinate of division (row-major)
        if(i!=c && v==field[c%9+i]) good=!good;//checking rows
        else if(i!=c && v==field[c%9+i*9]) good=!good;//checking columns
        else if(i!=c && i<3 && (v==field[row*27+col*3+i] || v==field[9+row*27+col*3+i] || v==field[18+row*27+col*3+i])) good=!good;
    }
    return good;
}
