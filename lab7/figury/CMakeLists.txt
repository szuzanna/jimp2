
project(figury)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libfigury STATIC ${SOURCE_FILES})
target_include_directories(libfigury PUBLIC .)

add_executable(figury ${SOURCE_FILES} main.cpp)

target_link_libraries(figury libfigury)