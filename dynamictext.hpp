#ifndef DYN_TEXT_H_INCLUDED
#define DYN_TEXT_H_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"

class DynamicText : public Widget {
protected:
    std::string _text;
public:
    DynamicText(int x, int y, int sx, int sy);
    virtual void draw(int r, int g, int b) const;
    virtual std::string get_text() const;
    virtual void handle (genv::event ev) ;
};

#endif // DYN_TEXT_H_INCLUDED
