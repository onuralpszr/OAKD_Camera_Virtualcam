cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)

# Add depthai-core dependency
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/depthai-core EXCLUDE_FROM_ALL)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(include)

project(DepthAiWebcam)
add_executable(DepthAiWebcam main.cpp)

# Link with libraries
target_link_libraries(DepthAiWebcam depthai::opencv ${OpenCV_LIBS})

# Set compiler features (c++17)
set_property(TARGET ${TARGET_CORE_NAME} PROPERTY CXX_STANDARD 17)

