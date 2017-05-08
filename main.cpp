#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "numeric.hpp"
#include "statictext.hpp"
#include "gamemaster.hpp"
#include "pushbutton.hpp"
#include "game.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <sstream>

using namespace genv;
using namespace std;

const int XX=300,YY=300;//size of window
const int C=30;//size of cells (square)

class Sudoku : public Game {
public:
    vector<Numeric *> cells;
    Sudoku(int x,int y,string filename,GameMaster gm) : Game(x,y,gm) {
        vector<int> given=gm.load_field(filename);
        for(int i=0;i<81;i++) {
            Numeric *temp;
            if(given[i]!=0) temp=new Numeric(10+i%9*C+(i%9)/3*5,10+i/9*C+i/27*5,C,C,0,9,false,given[i]);
            else temp=new Numeric(10+i%9*C+(i%9)/3*5,10+i/9*C+i/27*5,C,C,0,9,true);
            cells.push_back(temp);
            widgets.push_back(temp);
        }
    }
    void game_logic() {
        vector<int> _field=make_field();
        for(int i=0;i<81;i++) if(_field[i]!=0) cells[i]->set_correct(_gm.is_correct(i,_field[i],_field));
        if(_gm.is_finished(_field)) {
            string f1="Hurray, you did it!";
            string f2="Press Esc to exit";
            StaticText *finish1=new StaticText((_size_x-gout.twidth(f1))/2,_size_y/2-gout.cascent(),gout.twidth(f1),gout.cascent()+gout.cdescent(),f1);
            StaticText *finish2=new StaticText((_size_x-gout.twidth(f2))/2,_size_y/2+4,gout.twidth(f2),gout.cascent()+gout.cdescent(),f2);
            finish1->draw(255,128,0);
            finish2->draw(255,128,0);
        }

    }
    vector<int> make_field() {
        vector<int> result;
        for(int i=0;i<cells.size();i++) result.push_back(cells[i]->get_num());
        return result;
    }
};

string num2str(int a) ;
int main()
{
    srand(time(0));
    int fieldn=rand()%5+1;
    string field=(fieldn<10)?"0":"";
    field+=num2str(fieldn)+".txt";
    cout<<field;
    GameMaster gm;
    Sudoku *sudoku=new Sudoku(XX,YY,field, gm);
    sudoku->event_loop();
    return 0;
}
