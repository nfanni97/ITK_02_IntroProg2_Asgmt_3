#ifndef PUSHBUTTON_H_INCLUDED
#define PUSHBUTTON_H_INCLUDED

#include "widgets.hpp"
#include <functional>

class PushButton : public Widget {
protected:
    std::function<void()> _functor;
    std::string _text;
public:
    PushButton(int x, int y, int sx, int sy, std::string s, std::function<void()> f);
    virtual void draw(int r, int g, int b) const;
    virtual void handle(genv::event ev);
    virtual void action();
};

#endif // PUSHBUTTON_H_INCLUDED
