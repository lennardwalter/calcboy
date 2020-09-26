#include <stdint.h>

#include "gui.h"
#include "wrapper.h"

void gui_draw_line(uint16_t *pixels, uint8_t y, bool use_color)
{
    if (use_color)
    {
        for (int x = 0; x < 160; x++)
        {
            // please someone fix this, i beg you
            pixels[x] = ((((pixels[x] >> 0) & 0x1f) << 3) >> 3) << 11 | ((((pixels[x] >> 5) & 0x1f) << 3) >> 2) << 5 | ((((pixels[x] >> 10) & 0x1f) << 3) >> 3);
        }
    }
    else
    {
        uint16_t palette[] = {0xffff, 0xad55, 0x632c, 0x1082};

        for (int x = 0; x < 160; x++)
        {
            pixels[x] = palette[pixels[x]];
        }
    }
    drawLine(pixels, y);
}

int gui_input_poll(struct player_input *input)
{
    input->special_quit = 0;
    input->special_savestate = 0;
    input->special_dbgbreak = 0;

    uint8_t *key_states = getKeyStates();

    input->button_left = key_states[0];
    input->button_up = key_states[1];
    input->button_down = key_states[2];
    input->button_right = key_states[3];
    input->button_b = key_states[4];
    input->button_a = key_states[5];
    input->special_quit = key_states[6];
    input->button_start = key_states[7];
    input->button_select = key_states[8];

    return 1;
}
