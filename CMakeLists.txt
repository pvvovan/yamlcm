cmake_minimum_required(VERSION 4.3.3)
project (yamldemo LANGUAGES CXX)

add_subdirectory(yaml)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} yaml::markup)

if(MSVC) # Intended to set up file tabs in Visual Studio
    set(HPP_FILES
        yaml/indent.hpp
        yaml/markup.hpp
    )

    target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET HEADERS
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES ${HPP_FILES})

    set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set(CMAKE_SUPPRESS_REGENERATION OFF)

    source_group(
        TREE ${PROJECT_SOURCE_DIR}
        PREFIX Headers
        FILES ${HPP_FILES})
endif()
