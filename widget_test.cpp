#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include "list.hpp"
#include "numeric.hpp"
#include "pushbutton.hpp"
#include "statictext.hpp"

#include <iostream>

using namespace genv;
using namespace std;

const int XX=800,YY=800;

class MyWindow : public Window {
public:
    DynamicText *editor;
    CheckBox *check;
    List *menu;
    Numeric *num;
    StaticText *label;
    PushButton *add;
    PushButton *del;
    MyWindow(int x, int y) {
        _size_x=x;
        _size_y=y;
        int _L=gout.cascent()+gout.cdescent();
        editor=new DynamicText(10,10,200,_L+4);
        check=new CheckBox(10,14+_L,20,20);
        vector<string> v={"nulla","egy","ketto","harom","negy","ot","hat"};
        menu=new List(10,34+_L,v,200,3);
        num=new Numeric(10,38+4*_L,200,50,0,40);
        label=new StaticText(300,10,gout.twidth("Test")+4,_L+4,"Test");
        add=new PushButton(this,10,88+4*_L,50,30," + ","add");
        del=new PushButton(this,10,118+4*_L,50,30," - ","del");
        widgets.push_back(editor);
        widgets.push_back(check);
        widgets.push_back(menu);
        widgets.push_back(num);
        widgets.push_back(label);
        widgets.push_back(add);
        widgets.push_back(del);
    }
    void esemeny(string mitortent) {
        if(mitortent=="add") menu->add(editor->get_text());
        else if(mitortent=="del") menu->del();
    }
};

int main()
{
    gout.open(XX,YY);
    gout.load_font("LiberationSerif-BoldItalic.ttf",22);
    MyWindow *mywindow=new MyWindow(XX,YY);
    mywindow->event_loop();
    std::cout<<gout.cascent()+gout.cdescent();
    return 0;
}
