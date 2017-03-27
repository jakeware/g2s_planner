# add g2s_planner library
add_library(g2s_planner
  g2s_planner.cc
  g2s_planner_params.cc
  )

target_link_libraries(g2s_planner
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
  )

install(TARGETS g2s_planner
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )
