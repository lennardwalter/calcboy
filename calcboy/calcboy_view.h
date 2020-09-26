#ifndef CALCBOY_VIEW_H
#define CALCBOY_VIEW_H

#include <escher.h>

namespace Calcboy
{

  class CalcboyView : public View
  {
  public:
    CalcboyView();
    void drawRect(KDContext *ctx, KDRect rect) const override;
  };

} // namespace Calcboy

#endif
