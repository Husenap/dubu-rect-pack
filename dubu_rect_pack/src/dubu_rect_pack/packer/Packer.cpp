#include "Packer.hpp"

#include <ranges>

namespace dubu::rect_pack {

Packer::Packer(int width, int height) {
    mSpaces.emplace_back(0, 0, width, height);
}

std::optional<Space> Packer::Pack(Rect rectangle) {
    for (auto& space : mSpaces | std::views::reverse) {
        space.CanFitRect(rectangle);
    }

    return std::nullopt;
}

}  // namespace dubu::rect_pack