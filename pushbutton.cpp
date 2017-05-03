#include "pushbutton.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

PushButton :: PushButton(Window * parent, int x, int y, int sx, int sy, std::string s, std::string id)
    : Widget(x,y,sx,sy)
    {
        _parent=parent;
        _text=s;
        _id=id;
    }

void PushButton :: draw(int r, int g, int b) const {
    gout<<move_to(_x,_y)<<color(r,g,b)<<box(_size_x,_size_y)<<color(255,255,255)<<move_to(_x+2,_y+2)<<box(_size_x-4,_size_y-4)<<move_to(_x+2+(_size_x-4-gout.twidth(_text))/2,_y+2+(_size_y-4-gout.cascent()-gout.cdescent())/2)<<color(0,0,0)<<text(_text);
}

void PushButton :: handle(event ev) {
    if(ev.type==ev_mouse && ev.button==btn_left && is_selected(ev.pos_x,ev.pos_y)) action();
}

void PushButton :: action() {
    _parent->esemeny(_id);
}
