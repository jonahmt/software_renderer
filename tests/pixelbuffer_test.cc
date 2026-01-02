#include "pixelbuffer.h"

#include <gtest/gtest.h>

namespace softrender {

TEST(PixelbufferTest, StoresAndRetrievesPixels) {
  Pixelbuffer pb(5, 4);
  EXPECT_EQ(pb.width, 5);
  EXPECT_EQ(pb.height, 4);

  int x = 0;

  pb.SetPixel(0, 0, 0x00000000);
  pb.SetPixel(1, 1, 0x00000001);
  pb.SetPixel(2, 2, 0x00000002);
  pb.SetPixel(3, 3, 0x00000003);
  EXPECT_EQ(pb.GetPixel(0, 0), 0x00000000);
  EXPECT_EQ(pb.GetPixel(1, 1), 0x00000001);
  EXPECT_EQ(pb.GetPixel(2, 2), 0x00000002);
  EXPECT_EQ(pb.GetPixel(3, 3), 0x00000003);
}

TEST(PixelbufferDeathTest, SetPixelWithInvalidCoordinates) {
  Pixelbuffer pb(2, 2);
  EXPECT_DEBUG_DEATH(pb.SetPixel(-1, 0, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(pb.SetPixel(0, -1, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(pb.SetPixel(2, 0, 0x00000000), "Assertion");
  EXPECT_DEBUG_DEATH(pb.SetPixel(0, 2, 0x00000000), "Assertion");
}

TEST(PixelbufferDeathTest, GetPixelWithInvalidCoordinates) {
  Pixelbuffer pb(2, 2);
  // Cast results to void to avoid compiler warnings about unused results.
  EXPECT_DEBUG_DEATH((void)pb.GetPixel(-1, 0), "Assertion");
  EXPECT_DEBUG_DEATH((void)pb.GetPixel(0, -1), "Assertion");
  EXPECT_DEBUG_DEATH((void)pb.GetPixel(2, 0), "Assertion");
  EXPECT_DEBUG_DEATH((void)pb.GetPixel(0, 2), "Assertion");
}

}  // namespace softrender
