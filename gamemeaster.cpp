#include "gamemaster.hpp"
#include <vector>

#include <iostream>

GameMaster::GameMaster() {
}

bool GameMaster::is_correct(int c,int v,std::vector<int> field) const {
    bool good=true;
    int row=c/9;
    int col=c%9;
    for(int i=0;i<9 && good;i++) {
        if(row*9+i!=c && v==field[row*9+i]) good=!good;//checking rows
        else if(i*9+col!=c && v==field[col+i*9]) good=!good;//checking columns
    }
    int first=row/3*27+col/3*3;
    std::cout<<c<<" "<<v<<" "<<first<<std::endl;
    for(int i=first;i<first+21 && good;(i%3==2)?i+=7:i+=1) {if(i!=c && v==field[i]) good=!good;std::cout<<i<<" "<<field[i]<<std::endl;}
    return good;
}
