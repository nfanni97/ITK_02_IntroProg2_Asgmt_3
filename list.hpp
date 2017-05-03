#ifndef CHOOSE_H_INCLUDED
#define CHOOSE_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

class List : public Widget {
protected:
    std::vector<std::string> _o;//lehetőségek listája
    int _lines,_top,_active;//melyik az éppen kiválasztott elem, kirajzoláskor hány lehetõség látszik és melyik indexû a legfelsõ
public:
    List(int x, int y, std::vector<std::string> options, int sx, int lines);
    virtual void draw(int r, int g, int b) const;
    virtual void handle(genv::event ev);
    virtual void add(std::string t);
    virtual void del();//kiválasztott elemet törli
    virtual void write_to(std::ofstream & output) const;
};

#endif // CHOOSE_H_INCLUDED
