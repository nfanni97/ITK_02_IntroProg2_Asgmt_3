#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "numeric.hpp"
#include "statictext.hpp"
#include "gamemaster.hpp"
#include "pushbutton.hpp"

#include <iostream>
#include <vector>
#include <fstream>

using namespace genv;
using namespace std;

const int XX=500,YY=500;//size of window
const int C=30;//size of cells (square)

class MyWindow : public Window {
public:
    vector<Numeric *> cells;
    PushButton *test;
    GameMaster gm;
    MyWindow(int x,int y,string filename) {
        _size_x=x;
        _size_y=y;
        gm=GameMaster();
        vector<int> given=gm.load_field(filename);
        for(int i=0;i<81;i++) {
            Numeric *temp;
            if(given[i]!=0) temp=new Numeric(i%9*C+(i%9)/3*5,i/9*C+i/27*5,C,C,0,9,false,given[i]);
            else temp=new Numeric(i%9*C+(i%9)/3*5,i/9*C+i/27*5,C,C,0,9,true);
            cells.push_back(temp);
            widgets.push_back(temp);
        }
        test=new PushButton(300,300,gout.twidth("Check")+10,30,"Check",[this](){this->check();});
        widgets.push_back(test);
        gm=GameMaster();
    }
    vector<int> make_field() {
        vector<int> result;
        for(int i=0;i<cells.size();i++) result.push_back(cells[i]->get_num());
        return result;
    }
    void check() {
        vector<int> field=make_field();
        for(int i=0;i<81;i++) if(field[i]!=0) cells[i]->set_correct(gm.is_correct(i,field[i],field));
    }
};

int main()
{
    gout.open(XX,YY);
    gout.load_font("LiberationSerif-BoldItalic.ttf",20);
    MyWindow *mywindow=new MyWindow(XX,YY,"test2.txt");
    mywindow->event_loop();
    return 0;
}
