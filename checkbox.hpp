#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
public:
    CheckBox(int x, int y, int sx, int sy);
    virtual void draw(int r, int g, int b) const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
