#pragma once

#include "math.h"

namespace softrender {

// Camera class that defines the view and projection for rendering a 3D scene.
// Uses a look-at camera model with perspective projection.
class Camera {
 public:
  // Constructs a camera with the specified parameters.
  Camera(const Vector<3>& position, const Vector<3>& look_at,
         const Vector<3>& up, Real fov_degrees, Real aspect_ratio,
         Real near_plane, Real far_plane);

  // Returns the view matrix that transforms world space coordinates to camera
  // space.
  [[nodiscard]] Matrix<4, 4> GetViewMatrix() const;
  // Returns the projection matrix that transforms camera space coordinates to
  // clip space.
  [[nodiscard]] Matrix<4, 4> GetProjectionMatrix() const;

  // Sets the camera position in world space.
  void SetPosition(const Vector<3>& position);
  // Sets the point in world space that the camera is looking at.
  void SetLookAt(const Vector<3>& look_at);
  // Sets the up vector defining the camera's orientation.
  void SetUp(const Vector<3>& up);
  // Sets the vertical field of view in degrees.
  void SetFOV(Real fov_degrees);
  // Sets the aspect ratio (width / height) of the viewport.
  void SetAspectRatio(Real aspect_ratio);
  // Sets the distance to the near clipping plane.
  void SetNearPlane(Real near_plane);
  // Sets the distance to the far clipping plane.
  void SetFarPlane(Real far_plane);

  // Returns the camera position in world space.
  [[nodiscard]] const Vector<3>& GetPosition() const;
  // Returns the point in world space that the camera is looking at.
  [[nodiscard]] const Vector<3>& GetLookAt() const;
  // Returns the up vector defining the camera's orientation.
  [[nodiscard]] const Vector<3>& GetUp() const;
  // Returns the vertical field of view in degrees.
  [[nodiscard]] Real GetFOV() const;
  // Returns the aspect ratio (width / height) of the viewport.
  [[nodiscard]] Real GetAspectRatio() const;
  // Returns the distance to the near clipping plane.
  [[nodiscard]] Real GetNearPlane() const;
  // Returns the distance to the far clipping plane.
  [[nodiscard]] Real GetFarPlane() const;

 private:
  // Position of the camera in world space.
  Vector<3> position_;
  // Point in world space that the camera is looking at.
  Vector<3> look_at_;
  // Up vector defining the camera's orientation.
  Vector<3> up_;
  // Vertical field of view in degrees.
  Real fov_degrees_;
  // Aspect ratio (width / height) of the viewport.
  Real aspect_ratio_;
  // Distance to the near clipping plane.
  Real near_plane_;
  // Distance to the far clipping plane.
  Real far_plane_;
};

}  // namespace softrender
