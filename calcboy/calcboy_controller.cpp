#include "calcboy_controller.h"
#include <apps/apps_container.h>

namespace Calcboy
{

  CalcboyController::CalcboyController() : ViewController(nullptr),
                                           m_calcboyView()
  {
  }

  View *CalcboyController::view()
  {
    return &m_calcboyView;
  }

} // namespace Calcboy
