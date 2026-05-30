project (yamlmarkup LANGUAGES CXX)

add_library(yamlmarkup INTERFACE)
add_library(yaml::markup ALIAS yamlmarkup)
target_compile_features(yamlmarkup INTERFACE cxx_std_26)
target_compile_options(yamlmarkup INTERFACE --reflection)

target_sources(yamlmarkup INTERFACE
    FILE_SET HEADERS FILES
        markup.hpp)
