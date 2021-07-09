#pragma once

#include "Rect.hpp"

namespace dubu::rect_pack {

class Space {
public:
    explicit Space(int left, int top, int right, int bottom);

    bool CanFitRect(Rect rectangle) const;

    bool operator==(const Space& rhs) const {
        return mLeft == rhs.mLeft && mTop == rhs.mTop && mRight == rhs.mRight &&
               mBottom == rhs.mBottom;
    }

private:
    int mLeft;
    int mTop;
    int mRight;
    int mBottom;
    int mWidth;
    int mHeight;
};

}  // namespace dubu::rect_pack