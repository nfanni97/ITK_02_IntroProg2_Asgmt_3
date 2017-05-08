#ifndef COMBINEDLIST_HPP_INCLUDED
#define COMBINEDLIST_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"

#include <map>

class CombinedList : public Widget {
    std::map<std::string,std::string> _o;
    //std::map<std::string,std::string>::iterator _top,_active;
    int _lines,_top,_active;
public:
    CombinedList(int x, int y, std::map<std::string,std::string> options, int sx, int lines);
    virtual void draw(int r, int g, int b) const;
    virtual void handle(genv::event ev);
    virtual void get_active(std::string &f, std::string &s);
    virtual void add(std::string first,std::string second);
    virtual void del();//kiválasztott elemet törli
    virtual void write_to(std::ofstream & output) const;
};

#endif // COMBINEDLIST_HPP_INCLUDED
