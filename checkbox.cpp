#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

CheckBox::CheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy), _checked(false) {
    }

void CheckBox::draw(int r, int g, int b) const
{
    gout << move_to(_x, _y)<<color(r,g,b);
    gout << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    if (_checked) {
        gout << color(0,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
}

void CheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool CheckBox::is_checked() const
{
    return _checked;
}
