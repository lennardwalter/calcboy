#ifndef GUI_H
#define GUI_H

#include "player_input.h"

int gui_input_poll(struct player_input *input);
void gui_draw_line(uint16_t *pixels, uint8_t y, bool use_color);

#endif
