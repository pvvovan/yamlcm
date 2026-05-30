project (yamlmarkup LANGUAGES CXX)

add_library(yamlmarkup INTERFACE)
add_library(yaml::markup ALIAS yamlmarkup)
target_compile_features(yamlmarkup INTERFACE cxx_std_26)
target_compile_options(yamlmarkup INTERFACE --reflection)

set(SRC
    indent.hpp
    markup.hpp
)

# Intended to set up file tabs in Visual Studio
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${SRC}
)

target_sources(yamlmarkup INTERFACE
    FILE_SET HEADERS FILES
        ${SRC}
)
