# CalcBoy

A Gameboy Color emulator for the Numworks graphing calculator based on [koenk/gbc](https://github.com/koenk/gbc).

## How to build

Connect the calculator to the computer, then

```bash
git clone https://github.com/numworks/epsilon
git clone https://github.com/hallowed/calcboy
cp -r calcboy/calcboy epsilon/apps
cd epsilon
make GB_ROM='<path_to_ROM>' EPSILON_APPS='calcboy calculation graph code statistics probability solver sequence regression settings' epsilon_flash
```

## Controls

| Calculator | Gameboy |
| ---------- | ------- |
| Up         | Up      |
| Down       | Down    |
| Left       | Left    |
| Right      | Right   |
| Back       | A       |
| OK         | B       |
| Backspace  | Start   |
| Toolbox    | Select  |
| Home       | Exit    |

## Problems

The emulator is quite slow (not original speed), most games seem to run though.
There are some visual problems as well, probably because I have to push a scanline to the screen,
rather than the whole frame at once. There is also no support for saving the state at the moment.

## Todo (Contributing?)

- **Optimization!**

- Implementing save-state

- Adding multi-ROM support

- Making an icon
