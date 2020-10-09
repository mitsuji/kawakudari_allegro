#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include "ichigojam.h"

#define TRUE 1
#define FALSE 0

int main()
{
  srand(time(NULL));

  al_init();
  al_install_keyboard();
  al_init_primitives_addon();

  ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();
  ALLEGRO_DISPLAY * disp = al_create_display(512, 384);
  ALLEGRO_TIMER * timer = al_create_timer(1.0 / 60.0);

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  STD15 * std15 = ij_create_std15(512,384,32,24);
  unsigned int frame = 0;
  int x = 15;
  int running = TRUE;

  al_start_timer(timer);
  while(TRUE) {
    ALLEGRO_EVENT event;
    al_wait_for_event(queue, &event);
    switch(event.type) {
    case ALLEGRO_EVENT_TIMER: {
      if(al_is_event_queue_empty(queue)) {
        if (!running) break;
        if (frame % 5 == 0) {
          ij_locate(std15,x,5);
          ij_putc(std15,'0');
          ij_locate(std15,rand()%32,23);
          ij_putc(std15,'*');
          ij_scroll(std15, DIR_UP);
          if (ij_scr(std15,x,5) != '\0') {
	    ij_locate(std15,0,23);
	    ij_putstr(std15,"Game Over...");
	    ij_putnum(std15,frame);
	    running = FALSE;
	  }
        }
        ij_draw_screen(std15);
        ++ frame;
      }
      break;
    }
    case ALLEGRO_EVENT_KEY_DOWN: {
      ALLEGRO_KEYBOARD_STATE key_state;
      al_get_keyboard_state(&key_state);
      if(al_key_down(&key_state,ALLEGRO_KEY_LEFT))  --x;
      if(al_key_down(&key_state,ALLEGRO_KEY_RIGHT)) ++x;
      break;
    }
    case ALLEGRO_EVENT_DISPLAY_CLOSE: {
      goto SHUTDOWN;
      break;
    }
    }
  }

SHUTDOWN:
  ij_destroy_std15(std15);
  al_destroy_timer(timer);
  al_destroy_display(disp);
  al_destroy_event_queue(queue);

  return 0;
}
