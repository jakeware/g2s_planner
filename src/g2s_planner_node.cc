// Copyright 2017 Massachusetts Institute of Technology

#include <csignal>

#include "ros/ros.h"

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

}  // namespace g2s_planner

int main(int argc, char **argv) {
  ros::init(argc, argv, "g2s_planner");

  // Install signal handler.
  std::signal(SIGINT, g2s_planner::signal_handler);

  g2s_planner::G2SPlannerRos g2s_planner_ros(&g2s_planner::stop_signal_);
  ROS_INFO("Starting loop");
  g2s_planner_ros.Run();

  return 0;
}
