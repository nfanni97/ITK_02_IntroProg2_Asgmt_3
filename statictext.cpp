#include "statictext.hpp"
#include "graphics.hpp"

using namespace genv;

StaticText :: StaticText(int x, int y, int sx, int sy, std::string t)
    : Widget(x,y,sx,sy,false)
{
    _text = t;
}

void StaticText :: draw(int r, int g, int b) const
{
    gout<<color(0,0,0);
    gout<<move_to(_x,_y)<<text(_text);
}
