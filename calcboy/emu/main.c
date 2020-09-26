#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "wrapper.h"

#include "types.h"
#include "hwdefs.h"
#include "emu.h"
#include "state.h"
#include "cpu.h"
#include "mmu.h"
#include "lcd.h"
#include "audio.h"
#include "disassembler.h"
#include "debugger.h"
#include "gui.h"
#include "fileio.h"

#define GUI_WINDOW_TITLE "Calcboy"
#define GUI_ZOOM 1

int parse_args(int argc, char **argv, struct emu_args *emu_args)
{
    // we could theoretically add args support again.
    // the omega / epsilon app would have a gui for settings (like selecting a rom)
    // and it would give the pointer to the rom, etc. as an argument to gb_main()
    memset(emu_args, 0, sizeof(struct emu_args));

    // to lazy to remove all references
    emu_args->rom_filename = "placeholder";

    return 0;
}

int gb_main(int argc, char *argv[])
{
    struct gb_state gb_state;

    struct emu_args emu_args;
    if (parse_args(argc, argv, &emu_args))
        return 1;

    if (emu_init(&gb_state, &emu_args))
    {
        fprintf(stderr, "Initialization failed\n");
        return 1;
    }

    // if (emu_args.audio_enable)
    // {
    //     if (gui_audio_init(AUDIO_SAMPLE_RATE, AUDIO_CHANNELS, AUDIO_SNDBUF_SIZE,
    //                        gb_state.emu_state->audio_sndbuf))
    //     {
    //         fprintf(stderr, "Couldn't initialize GUI audio\n");
    //         return 1;
    //     }
    // }

    printf("==========================\n");
    printf("=== Starting execution ===\n");
    printf("==========================\n\n");

    struct player_input input_state;
    memset(&input_state, 0, sizeof(struct player_input));

    while (!gb_state.emu_state->quit)
    {
        // timing at it's finest!

        // the device is too slow anyway so idc
        #if DEVICE
        
        emu_step_frame(&gb_state);
        gui_input_poll(&input_state);
        emu_process_inputs(&gb_state, &input_state);
        
        #else
        
        uint64_t before = millis();
        
        emu_step_frame(&gb_state);
        gui_input_poll(&input_state);
        emu_process_inputs(&gb_state, &input_state);
        
        int time_to_sleep = 16 - (millis() - before);
        if (time_to_sleep > 0)
        {
            sleep(time_to_sleep);
        }

        #endif
    }

    // we could add save support again
    // if (gb_state.emu_state->extram_dirty)
    //     emu_save(&gb_state, 1, gb_state.emu_state->save_filename_out);

    void *stuff_to_free[] = {gb_state.emu_cpu_state,
                             gb_state.mem_WRAM,
                             gb_state.mem_EXTRAM,
                             gb_state.mem_VRAM,
                             gb_state.emu_state->lcd_pixbuf,
                             gb_state.emu_state};

    for (int i = 0; i < 6; i++)
    {
        if (stuff_to_free[i] != NULL)
        {
            free(stuff_to_free[i]);
        }
    }
    printf("\nEmulation ended at instr: ");
    disassemble(&gb_state);
    dbg_print_regs(&gb_state);

    return 0;
}
