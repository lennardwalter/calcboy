#include "calcboy_view.h"

namespace Calcboy
{

  CalcboyView::CalcboyView() : View()
  {
  }

  void CalcboyView::drawRect(KDContext *ctx, KDRect rect) const
  {
    ctx->fillRect(bounds(), KDColorBlack);
  }
} // namespace Calcboy