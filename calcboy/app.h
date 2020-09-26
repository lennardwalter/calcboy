#ifndef CALCBOY_APP_H
#define CALCBOY_APP_H

#include <escher.h>
#include <apps/apps_container.h>
#include "calcboy_controller.h"

namespace Calcboy
{

  class App : public ::App
  {
  public:
    class Descriptor : public ::App::Descriptor
    {
    public:
      I18n::Message name() override;
      I18n::Message upperName() override;
      const Image *icon() override;
    };
    class Snapshot : public ::App::Snapshot
    {
    public:
      App *unpack(Container *container) override;
      void reset() override;
      Descriptor *descriptor() override;
    };
    virtual void didBecomeActive(Window *window);
    virtual void willBecomeInactive();

  private:
    App(Container *container, Snapshot *snapshot);
    CalcboyController m_calcboyController;
    AppsContainer *m_appsContainer;
  };

} // namespace Calcboy

#endif
