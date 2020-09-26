#include "wrapper.h"
#include <ion.h>
#include <kandinsky.h>
#include <stdint.h>

#ifdef DEVICE
#include "../../ion/src/device/shared/drivers/display.h"
#endif

Ion::Keyboard::Key keysToCheck[] = {
    Ion::Keyboard::Key::Left,
    Ion::Keyboard::Key::Up,
    Ion::Keyboard::Key::Down,
    Ion::Keyboard::Key::Right,
    Ion::Keyboard::Key::OK,
    Ion::Keyboard::Key::Back,
    Ion::Keyboard::Key::Home,
    Ion::Keyboard::Key::Backspace,
    Ion::Keyboard::Key::Toolbox,

};

uint8_t *getKeyStates()
{

    Ion::Keyboard::State state = Ion::Keyboard::scan();
    static uint8_t returnState[sizeof(keysToCheck)];

    for (int i = 0; i < sizeof(keysToCheck); i++)
    {
        returnState[i] = state.keyDown(keysToCheck[i]) ? 1 : 0;
    }
    return returnState;
}

void sleep(uint32_t amount)
{
    Ion::Timing::msleep(amount);
}

uint64_t millis()
{
    return Ion::Timing::millis();
}

void drawLine(uint16_t *pixels, uint8_t y)
{
#if DEVICE
    uint8_t numberOfPixels = 160;
    Ion::Device::Display::setDrawingArea(KDRect(80, y + 48, 160, 1), Ion::Device::Display::Orientation::Landscape);
    *Ion::Device::Display::CommandAddress = Ion::Device::Display::Command::MemoryWrite;

    while (numberOfPixels > 32)
    {
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        *Ion::Device::Display::DataAddress = *pixels++;
        numberOfPixels -= 32;
    }
    while (numberOfPixels--)
    {
        *Ion::Device::Display::DataAddress = *pixels++;
    }
#else
    Ion::Display::pushRect(KDRect(80, y + 48, 160, 1), (KDColor *)pixels);
#endif
}
