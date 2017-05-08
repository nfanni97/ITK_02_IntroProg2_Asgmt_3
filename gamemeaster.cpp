#include "gamemaster.hpp"
#include <vector>
#include <fstream>

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
    for(int i=first;i<first+21 && good;(i%3==2)?i+=7:i+=1) if(i!=c && v==field[i]) good=!good;
    return good;
}

bool GameMaster::is_finished(std::vector<int> field) const {
    bool yes=true;
    for(int i=0;i<field.size() && yes;i++) if(field[i]==0 || !is_correct(i,field[i],field)) yes=!yes;
    return yes;
}

std::vector<int> GameMaster::load_field(std::string filename) const {
    std::vector<int> given;
    std::ifstream f(filename);
    if(f.fail()) {
        std::vector<int> failed(81,0);
        return failed;
    }
    else {
        while(!f.eof()) {
            int temp;
            f>>temp;
            given.push_back(temp);
        }
        f.close();
        return given;
    }
}
