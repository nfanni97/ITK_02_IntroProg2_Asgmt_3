#include "window.hpp"
#include "graphics.hpp"

using namespace genv;
void Window :: event_loop() {
    event ev;
    int focus=-1;
    while(gin >> ev && ev.keycode!=key_escape) {
        if(ev.type == ev_key && ev.keycode == key_tab) focus=(focus+1)%widgets.size();//tabbal is lehet lépkedni
        if (ev.type == ev_mouse && ev.button==btn_left) {
            bool valid=false;
            for (size_t i=0;i<widgets.size()/*&&!valid*/;i++) {//melyikre kattintottunk: ha egyikre sem, a fókusz újra -1
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                    valid=true;
                }
            }
            if(!valid) {
                focus=-1;
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            if(i==focus) widgets[i]->draw(255,128,0);
            else widgets[i]->draw(0,0,0);
        }
        gout<<refresh;
    }
}
