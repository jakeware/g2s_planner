// Copyright 2017 Massachusetts Institute of Technology

#include <csignal>

#include "ros/ros.h"
#include "nodelet/nodelet.h"

#include "g2s_planner_ros/g2s_planner_ros.h"

namespace g2s_planner {

volatile std::sig_atomic_t stop_signal_ = 0;

/**
 * We override the default ROS SIGINT handler to set a global variable which
 * tells the other threads to stop.
 */
static void signal_handler(int signal) {
  printf("(g2s_planner) SIGINT received\n");

  // Tell other threads to stop.
  stop_signal_ = 1;

  // Tell ROS to shutdown nodes.
  ros::shutdown();

  return;
}

class G2SPlannerNodelet : public nodelet::Nodelet {
 public:
  G2SPlannerNodelet() = default;
  ~G2SPlannerNodelet() = default;

  G2SPlannerNodelet(const G2SPlannerNodelet& rhs) = delete;
  G2SPlannerNodelet& operator=(const G2SPlannerNodelet& rhs) = delete;

  G2SPlannerNodelet(G2SPlannerNodelet&& rhs) = delete;
  G2SPlannerNodelet& operator=(G2SPlannerNodelet&& rhs) = delete;

  /**
   * \brief Nodelet initialization.
   *
   * Subclasses of nodelet::Nodelet need to override this virtual method.
   * It takes the place of the nodelet constructor.
   */
  virtual void onInit() {
    // Install signal handler.
    std::signal(SIGINT, signal_handler);

    G2SPlannerRos g2s_planner_ros(&stop_signal_);
    NODELET_INFO("Starting loop");
    g2s_planner_ros.Run();

    return;
  }

  // // sigint
  // static volatile std::sig_atomic_t stop_signal_;
};

}  // namespace g2s_planner

// Export as a plugin.
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(g2s_planner::G2SPlannerNodelet, nodelet::Nodelet)
