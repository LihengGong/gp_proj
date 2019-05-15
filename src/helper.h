#ifndef HELPER_H
#define HELPER_H
#include <Eigen/Core>

void compute_all_points(
    const Eigen::Ref<const Eigen::Vector2d> p0,
    const Eigen::Ref<const Eigen::Vector2d> p1,
    const Eigen::Ref<const Eigen::Vector2d> p2,
    const Eigen::Ref<const Eigen::Vector2d> p3,
    Eigen::MatrixXd& points
);
#endif
