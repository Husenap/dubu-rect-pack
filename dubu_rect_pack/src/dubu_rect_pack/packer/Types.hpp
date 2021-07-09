#pragma once

#include <cstdint>

namespace dubu::rect_pack {

struct Size {
    const std::uint32_t width  = {};
    const std::uint32_t height = {};
};

struct Rect {
    const std::uint32_t x = {};
    const std::uint32_t y = {};
    const std::uint32_t w = {};
    const std::uint32_t h = {};

    bool operator==(const Rect& rhs) const {
        return x == rhs.x && y == rhs.y && w == rhs.w && h == rhs.h;
    }
};

}  // namespace dubu::rect_pack