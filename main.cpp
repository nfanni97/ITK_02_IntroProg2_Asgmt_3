#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "numeric.hpp"
#include "statictext.hpp"
#include "gamemaster.hpp"
#include "game.hpp"

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
            bool changeable=(given[i]==0)?true:false;
            temp=new Numeric(10+i%9*C+(i%9)/3*5,10+i/9*C+i/27*5,C,C,0,9,changeable,given[i]);
            cells.push_back(temp);
            widgets.push_back(temp);
        }
    }
    void game_logic() {
        vector<int> _field=make_field();
        for(int i=0;i<81;i++) cells[i]->set_correct(_gm.is_correct(i,_field[i],_field));

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
    GameMaster gm;
    Sudoku *sudoku=new Sudoku(XX,YY,field, gm);
    //Sudoku *sudoku=new Sudoku(XX,YY,"finished.txt", gm);
    sudoku->event_loop();
    return 0;
}
