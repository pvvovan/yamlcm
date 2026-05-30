project(yamlmarkup LANGUAGES CXX)

add_library(yamlmarkup INTERFACE)
add_library(yaml::markup ALIAS yamlmarkup)

set(HPP_FILES
    indent.hpp
    markup.hpp
)

target_sources(yamlmarkup INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES ${HPP_FILES}
)

set(HPP_FILES ${HPP_FILES} PARENT_SCOPE)
