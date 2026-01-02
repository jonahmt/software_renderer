#include "mesh.h"

#include <gtest/gtest.h>

namespace softrender {

namespace {
Vector<3> kPosition1 = {1, 1, 1};
Vector<3> kPosition2 = {2, 2, 2};
Vector<3> kPosition3 = {3, 3, 3};

Vector<2> kUV1 = {0.4, 0.4};
Vector<2> kUV2 = {0.5, 0.5};
Vector<2> kUV3 = {0.6, 0.6};

Vector<3> kNormal1 = {7, 7, 7};
Vector<3> kNormal2 = {8, 8, 8};
Vector<3> kNormal3 = {9, 9, 9};
}  // namespace

TEST(MeshTest, Basic) {
  Mesh mesh;
  EXPECT_EQ(mesh.GetPositions().size(), 0);
  EXPECT_EQ(mesh.GetUVs().size(), 0);
  EXPECT_EQ(mesh.GetNormals().size(), 0);
  EXPECT_EQ(mesh.GetIndices().size(), 0);
}

TEST(MeshTest, Vertices) {
  Mesh mesh;
  uint32_t v1 = mesh.AddVertex(kPosition1, kUV1, kNormal1);
  uint32_t v2 = mesh.AddVertex(kPosition2, kUV2, kNormal2);

  EXPECT_EQ(mesh.GetPositions().size(), 2);
  EXPECT_EQ(mesh.GetUVs().size(), 2);
  EXPECT_EQ(mesh.GetNormals().size(), 2);
  EXPECT_EQ(mesh.GetIndices().size(), 0);

  EXPECT_EQ(mesh.GetVertexPosition(v1), kPosition1);
  EXPECT_EQ(mesh.GetVertexUV(v1), kUV1);
  EXPECT_EQ(mesh.GetVertexNormal(v1), kNormal1);
  EXPECT_EQ(mesh.GetVertexPosition(v2), kPosition2);
  EXPECT_EQ(mesh.GetVertexUV(v2), kUV2);
  EXPECT_EQ(mesh.GetVertexNormal(v2), kNormal2);

  EXPECT_EQ(mesh.GetPositions()[v1], kPosition1);
  EXPECT_EQ(mesh.GetUVs()[v1], kUV1);
  EXPECT_EQ(mesh.GetNormals()[v1], kNormal1);
  EXPECT_EQ(mesh.GetPositions()[v2], kPosition2);
  EXPECT_EQ(mesh.GetUVs()[v2], kUV2);
  EXPECT_EQ(mesh.GetNormals()[v2], kNormal2);
}

TEST(MeshTest, VertexIndicesIncreaseIncrementally) {
  Mesh mesh;
  int i = 0;
  for (; i < 100; i++) {
    EXPECT_EQ(mesh.AddVertex(kPosition1, kUV1, kNormal1), i);
  }
}

TEST(MeshTest, SingleTriangle) {
  Mesh mesh;
  uint32_t v1 = mesh.AddVertex(kPosition1, kUV1, kNormal1);
  uint32_t v2 = mesh.AddVertex(kPosition2, kUV2, kNormal2);
  uint32_t v3 = mesh.AddVertex(kPosition3, kUV3, kNormal3);

  mesh.AddTriangle(v1, v2, v3);

  EXPECT_EQ(mesh.GetIndices().size(), 3);
  EXPECT_EQ(mesh.GetIndices()[0], v1);
  EXPECT_EQ(mesh.GetIndices()[1], v2);
  EXPECT_EQ(mesh.GetIndices()[2], v3);
}

TEST(MeshTest, OverlappingTriangles) {
  Mesh mesh;
  uint32_t v1 = mesh.AddVertex(kPosition1, kUV1, kNormal1);
  uint32_t v2 = mesh.AddVertex(kPosition2, kUV2, kNormal2);
  uint32_t v3 = mesh.AddVertex(kPosition3, kUV3, kNormal3);

  // Use same vertices for both triangles, just in a different order.
  mesh.AddTriangle(v1, v2, v3);
  mesh.AddTriangle(v3, v2, v1);

  EXPECT_EQ(mesh.GetIndices().size(), 6);
  EXPECT_EQ(mesh.GetIndices()[0], v1);
  EXPECT_EQ(mesh.GetIndices()[1], v2);
  EXPECT_EQ(mesh.GetIndices()[2], v3);
  EXPECT_EQ(mesh.GetIndices()[3], v3);
  EXPECT_EQ(mesh.GetIndices()[4], v2);
  EXPECT_EQ(mesh.GetIndices()[5], v1);
}

TEST(MeshDeathTest, GetVertexAttributesWithInvalidIndex) {
  Mesh mesh;
  uint32_t v1 = mesh.AddVertex(kPosition1, kUV1, kNormal1);
  uint32_t v2 = mesh.AddVertex(kPosition2, kUV2, kNormal2);
  uint32_t v3 = mesh.AddVertex(kPosition3, kUV3, kNormal3);

  // Cast results to void to avoid compiler warnings about unused results.
  EXPECT_DEBUG_DEATH((void)mesh.GetVertexPosition(v1 + 1), "Assertion");
  EXPECT_DEBUG_DEATH((void)mesh.GetVertexUV(v1 + 1), "Assertion");
  EXPECT_DEBUG_DEATH((void)mesh.GetVertexNormal(v1 + 1), "Assertion");
}

TEST(MeshDeathTest, AddTriangleWithInvalidVertexIndex) {
  Mesh mesh;
  uint32_t v1 = mesh.AddVertex(kPosition1, kUV1, kNormal1);
  uint32_t v2 = mesh.AddVertex(kPosition2, kUV2, kNormal2);
  uint32_t v3 = mesh.AddVertex(kPosition3, kUV3, kNormal3);

  EXPECT_DEBUG_DEATH(mesh.AddTriangle(v1, v2, v3 + 1), "Assertion");
}

}  // namespace softrender