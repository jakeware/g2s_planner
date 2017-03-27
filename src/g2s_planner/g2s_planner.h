// Copyright 2017 Massachusetts Institute of Technology
#pragma once

#include <csignal>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>

#include "g2s_planner/g2s_planner_params.h"

namespace g2s_planner {

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

class G2SPlanner {
 public:
  G2SPlanner(volatile std::sig_atomic_t* stop_signal_ptr_, G2SPlannerParams& params);
  ~G2SPlanner();

  // copy constructors
  G2SPlanner(const G2SPlanner& rhs) = delete;
  G2SPlanner& operator=(const G2SPlanner& rhs) = delete;

  // move constructors
  G2SPlanner(G2SPlanner&& rhs) = delete;
  G2SPlanner& operator=(G2SPlanner&& rhs) = delete;

  void Run();

  volatile std::sig_atomic_t* stop_signal_ptr_;
  G2SPlannerParams params_;

 private:
  void Spin();

  std::thread thread_;
  std::condition_variable condition_;
  std::sig_atomic_t data_ready_;
};
}  // namespace g2s_planner
