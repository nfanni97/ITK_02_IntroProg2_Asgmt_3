#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "numeric.hpp"
#include "statictext.hpp"
#include "gamemaster.hpp"

#include "pushbutton.hpp"

//#include <iostream>
#include <vector>
#include <fstream>

using namespace genv;
using namespace std;

const int XX=500,YY=500;//size of window
const int C=30;//size of cells (square)

class MyWindow : public Window {
public:
    vector<Numeric*> cells;
    PushButton *test;
    GameMaster gm;
    MyWindow(int x,int y) {
        _size_x=x;
        _size_y=y;
        for(int i=0;i<81;i++) {
            Numeric *temp=new Numeric(i%9*C+(i%9)/3*5,i/9*C+i/27*5,C,C,0,9);
            cells.push_back(temp);
            widgets.push_back(temp);
        }
        test=new PushButton(this,300,300,30,30,"test","test");
        widgets.push_back(test);
        gm=GameMaster();
    }
    void esemeny(string mitortent) {
        if(mitortent=="test") {cout<<endl<<gm.is_correct(0,9,field_maker())<<endl;};
    }
    vector<int> field_maker() {
        vector<int> result;
        for(int i=0;i<cells.size();i++) result.push_back(cells[i]->get_num());
        return result;
    }
    /*void load_field(string filename) {

    }*/
};

int main()
{
    gout.open(XX,YY);
    gout.load_font("LiberationSerif-BoldItalic.ttf",20);
    MyWindow *mywindow=new MyWindow(XX,YY);
    //mywindow->load_field("something");
    mywindow->event_loop();
    return 0;
}
