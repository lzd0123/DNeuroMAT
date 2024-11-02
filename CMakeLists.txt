cmake_minimum_required(VERSION 3.22)
project(DNeuroMAT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(VAA3DPATH  E:/Neure) # the installation path of Vaa3D

find_package(Qt4 REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

aux_source_directory(./src/cpp SRC_CPP)
file(GLOB QPropertyCPP ${QT_INCLUDE_DIR}/../tools/shared/qtpropertybrowser/*.cpp)
file(GLOB QRC_FILES *.qrc)

set(SRC_CPP ${SRC_CPP} ${VAA3DPATH}/v3d_external/v3d_main/basic_c_fun/v3d_message.cpp
    ${VAA3DPATH}/v3d_external/v3d_main/basic_c_fun/basic_surf_objs.cpp
    ${QPropertyCPP}
    )

include_directories(
    ${PROJECT_SOURCE_DIR}/src/cpp
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDE_DIR}/../tools/shared/qtpropertybrowser
    ${VAA3DPATH}/v3d_external/v3d_main/basic_c_fun
)

set(CMAKE_BUILD_TYPE RELEASE)
if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${VAA3DPATH}/v3d_external/bin/plugins/${PROJECT_NAME}/)
endif (WIN32)
if (UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${VAA3DPATH}/v3d_external/bin/plugins/${PROJECT_NAME}/)
endif (UNIX)
add_library(${PROJECT_NAME} SHARED ${SRC_CPP} ${QRC_FILES})
target_link_libraries(${PROJECT_NAME} Qt4::QtCore Qt4::QtGui)