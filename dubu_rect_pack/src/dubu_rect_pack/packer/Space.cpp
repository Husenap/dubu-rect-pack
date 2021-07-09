#include "Space.hpp"

#include <cassert>

namespace dubu::rect_pack {

Space::Space(int left, int top, int right, int bottom)
    : mLeft(left)
    , mTop(top)
    , mRight(right)
    , mBottom(bottom)
    , mWidth(right - left)
    , mHeight(bottom - top) {
    assert(mRight >= mLeft);
    assert(mBottom >= mTop);
}

bool Space::CanFitRect(Rect rectangle) const {
    return (rectangle.width <= mWidth) && (rectangle.height <= mHeight);
}

}  // namespace dubu::rect_pack