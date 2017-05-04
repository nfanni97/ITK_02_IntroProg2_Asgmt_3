#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    bool _focusable,_focused;
    public:
public:
    Widget(int x, int y, int sx, int sy, bool focusable);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw(int r, int g, int b) const;
    virtual bool is_focusable() const;
    virtual void focus();
    virtual void unfocus();
    virtual void handle(genv::event ev);
    virtual void write_to(std::ofstream & output) const;
};

#endif // WIDGETS_HPP_INCLUDED
