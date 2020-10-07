#ifndef __ICHIGOJAM_H__
#define __ICHIGOJAM_H__

typedef struct STD15 STD15;
struct STD15 {
  int screen_w;
  int screen_h;
  int buff_w;
  int buff_h;
  float dot_w;
  float dot_h;
  char * buff;
  int cursor_x;
  int cursor_y;
};

STD15 * ij_create_std15(int screen_w, int screen_h, int buff_w, int buff_h);
void ij_destroy_std15(STD15 * self);
void ij_locate(STD15 * self, int x, int y);
void ij_putc(STD15 * self, char c);
void ij_putstr(STD15 * self, const char * s);
void ij_putnum(STD15 * self, int n);
char ij_scr(STD15 * self, int x ,int y);
void ij_cls(STD15 * self);
void ij_scroll(STD15 * self);
void ij_draw_screen(STD15 * self);

#endif
