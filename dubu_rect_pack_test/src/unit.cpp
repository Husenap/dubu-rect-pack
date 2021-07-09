#include <dubu_rect_pack/dubu_rect_pack.hpp>
#include <gtest/gtest.h>

TEST(dubu_rect_pack, pack_single_rect) {
    dubu::rect_pack::Packer packer(256, 256);
