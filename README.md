[![Build](https://github.com/Husenap/dubu-rect-pack/actions/workflows/build.yml/badge.svg)](https://github.com/Husenap/dubu-rect-pack/actions/workflows/build.yml)

# dubu-rect-pack

C++ library for packing rectangles

## Algorithm

* When packing a new rect: it tries to find the smallest area it fits into.
* When splitting: it prefers the split which yields the biggest area in one of the spaces.

## Example Usage

```cpp
#include <dubu-rect-pack/dubu-rect-pack.hpp>

int main() {
    dubu::rect_pack::Packer packer(256, 256);   // create a space of 256x256
    packer.Pack({100, 100});                    // Rect{0, 0, 100, 100}
    packer.Pack({100, 100});                    // Rect{100, 0, 100, 100}
    packer.Pack({1000, 100});                   // std::nullopt, doesn't fit
    packer.Pack({56, 100});                     // Rect{200, 0, 56, 100}
}
```