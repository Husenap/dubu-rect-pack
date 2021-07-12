set(target_name "dubu_rect_pack")

set(src_precompiled
    "src/dubu_rect_pack/precompiled.hpp")

set(src_packer
    "src/dubu_rect_pack/packer/Packer.cpp"
    "src/dubu_rect_pack/packer/Packer.hpp"
    "src/dubu_rect_pack/packer/Space.cpp"
    "src/dubu_rect_pack/packer/Space.hpp"
    "src/dubu_rect_pack/packer/Types.hpp")

set(src_dubu_rect_pack
    "src/dubu_rect_pack/dubu_rect_pack.hpp")

set(src_files
    ${src_precompiled}
    ${src_packer}
    ${src_dubu_rect_pack})

# Project
add_library(${target_name} STATIC ${src_files})
add_library(dubu::rect_pack ALIAS ${target_name})
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings)

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_precompile_headers(${target_name} PUBLIC ${src_precompiled})

auto_group_sources(src_files ${CMAKE_CURRENT_SOURCE_DIR})
source_group("src/precompiled" REGULAR_EXPRESSION "cmake_pch\.[ch]xx")

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})
