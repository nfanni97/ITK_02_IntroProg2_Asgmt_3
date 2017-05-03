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

Numeric :: Numeric(int x, int y, int sx, int sy, int down, int up, int innum) : Widget(x,y,sx,sy) {
    _floor=down;
    _ceiling=up;
    _n=(innum>=down && innum<=up)?innum:(down+up)/2;//ha a konstruktorban rossz a kezdeti érték, ő maga ad meg egy átlagot
}

void Numeric :: draw(int r, int g, int b) const {
    /*const int _L=gout.cascent()+gout.cdescent();
    gout<<move_to(_x,_y)<<color(r,g,b)<<box(_size_x-_size_y/2,_size_y)<<move_to(_x+2,_y+2)<<color(0,0,0)<<box(_size_x-_size_y/2-4,_size_y-4);//szám kerete
    gout<<move_to(_x+2,_y+2+(_size_y-4-gout.cascent()-gout.cdescent())/2)<<color(255,255,255)<<text(_n);//szám
    gout<<color(r,g,b)<<move_to(_x+_size_x-_size_y/2,_y)<<box(_size_y/2,_size_y/2)<<move_to(_x+_size_x-_size_y/2+2,_y+2)<<color(0,0,0)<<box(_size_y/2-4,_size_y/2-4);//felső doboz
    gout<<color(255,255,255)<<move_to(_x+_size_x-_size_y/2+6+(_size_y/2-12)/2,_y+6)<<line_to(_x+_size_x-6,_y+_size_y/2-6)<<line_to(_x+_size_x-_size_y/2+6,_y+_size_y/2-6)<<line_to(_x+_size_x-_size_y/2+6+(_size_y/2-12)/2,_y+6);//felső nyíl
    gout<<color(r,g,b)<<move_to(_x+_size_x-_size_y/2,_y+_size_y/2)<<box(_size_y/2,_size_y/2)<<color(0,0,0)<<move_to(_x+_size_x-_size_y/2+2,_y+_size_y/2+2)<<box(_size_y/2-4,_size_y/2-4);//alsó doboz
    gout<<color(255,255,255)<<move_to(_x+_size_x-_size_y/2+6,_y+_size_y/2+6)<<line_to(_x+_size_x-6,_y+_size_y/2+6)<<line_to(_x+_size_x-_size_y/2+6+(_size_y/2-12)/2,_y+_size_y-6)<<line_to(_x+(_size_x-_size_y/2)+6,_y+_size_y/2+6);//alsó nyíl*/
    gout<<move_to(_x,_y)<<color(r,g,b)<<box(_size_x,_size_y)<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_size_x-4,_size_y-4);
    if(_n!=0) gout<<move_to(_x+(_size_x-gout.twidth(num2str(_n)))/2,_y+(_size_y-gout.cascent()-gout.cdescent())/2)<<color(0,0,0)<<text(num2str(_n));
}

int Numeric::get_num() const {
    return _n;
}

void Numeric :: add(int nn) {//tetszőleges számot hozzáad/elvesz a számból
    _n+=nn;
    if(_n>=_ceiling) _n=_ceiling;
    else if(_n<=_floor) _n=_floor;
}

void Numeric :: handle(event ev) {
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

void Numeric::write_to(std::ofstream & output) const {
    output<<"x: "<<_x<<"\ny: "<<_y<<"\nx-size: "<<_size_x<<"\ny-size: "<<_size_y<<"\nvalue: "<<_n<<"\ninterval: "<<_floor<<"->"<<_ceiling<<std::endl;
}
