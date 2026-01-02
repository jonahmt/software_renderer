#include "texture.h"

#include <gtest/gtest.h>

namespace softrender {

TEST(TextureTest, Basic) {
  const int width = 10;
  const int height = 20;
  Texture tex(width, height);

  EXPECT_EQ(tex.GetWidth(), width);
  EXPECT_EQ(tex.GetHeight(), height);
}

TEST(TextureTest, SetAndGetPixel) {
  Texture tex(2, 2);
  uint32_t color_1 = 0xAABBCCDD;
  uint32_t color_2 = 0x11223344;

  tex.SetPixel(0, 0, color_1);
  tex.SetPixel(1, 1, color_2);

  EXPECT_EQ(tex.GetPixel(0, 0), color_1);
  EXPECT_EQ(tex.GetPixel(1, 1), color_2);
}

TEST(TextureDeathTest, SetPixelWithInvalidCoordinates) {
  Texture tex(2, 2);
  EXPECT_DEBUG_DEATH(tex.SetPixel(-1, 0, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(tex.SetPixel(0, -1, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(tex.SetPixel(2, 0, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(tex.SetPixel(0, 2, 0x00000000), "Assertion");
}

TEST(TextureDeathTest, GetPixelWithInvalidCoordinates) {
  Texture tex(2, 2);
  // Cast results to void to avoid compiler warnings about unused results.
  EXPECT_DEBUG_DEATH((void)tex.GetPixel(-1, 0), "Assertion");
  EXPECT_DEBUG_DEATH((void)tex.GetPixel(0, -1), "Assertion");
  EXPECT_DEBUG_DEATH((void)tex.GetPixel(2, 0), "Assertion");
  EXPECT_DEBUG_DEATH((void)tex.GetPixel(0, 2), "Assertion");
}
}  // namespace softrender
