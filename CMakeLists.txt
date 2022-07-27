cmake_minimum_required(VERSION 3.0.0)
project(practice VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(practice main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# find_package(PkgConfig)

# pkg_check_modules(ImageMagick REQUIRED Magick++ MagickCore)
find_package(ImageMagick COMPONENTS Magick++ MagickCore)
target_link_libraries("${PROJECT_NAME}"
    PRIVATE
    pthread #thread
    ${ImageMagick_LIBRARIES}
)

target_include_directories("${PROJECT_NAME}"
    PRIVATE 
            ${ImageMagick_INCLUDE_DIRS}
         
)


