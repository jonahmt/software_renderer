#pragma once

#include <Eigen/Dense>

namespace softrender {

using Real = double;

template <int Rows>
using Vector = Eigen::Matrix<Real, Rows, 1>;

template <int Rows, int Cols>
using Matrix = Eigen::Matrix<Real, Rows, Cols>;

}  // namespace softrender