#include "graphics.hpp"
#include "numeric.hpp"
#include <sstream>
#include <fstream>

using namespace genv;

std::string num2str(int x) {
    std::stringstream ss;
    ss<<x;
    return ss.str();
}

Numeric :: Numeric(int x, int y, int sx, int sy, int down, int up, bool changeable, int innum) : Widget(x,y,sx,sy,changeable) {
    _floor=down;
    _ceiling=up;
    _correct=true;
    _n=(innum>=down && innum<=up)?innum:(down+up)/2;//ha a konstruktorban rossz a kezdeti érték, ő maga ad meg egy átlagot
}

void Numeric :: draw(int r, int g, int b) const {
    if(_focusable) {
        if(_correct) gout<<color(r,g,b);
        else if(_focused) gout<<color(r,g,b);
        else gout<<color(255,0,0);
    }
    else {
        if(_correct) gout<<color(0,0,0);
        else gout<<color(255,0,0);
    }
    gout<<move_to(_x,_y)<<box(_size_x,_size_y)<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_size_x-4,_size_y-4);
    if(_n!=0) {
        gout<<move_to(_x+(_size_x-gout.twidth(num2str(_n)))/2,_y+(_size_y-gout.cascent()-gout.cdescent())/2);
        if(_correct) {
            if(_focusable) gout<<color(0,0,0);
            else gout<<color(0,0,255);
        }
        else gout<<color(255,0,0);
        gout<<text(num2str(_n));
    }
}

int Numeric::get_num() const {
    return _n;
}

void Numeric::set_correct(bool to) {
    _correct=to;
}

void Numeric :: add(int nn) {//tetszőleges számot hozzáad/elvesz a számból
    _n+=nn;
    if(_n>=_ceiling) _n=_ceiling;
    else if(_n<=_floor) _n=_floor;
}

void Numeric :: handle(event ev) {
    if(_focusable) {
        if(ev.type==ev_mouse)//görgetéskor
        {
            if(ev.button==btn_wheelup) add(1);
            else if(ev.button==btn_wheeldown) add(-1);
        }
        if(ev.type==ev_key)//gombnyomáskor
        {
            switch(ev.keycode)
            {
                case key_up: add(1);break;
                case key_down: add(-1);break;
                case key_pgup: add(10);break;
                case key_pgdn: add(-10);break;
            }
        }
    }
}

void Numeric::write_to(std::ofstream & output) const {
    output<<"x: "<<_x<<"\ny: "<<_y<<"\nx-size: "<<_size_x<<"\ny-size: "<<_size_y<<"\nvalue: "<<_n<<"\ninterval: "<<_floor<<"->"<<_ceiling<<std::endl;
}
