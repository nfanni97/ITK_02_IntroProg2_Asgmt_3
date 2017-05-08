#include "game.hpp"
#include "graphics.hpp"

using namespace genv;

Game::Game(int x, int y, GameMaster gm) {
    _size_x=x;
    _size_y=y;
    _gm=gm;
}

void Game::game_logic() {}

void Game :: event_loop() {
    event ev;
    gout.open(_size_x,_size_y);
    gout.load_font("LiberationSerif-BoldItalic.ttf",30);
    int f=-1;
    while(gin >> ev && ev.keycode!=key_escape) {
        if(ev.type == ev_key && ev.keycode == key_tab) {
            if(f!=-1) widgets[f]->unfocus();
            f=(f+1)%widgets.size();//tabbal is lehet lépkedni
            widgets[f]->focus();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            bool valid=false;
            for (size_t i=0;i<widgets.size();i++) {//melyikre kattintottunk: ha egyikre sem, a fókusz újra -1
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && widgets[i]->is_focusable()) {
                    if(f!=-1) widgets[f]->unfocus();
                    f = i;
                    widgets[f]->focus();
                    valid=true;
                }
            }
            if(!valid) {
                f=-1;
            }
        }
        if (f!=-1) {
            widgets[f]->handle(ev);
        }
        gout<<move_to(0,0)<<color(255,255,255)<<box(_size_x,_size_y);
        for (size_t i=0;i<widgets.size();i++) {
            if(i==f) widgets[i]->draw(255,128,0);
            else widgets[i]->draw(0,0,0);
        }
        game_logic();
        gout<<refresh;
    }
}
