# kawakudari_allegro

This project implements part of the [std15.h](https://github.com/IchigoJam/c4ij/blob/master/src/std15.h) API (from [c4ij](https://github.com/IchigoJam/c4ij)) with [Allegro](https://liballeg.org/), and [Kawakudari Game](https://ichigojam.github.io/print/en/KAWAKUDARI.html) on top of it.

It will allow programming for [IchigoJam](https://ichigojam.net/index-en.html)-like targets using a C programming language.
```
  std15_init(512,384,32,24);
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
          locate(x,5);
          putc_('0');
          locate(rand()%32,23);
          putc_('*');
          scroll();
          if (scr(x,5) != '\0') running = FALSE;
        }
        draw();
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
```

## Prerequisite

[Download](https://liballeg.org/download.html) and install Allegro suitable for your environment.

[Download](https://www.gnu.org/software/make/) and install GNU Make suitable for your environment.

[Download](https://gcc.gnu.org/) and install GCC suitable for your environment.

## How to use

To build it
```
$ make
```

To run it
```
$ ./kawakudari
```
