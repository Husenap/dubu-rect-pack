#include <gtest/gtest.h>

#include <dubu_rect_pack/dubu_rect_pack.hpp>

TEST(dubu_rect_pack, pack_single_rect) {
    dubu::rect_pack::Packer packer(256, 256);
