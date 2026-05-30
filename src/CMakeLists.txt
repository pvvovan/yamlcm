project(yamlmarkup LANGUAGES CXX)

add_library(yamlmarkup INTERFACE)
add_library(yaml::markup ALIAS yamlmarkup)
target_compile_features(yamlmarkup INTERFACE cxx_std_26)
target_compile_options(yamlmarkup INTERFACE --reflection)

set(YAML_HPP_FILES
    yaml/indent.hpp
    yaml/markup.hpp
)

target_sources(yamlmarkup INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES ${YAML_HPP_FILES}
)

set(YAML_HPP_FILES ${YAML_HPP_FILES} PARENT_SCOPE)
