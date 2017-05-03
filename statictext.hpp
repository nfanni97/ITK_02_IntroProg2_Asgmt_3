#ifndef STATIC_TEXT_H_INCLUDED
#define STATIC_TEXT_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class StaticText : public Widget {
protected:
    std::string _text;
public:
    StaticText(int x, int y, int sx, int sy, std::string t);
    virtual std::string get_text() const;
    virtual void draw(int r, int g, int b) const;
};

#endif // STATIC_TEXT_H_INCLUDED
