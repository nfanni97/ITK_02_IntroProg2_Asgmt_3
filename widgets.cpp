#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, bool focusable)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _focusable=focusable;
    _focused=false;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::draw(int r, int g, int b) const {
}

bool Widget::is_focusable() const {
    return _focusable;
}

void Widget::focus() {
    if(_focusable) _focused=true;
}

void Widget::unfocus() {
    if(_focusable) _focused=false;
}

void Widget::handle(event ev) {
}

void Widget::write_to(std::ofstream & output) const {
}



