#include <igl/opengl/glfw/Viewer.h>

// #include "helper.h"

#include <iostream>

int TOTAL_POINTS = 10000;

const double bc_step = 1.0 / (double)TOTAL_POINTS;

void deCasteljau(
    const Eigen::Ref<const Eigen::Vector2d> p0,
    const Eigen::Ref<const Eigen::Vector2d> p1,
    const Eigen::Ref<const Eigen::Vector2d> p2,
    const Eigen::Ref<const Eigen::Vector2d> p3,
    double t,
    Eigen::Ref<Eigen::Vector2d> p_res
) {
    if (t > 1 || t < 0) {
        printf("Wrong input t: %f\n", t);
        return;
    }
    // First iteration
    Eigen::Vector2d p01 = (1-t) * p0 + t * p1;
    Eigen::Vector2d p12 = (1-t) * p1 + t * p2;
    Eigen::Vector2d p23 = (1-t) * p2 + t * p3;

    // Second iteration
    Eigen::Vector2d p0112 = (1-t) * p01 + t * p12;
    Eigen::Vector2d p1223 = (1-t) * p12 + t * p23;

    // Last iteration
    p_res = (1-t) * p0112 + t * p1223;
}

void compute_all_points(
    const Eigen::Ref<const Eigen::Vector2d> p0,
    const Eigen::Ref<const Eigen::Vector2d> p1,
    const Eigen::Ref<const Eigen::Vector2d> p2,
    const Eigen::Ref<const Eigen::Vector2d> p3,
    Eigen::MatrixXd& points
) {
    assert(points.rows() == TOTAL_POINTS && points.cols() == 3);
    for (int ind = 0; ind < TOTAL_POINTS; ++ind) {
        Eigen::Vector2d cur_p;
        cur_p << 0., 0.;
        deCasteljau(p0, p1, p2, p3, (double)ind * bc_step, cur_p);
        // std::cout << cur_p << ", ";
        // std::cout << "curp0: " << cur_p(0) << ", curp1: " << cur_p(1) << "///";
        points.row(ind) << cur_p(0), cur_p(1), 0.;
        // std::cout << "1curp0: " << cur_p(0) << ", 1curp1: " << cur_p(1) << "///";
        // std::cout << points.row(ind) << ";;;";
    }
}

int main(int argc, char *argv[])
{
  // Inline mesh of a cube
  const Eigen::MatrixXd V= (Eigen::MatrixXd(8,3)<<
    0.0,0.0,0.0,
    0.0,0.0,1.0,
    0.0,1.0,0.0,
    0.0,1.0,1.0,
    1.0,0.0,0.0,
    1.0,0.0,1.0,
    1.0,1.0,0.0,
    1.0,1.0,1.0).finished();
  const Eigen::MatrixXi F = (Eigen::MatrixXi(12,3)<<
    1,7,5,
    1,3,7,
    1,4,3,
    1,2,4,
    3,8,7,
    3,4,8,
    5,7,8,
    5,8,6,
    1,5,6,
    1,6,2,
    2,6,8,
    2,8,4).finished().array()-1;

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  // viewer.data().set_mesh(V, F);
  // viewer.data().set_face_based(true);
  // int rws = V.rows();
  // Eigen::MatrixXd pts1 = V.topRows(rws-1);
  // Eigen::MatrixXd pts2 = V.bottomRows(rws-1);
  // viewer.data().add_edges(pts1, pts2, Eigen::RowVector3d(1,0,0));
  Eigen::MatrixXd control_points = (Eigen::MatrixXd(2, 4) << 
          -0.1, 0.2, 0.3, 1.8,
          -0.1, 0.5, 0.8, 0.2).finished();
  Eigen::MatrixXd plot_points(TOTAL_POINTS, 3);
  compute_all_points(control_points.col(0),
                     control_points.col(1),
                     control_points.col(2),
                     control_points.col(3),
                     plot_points);
  std::cout << plot_points.row(10) << std::endl;
  std::cout << plot_points.row(11) << std::endl;

  int rws = plot_points.rows();
  Eigen::MatrixXd pts1 = plot_points.topRows(rws-1);
  Eigen::MatrixXd pts2 = plot_points.bottomRows(rws-1);
  viewer.data().add_edges(pts1, pts2, Eigen::RowVector3d(1, 0, 0));
  // viewer.data().show_lines = false;
  viewer.launch();
}
