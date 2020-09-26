#ifndef CALCBOY_CONTROLLER_H
#define CALCBOY_CONTROLLER_H

#include <escher.h>
#include "calcboy_view.h"

namespace Calcboy
{

  class CalcboyController : public ViewController
  {
  public:
    CalcboyController();
    View *view() override;

  private:
    CalcboyView m_calcboyView;
  };

} // namespace Calcboy

#endif
