#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    public:
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw(int r, int g, int b) const;
    virtual void handle(genv::event ev);
    virtual void write_to(std::ofstream & output) const;
};

#endif // WIDGETS_HPP_INCLUDED
