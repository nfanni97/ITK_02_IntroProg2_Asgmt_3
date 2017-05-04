#include "window.hpp"
#include "graphics.hpp"

using namespace genv;

void Window :: event_loop() {
    event ev;
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
        gout<<refresh;
    }
}
