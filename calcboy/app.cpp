#include "app.h"
#include "calcboy_icon.h"
#include <apps/i18n.h>
#include <apps/apps_container.h>

namespace Calcboy
{

  I18n::Message App::Descriptor::name()
  {
    return I18n::Message::CalcboyApp;
  }

  I18n::Message App::Descriptor::upperName()
  {
    return I18n::Message::CalcboyAppCapital;
  }

  const Image *App::Descriptor::icon()
  {
    return ImageStore::CalcboyIcon;
  }

  App *App::Snapshot::unpack(Container *container)
  {
    return new (container->currentAppBuffer()) App(container, this);
  }

  void App::Snapshot::reset()
  {
  }

  App::Descriptor *App::Snapshot::descriptor()
  {
    static Descriptor descriptor;
    return &descriptor;
  }

  void App::didBecomeActive(Window *window)
  {
    ::App::didBecomeActive(window);
    Ion::Display::pushRectUniform(KDRect(0, 0, 320, 240), KDColorBlack);

    // start main emu here
  }

  void App::willBecomeInactive()
  {
    ::App::willBecomeInactive();
  }

  App::App(Container *container, Snapshot *snapshot) : ::App(snapshot, &m_calcboyController),
                                                       m_appsContainer((AppsContainer *)container)
  {
  }

} // namespace Calcboy
