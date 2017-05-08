#include "graphics.hpp"
#include "combinedlist.hpp"

#include <fstream>
//#include <iostream>

using namespace genv;
using namespace std;

CombinedList :: CombinedList(int x, int y, map<string,string> options, int sx, int lines) : Widget(x,y,sx,(lines)*(gout.cascent()+gout.cdescent())+4,true), _lines(lines) {
    _o=options;
    _top=0;
    _active=0;
}

void CombinedList :: draw(int r, int g, int b) const {
    const int _L=gout.cascent()+gout.cdescent();
    gout<<color(r,g,b)<<move_to(_x,_y)<<box(_size_x-_L,_size_y)<<color(255,255,255)<<move_to(_x+2,_y+2)<<box(_size_x-_L-4,_size_y-4);//nagy keret
    gout<<color(r,g,b)<<move_to(_x+_size_x-_L,_y)<<box(_L,_L)<<color(255,255,255)<<move_to(_x+_size_x-_L+2,_y+2)<<box(_L-4,_L-4);//felső doboz
    gout<<color(0,0,0)<<move_to(_x+_size_x-_L+_L/2,_y+6)<<line_to(_x+_size_x-6,_y+_L-6)<<line_to(_x+_size_x-_L+6,_y+_L-6)<<line_to(_x+_size_x-_L+_L/2,_y+6);//felső nyíl
    gout<<color(r,g,b)<<move_to(_x+_size_x-_L,_y+_size_y-_L)<<box(_L,_L)<<color(255,255,255)<<move_to(_x+_size_x-_L+2,_y+_size_y-_L+2)<<box(_L-4,_L-4);//alsó doboz
    gout<<color(0,0,0)<<move_to(_x+_size_x-_L+6,_y+_size_y-_L+6)<<line_to(_x+_size_x-6,_y+_size_y-_L+6)<<line_to(_x+_size_x-_L+_L/2,_y+_size_y-6)<<line_to(_x+_size_x-_L+6,_y+_size_y-_L+6);//alsó nyíl
    if(_o.size()!=0 && _active>=_top && _active<=_top+_lines-1)//kiválasztott elem háttérszíne más
        gout<<color(255,128,0)<<move_to(_x+2,_y+2+(_active-_top)*_L)<<box(_size_x-_L-4,_L);
    gout<<color(0,0,0);
    for(int s=0;s<_lines && next(_o.begin(),_top+s)!=_o.end();s++)//lehetõségek listázása (ami látszik)
    {
        string f=next(_o.begin(),_top+s)->first;
        string delim="#";
        string sec=next(_o.begin(),_top+s)->second;
        gout<<move_to(_x+2,_y+2+/*(s-1)*/s*_L/*+gout.cascent()*/)<<text(f)<<text(delim)<<text(sec);
    }
}

void CombinedList::add(string first, string second) {//hozzáadja a megadott stringet a lehetőségek listájához
    if(first!="" || second!="") {
        _o[first]=second;
    }
}

void CombinedList::del() {
    if(_o.size()!=0) {
        _o.erase(next(_o.begin(),_active));
        if(_active==_o.size()) _active--;
        if(_top+_lines>=_o.size()) _top=(_top<=1)?0:_top-1;
    }
}

void CombinedList :: handle(event ev) {
    int _L=(_size_y-4)/_lines;
    if(ev.type==ev_mouse && ev.button==btn_left)//azt nem vizsgáljuk, hogy az elemre kattintottunk-e, ezt a fõ program feladata eldönteni
    {
        if(ev.pos_x<=_x+_size_x-_L && ev.pos_y-_y<=_o.size()*_L && ev.pos_y-_y<=_lines*_L)//kattintás elemre: az lesz az aktív
            _active=_top+(ev.pos_y-_y)/_L;
        else if(ev.pos_x>_x+_size_x-_L && ev.pos_y-_y<=_L && _top>0)//görgetés felfelé (csak ha lehet)
            {_top--;}
        else if(ev.pos_x>_x+_size_x-_L && ev.pos_y-_y>=(_lines-1)*_L && _top+_lines<_o.size())//görgetés lefelé (csak ha lehet)
            {_top++;}
    }
    else if(ev.type==ev_mouse) {//görgetésre is lehet fel-le mozogni a lehetőségek között
        if(ev.button==btn_wheelup && _top>0)
            _top--;
        else if(ev.button==btn_wheeldown && _top+_lines<_o.size())
            _top++;
    }
}

void CombinedList::get_active(string &f, string &s) {
    if(_o.size()!=0) {
        f=next(_o.begin(),_active)->first;
        s=next(_o.begin(),_active)->second;
    }
}

void CombinedList :: write_to(std::ofstream & output) const {
    /*output<<"x: "<<_x<<"\ny: "<<_y<<"\nx-size: "<<_size_x<<"\ny-size: "<<_size_y<<"\noptions:\n";
    for(int map<string,string>::iterator i=_o.begin();i!=_o.end();i++) output<<"\t"<<_o[i]->first<<"#"<<_o[i]->second<<endl;
    output<<"number of lines: "<<_lines<<"\nindex of item on top: "<<_top<<"\nindex of active item: "<<_active<<endl;*/
}
