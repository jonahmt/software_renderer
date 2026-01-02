#include "texture.h"

#include <gtest/gtest.h>

namespace softrender {

TEST(Texture, Basic) {
  const int width = 10;
  const int height = 20;
  Texture tex(width, height);

  EXPECT_EQ(tex.GetWidth(), width);
  EXPECT_EQ(tex.GetHeight(), height);
}

TEST(Texture, SetAndGetPixel) {
  Texture tex(2, 2);
  uint32_t color_1 = 0xAABBCCDD;
  uint32_t color_2 = 0x11223344;

  tex.SetPixel(0, 0, color_1);
  tex.SetPixel(1, 1, color_2);

  EXPECT_EQ(tex.GetPixel(0, 0), color_1);
  EXPECT_EQ(tex.GetPixel(1, 1), color_2);
}

}  // namespace softrender
