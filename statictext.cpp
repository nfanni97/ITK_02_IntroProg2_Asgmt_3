#include "statictext.hpp"
#include "graphics.hpp"

using namespace genv;

StaticText :: StaticText(int x, int y, int sx, int sy, std::string t)
    : Widget(x,y,sx,sy)
{
    _text = t;
}

void StaticText :: draw(int r, int g, int b) const
{
    gout<<color(0,255,0)<<move_to(_x,_y)<<box(_size_x,_size_y)<<color(255,255,255)<<move_to(_x+2,_y+2)<<box(_size_x-4,_size_y-4)<<color(0,0,0)<<move_to(_x+(_size_x-gout.twidth(_text))/2,_y+(_size_y-gout.cascent()-gout.cdescent())/2)<<text(_text);
}
