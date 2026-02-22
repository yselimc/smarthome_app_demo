# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "201projedeneme_autogen"
  "CMakeFiles\\201projedeneme_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\201projedeneme_autogen.dir\\ParseCache.txt"
  )
endif()
