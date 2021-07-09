#pragma once

#include "Rect.hpp"

namespace dubu::rect_pack {

class Space {
public:
    bool CanFitRect(Rect rectangle) const;

private:
    int mLeft;
    int mRight;
    int mTop;
    int mBottom;
};

}  // namespace dubu::rect_pack