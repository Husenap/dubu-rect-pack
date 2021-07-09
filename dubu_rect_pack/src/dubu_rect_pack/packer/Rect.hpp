#pragma once

namespace dubu::rect_pack {

class Rect {
public:
    explicit Rect(int width, int height);

private:
    int mWidth  = {};
    int mHeight = {};
};

}  // namespace dubu::rect_pack