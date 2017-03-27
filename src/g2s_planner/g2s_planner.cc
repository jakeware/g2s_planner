// Copyright 2017 Massachusetts Institute of Technology

#include "g2s_planner/g2s_planner.h"

namespace g2s_planner {

G2SPlanner::G2SPlanner(volatile std::sig_atomic_t* stop_signal_ptr, G2SPlannerParams& params)
  : stop_signal_ptr_(stop_signal_ptr),
    params_(params) {
}

G2SPlanner::~G2SPlanner() {
  if (thread_.joinable()) {
    thread_.join();
  }
}

void G2SPlanner::Spin() {
  while (!(*stop_signal_ptr_)) {
    // do stuff
  }
}

void G2SPlanner::Run() {
  fprintf(stderr, "G2SPlanner::Run");

  thread_ = std::thread(&G2SPlanner::Spin, this);
}

}  // namespace g2s_planner
