#include "helper.h"

#include <stdio.h>
#include <Eigen/Core>

const int TOTAL_POINTS = 1000;
// const double bc_step = 1.0 / (double)TOTAL_POINTS;

// void deCasteljau(
//     const Eigen::Ref<const Eigen::Vector2d> p0,
//     const Eigen::Ref<const Eigen::Vector2d> p1,
//     const Eigen::Ref<const Eigen::Vector2d> p2,
//     const Eigen::Ref<const Eigen::Vector2d> p3,
//     double t,
//     Eigen::Ref<Eigen::Vector2d> p_res
// ) {
//     if (t > 1 || t < 0) {
//         printf("Wrong input t: %f\n", t);
//         return;
//     }
//     // First iteration
//     Eigen::Vector2d p01 = (1-t) * p0 + t * p1;
//     Eigen::Vector2d p12 = (1-t) * p1 + t * p2;
//     Eigen::Vector2d p23 = (1-t) * p2 + t * p3;

//     // Second iteration
//     Eigen::Vector2d p0112 = (1-t) * p01 + t * p12;
//     Eigen::Vector2d p1223 = (1-t) * p12 + t * p23;

//     // Last iteration
//     p_res = (1-t) * p0112 + t * p1223;
// }

// void compute_all_points(
//     const Eigen::Ref<const Eigen::Vector2d> p0,
//     const Eigen::Ref<const Eigen::Vector2d> p1,
//     const Eigen::Ref<const Eigen::Vector2d> p2,
//     const Eigen::Ref<const Eigen::Vector2d> p3,
//     Eigen::MatrixXd& points
// ) {
//     assert(points.rows() == TOTAL_POINTS && points.cols() == 3);
//     for (int ind = 0; ind < TOTAL_POINTS; ++ind) {
//         Eigen::Vector2d cur_p;
//         cur_p << 0., 0.;
//         deCasteljau(p0, p1, p2, p3, ind * bc_step, cur_p);
//         points.row(ind) << (cur_p(0), cur_p(1), 0.);
//     }
// }
