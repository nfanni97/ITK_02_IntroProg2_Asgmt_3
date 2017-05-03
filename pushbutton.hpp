#ifndef PUSHBUTTON_H_INCLUDED
#define PUSHBUTTON_H_INCLUDED

#include "widgets.hpp"
#include "window.hpp"

class PushButton : public Widget {
protected:
    Window *_parent;
    std::string _text,_id;
public:
    PushButton(Window * parent, int x, int y, int sx, int sy, std::string s, std::string id);
    virtual void draw(int r, int g, int b) const;
    virtual void handle(genv::event ev);
    virtual void action();
};

#endif // PUSHBUTTON_H_INCLUDED
