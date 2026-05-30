cmake_minimum_required(VERSION 4.3.3)
project (yamltest LANGUAGES CXX)

add_subdirectory(yaml)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.15.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Catch2::Catch2WithMain
    yaml::markup
)

enable_testing()
add_test(NAME YamlTest COMMAND ${PROJECT_NAME})

if(MSVC) # Intended to set up file tabs in Visual Studio
    list(TRANSFORM HPP_FILES PREPEND "yaml/")

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
