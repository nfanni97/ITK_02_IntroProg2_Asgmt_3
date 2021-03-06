#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "window.hpp"
#include "gamemaster.hpp"
#include "graphics.hpp"

class Game : public Window {
protected:
    GameMaster _gm;
    int _font;
    virtual void game_logic();
public:
    Game(int x, int y, GameMaster gm, int font);
    void event_loop();
};

#endif // GAME_HPP_INCLUDED
