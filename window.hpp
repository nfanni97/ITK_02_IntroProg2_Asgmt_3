#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class Window {
protected:
    std::vector<Widget*> widgets;
    int _size_x,_size_y;
public:
    void event_loop();
};

#endif // WINDOW_HPP_INCLUDED
