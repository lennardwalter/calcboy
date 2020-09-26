apps_src += $(addprefix apps/calcboy/emu/,\
audio.c                 \
cpu.c                   \
debugger-dummy.c        \
disassembler.c          \
emu.c                   \
fileio.c                \
lcd.c                   \
main.c                  \
mmu.c                   \
gui.c                   \
state.c                 \
wrapper.cpp \
)

apps/calcboy/emu/emu.c: apps/calcboy/emu/rom.h

apps/calcboy/emu/rom.h: FORCE
	$(Q) echo "const unsigned char rom_data[] = {" > $@
	$(Q) cat "$(GB_ROM)" | xxd -i >> $@
	$(Q) echo "};" >> $@

FORCE: