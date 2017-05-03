#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include "list.hpp"
#include "pushbutton.hpp"
#include "numeric.hpp"
#include "statictext.hpp"

#include <iostream>
#include <vector>

using namespace genv;
using namespace std;

const int XX=280,YY=280;//size of window
const int C=30;//size of cells (square)

class MyWindow : public Window {
public:
    vector<Numeric*> cells;
    MyWindow(int x,int y) {
        _size_x=x;
        _size_y=y;
        for(int i=0;i<81;i++) {
            Numeric *temp=new Numeric(i%9*C+(i%9)/3*5,i/9*C+i/27*5,C,C,0,9);
            cells.push_back(temp);
            widgets.push_back(temp);
        }
    }
    void esemeny(string mitortent) {
    }
};

int main()
{
    gout.open(XX,YY);
    gout.load_font("LiberationSerif-BoldItalic.ttf",20);
    MyWindow *mywindow=new MyWindow(XX,YY);
    mywindow->event_loop();
    return 0;
}
