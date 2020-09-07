#ifndef __ICHIGOJAM_H__
#define __ICHIGOJAM_H__

void std15_init(int screen_sx, int screen_sy, int cb_sx, int cb_sy);
void std15_destroy();
void locate(int x, int y);
void putc_(char c);
char scr(int x ,int y);
void cls();
void scroll();
void draw();

#endif
