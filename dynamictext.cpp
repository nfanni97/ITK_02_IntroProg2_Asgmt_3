#include "dynamictext.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

DynamicText :: DynamicText(int x, int y, int sx, int sy)
    : Widget (x,y,sx,sy,true), _text("") {
}

void DynamicText :: draw(int r, int g, int b) const
{
    gout<<color(r,g,b);
    gout<<move_to(_x,_y)<<box(_size_x,_size_y)<<move_to(_x+2,_y+2)<<color(255,255,255)<<box(_size_x-4,_size_y-4);//keret
    gout<<move_to(_x+2,_y+2);
    gout<<color(0,0,0)<<text(_text+"|");//szöveg
}

string DynamicText :: get_text() const//_text getter
{
    return _text;
}

void DynamicText :: handle(event ev)
{
    if(ev.type == ev_key && ((ev.keycode>=32 && ev.keycode<=126) ||  (ev.keycode>=160 && ev.keycode<=255)))//karakter hozzáadása
    {
        char temp=ev.keycode;
        if(gout.twidth(_text+temp)<_size_x-2) _text+=temp;
    }
    else if(ev.type == ev_key && ev.keycode == key_backspace)//karakter törlése
    {
        _text=_text.substr(0,_text.length()-1);
    }
}
