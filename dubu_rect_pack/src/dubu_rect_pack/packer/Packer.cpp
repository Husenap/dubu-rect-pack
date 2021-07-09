#include "Packer.hpp"

#include <ranges>

namespace dubu::rect_pack {

Packer::Packer(int width, int height) {
    mSpaces.emplace_back(0, 0, width, height);
}

std::optional<Rect> Packer::Pack(Size rectangle) {
    for (auto it = mSpaces.crbegin(); it != mSpaces.crend(); ++it) {
        auto& space = *it;

        if (!space.CanFitRect(rectangle)) {
            continue;
        }

        const auto [occupied, newSpaces] = space.Split(rectangle);

        mSpaces.erase(it.base() - 1);

        std::move(std::begin(newSpaces),
                  std::end(newSpaces),
                  std::back_inserter(mSpaces));

        std::sort(std::begin(mSpaces),
                  std::end(mSpaces),
                  [](const Space& lhs, const Space& rhs) {
                      return lhs.Area() > rhs.Area();
                  });

        return occupied;
    }

    return std::nullopt;
}

}  // namespace dubu::rect_pack