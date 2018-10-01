cmake_minimum_required (VERSION 3.7)

project(UEM_K-Means_Clusterer)

set(UEM_K-Means_Clusterer MAJOR 0.1)
set(UEM_K-Means_Clusterer MINOR 1)

set(FLTK_DIR ./libs/fltk-1.3.4-2/build/)
find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS})


set(CMAKE_CXX_EXTENSIONS 11)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(HEADERS "include/Cluster.hpp"
            "include/Point.hpp"
            "include/KMeans.hpp"
            "include/KmeansReader.hpp"
            "include/KmeansGui.hpp")

set(SOURCES "src/Cluster.cpp"
            "src/KMeans.cpp"
            "src/Point.cpp"
            "src/KmeansReader.cpp"
            "src/KmeansGui.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_executable(kmeans "main.cpp" ${SOURCES} ${HEADERS} ${FLTK_INCLUDE_DIRS})
target_link_libraries(kmeans fltk)

