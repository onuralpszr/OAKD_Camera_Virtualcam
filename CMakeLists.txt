cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)

# Add depthai-core dependency
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/depthai-core EXCLUDE_FROM_ALL)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(CLI11 CONFIG REQUIRED)
include_directories(${CLI11_DIR}/include)

project(DepthAiWebcam)
add_executable(DepthAiWebcam main.cpp)

# Link with libraries
target_link_libraries(DepthAiWebcam depthai::opencv ${OpenCV_LIBS})

# Set compiler features (c++20)
set_property(TARGET ${TARGET_CORE_NAME} PROPERTY CXX_STANDARD 20)

