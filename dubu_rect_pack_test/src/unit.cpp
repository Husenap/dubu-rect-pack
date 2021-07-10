#include <dubu_rect_pack/dubu_rect_pack.hpp>
#include <gtest/gtest.h>

using namespace dubu::rect_pack;

TEST(dubu_rect_pack, pack_single_rect) {
    {
        dubu::rect_pack::Packer packer(256, 256);
        EXPECT_EQ(packer.Pack({256, 256}), (Rect{0, 0, 256, 256}));
    }
    {
        dubu::rect_pack::Packer packer(256, 256);
        EXPECT_EQ(packer.Pack({100, 100}), (Rect{0, 0, 100, 100}));
    }
    {
        dubu::rect_pack::Packer packer(256, 256);
        EXPECT_EQ(packer.Pack({512, 512}), std::nullopt);
    }
}

TEST(dubu_rect_pack, pack_multiple_rects) {
    {
        dubu::rect_pack::Packer packer(256, 256);
        EXPECT_EQ(packer.Pack({100, 100}), (Rect{0, 0, 100, 100}));
        EXPECT_EQ(packer.Pack({100, 100}), (Rect{100, 0, 100, 100}));
        EXPECT_EQ(packer.Pack({1000, 100}), std::nullopt);
        EXPECT_EQ(packer.Pack({56, 100}), (Rect{200, 0, 56, 100}));
    }
}
