#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Numeric : public Widget {
protected:
    int _n,_floor,_ceiling;//számérték, alsó határ, felső határ
    bool _correct;
    virtual void add(int nn);//csak a gombokkal/egérrel lehet megváltoztatni a számot
public:
    Numeric(int x, int y, int sx, int sy, int down, int up, bool changeable, int innum=0);
    virtual void draw(int r, int g, int b) const;
    virtual int get_num() const;
    virtual void set_correct(bool to);
    virtual void handle(genv::event ev);
    virtual void write_to(std::ofstream & output) const;
};

#endif // NUMBER_HPP_INCLUDED
