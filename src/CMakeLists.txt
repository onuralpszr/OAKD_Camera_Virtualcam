cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add depthai-core dependency
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/depthai-core EXCLUDE_FROM_ALL)
set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/depthai-core PROPERTY SKIP_AUTOUIC ON)
set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/depthai-core PROPERTY SKIP_AUTORCC ON)
set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/depthai-core PROPERTY SKIP_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(DepthAiWebcam VERSION 0.1 LANGUAGES C CXX)

find_package(OpenCV REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        include/ImageWriter.cpp
        include/ImageWriter.h
        include/AppBridge.cpp
        include/AppBridge.h
        include/CameraWorker.cpp
        include/CameraWorker.h)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DepthAiWebcam
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else ()
    add_executable(DepthAiWebcam
            ${PROJECT_SOURCES}
            )
endif ()


# Link with libraries
target_link_libraries(DepthAiWebcam PUBLIC depthai::opencv ${OpenCV_LIBS})
target_link_libraries(DepthAiWebcam PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

# Set compiler features (c++20)
set_property(TARGET ${TARGET_CORE_NAME} PROPERTY CXX_STANDARD 20)

install(TARGETS DepthAiWebcam
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(DepthAiWebcam)
    qt_finalize_executable(DepthAiWebcam)
endif()
