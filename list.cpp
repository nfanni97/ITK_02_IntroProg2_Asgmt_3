#include "graphics.hpp"
#include "list.hpp"

#include <fstream>

using namespace genv;
using namespace std;

List :: List(int x, int y, vector<string> options, int sx, int lines) : Widget(x,y,sx,(lines)*(gout.cascent()+gout.cdescent())+4), _o(options), _lines(lines), _top(0), _active(0) {
}

void List :: draw(int r, int g, int b) const {
    const int _L=gout.cascent()+gout.cdescent();
    gout<<color(r,g,b)<<move_to(_x,_y)<<box(_size_x-_L,_size_y)<<color(255,255,255)<<move_to(_x+2,_y+2)<<box(_size_x-_L-4,_size_y-4);//nagy keret
    gout<<color(r,g,b)<<move_to(_x+_size_x-_L,_y)<<box(_L,_L)<<color(255,255,255)<<move_to(_x+_size_x-_L+2,_y+2)<<box(_L-4,_L-4);//felső doboz
    gout<<color(0,0,0)<<move_to(_x+_size_x-_L+_L/2,_y+6)<<line_to(_x+_size_x-6,_y+_L-6)<<line_to(_x+_size_x-_L+6,_y+_L-6)<<line_to(_x+_size_x-_L+_L/2,_y+6);//felső nyíl
    gout<<color(r,g,b)<<move_to(_x+_size_x-_L,_y+_size_y-_L)<<box(_L,_L)<<color(255,255,255)<<move_to(_x+_size_x-_L+2,_y+_size_y-_L+2)<<box(_L-4,_L-4);//alsó doboz
    gout<<color(0,0,0)<<move_to(_x+_size_x-_L+6,_y+_size_y-_L+6)<<line_to(_x+_size_x-6,_y+_size_y-_L+6)<<line_to(_x+_size_x-_L+_L/2,_y+_size_y-6)<<line_to(_x+_size_x-_L+6,_y+_size_y-_L+6);//alsó nyíl
    if(_o.size()!=0 && _active>=_top && _active<=_top+_lines-1)//kiválasztott elem háttérszíne más
        gout<<color(255,128,0)<<move_to(_x+2,_y+2+(_active-_top)*_L)<<box(_size_x-_L-4,_L);
    gout<<color(0,0,0);
    for(int i=0;i<_lines;i++)//lehetõségek listázása (ami látszik)
    {
        if(i<_o.size()) gout<<move_to(_x+2,_y+2+(i-1)*_L+gout.cascent())<<text(_o[_top+i]);
    }
}

void List::add(string t) {//hozzáadja a megadott stringet a lehetőségek listájához
    if(t!="") _o.push_back(t);
}

void List::del() {
    if(_o.size()!=0) {
        _o.erase(_o.begin()+_active);
        if(_active==_o.size()) _active--;
        if(_top+_lines>=_o.size()) _top=(_top<=1)?0:_top-1;
    }
}

void List :: handle(event ev) {
    int _L=(_size_y-4)/_lines;
    if(ev.type==ev_mouse && ev.button==btn_left)//azt nem vizsgáljuk, hogy az elemre kattintottunk-e, ezt a fõ program feladata eldönteni
    {
        if(ev.pos_x<=_x+_size_x-20 && ev.pos_y-_y<=_o.size()*_L && ev.pos_y-_y<=_lines*_L)//kattintás elemre: az lesz az aktív
            _active=_top+(ev.pos_y-_y)/_L;
        else if(ev.pos_x>_x+_size_x-20 && ev.pos_y-_y<=_L && _top>0)//görgetés felfelé (csak ha lehet)
            _top--;
        else if(ev.pos_x>_x+_size_x-20 && ev.pos_y-_y>=(_lines-1)*_L && _top+_lines<_o.size())//görgetés lefelé (csak ha lehet)
            _top++;
    }
    else if(ev.type==ev_mouse) {//görgetésre is lehet fel-le mozogni a lehetőségek között
        if(ev.button==btn_wheelup && _top>0)
            _top--;
        else if(ev.button==btn_wheeldown && _top+_lines<_o.size())
            _top++;
    }
}

void List :: write_to(std::ofstream & output) const {
    output<<"x: "<<_x<<"\ny: "<<_y<<"\nx-size: "<<_size_x<<"\ny-size: "<<_size_y<<"\noptions:\n";
    for(int i=0;i<_o.size();i++) output<<"\t"<<_o[i]<<endl;
    output<<"number of lines: "<<_lines<<"\nindex of item on top: "<<_top<<"\nindex of active item: "<<_active<<endl;
}
