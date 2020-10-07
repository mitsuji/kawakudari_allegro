# kawakudari_allegro

This project implements part of the [std15.h](https://github.com/IchigoJam/c4ij/blob/master/src/std15.h) API (from [c4ij](https://github.com/IchigoJam/c4ij)) with [Allegro](https://liballeg.org/), and [Kawakudari Game](https://ichigojam.github.io/print/en/KAWAKUDARI.html) on top of it.

It will allow programming for [IchigoJam](https://ichigojam.net/index-en.html)-like targets that display [IchigoJam FONT](https://mitsuji.github.io/ichigojam-font.json/) on screen using a C programming language.
```
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
```

## Prerequisite

[Download](https://liballeg.org/download.html) and install Allegro suitable for your environment.

[Download](https://www.gnu.org/software/make/) and install GNU Make suitable for your environment.

[Download](https://gcc.gnu.org/) and install GCC suitable for your environment.

## Preparation

Adjust contents of Makefile.* to suit your environment.
```
BREW_PATH=/Users/mitsuji/apps/homebrew
```


## How to use

To build it (Linux)
```
$ make -f Makefile.linux
```

To build it (macOS)
```
$ make -f Makefile.macOS
```


To run it
```
$ ./kawakudari
```


## License
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)](http://creativecommons.org/licenses/by/4.0/)
[CC BY](https://creativecommons.org/licenses/by/4.0/) [mitsuji.org](https://mitsuji.org)

This work is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).
