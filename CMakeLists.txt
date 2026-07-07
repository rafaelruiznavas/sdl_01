cmake_minimum_required(VERSION 3.23)

# Definimos el proyecto
project(
    SDLDemo
    VERSION 1.0
    DESCRIPTION "Demo de SDL3"
    LANGUAGES CXX
)

# Configuramos C++ Standard a C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
)

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

if(APPLE)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "@executable_path;@loader_path"
    BUILD_WITH_INSTALL_RPATH TRUE
    MACOSX_RPATH TRUE
  )
elseif(UNIX)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    BUILD_WITH_INSTALL_RPATH TRUE
  )
endif()

if(WIN32)
  set(MATH_LIBRARY "" CACHE STRING "" FORCE)
endif()

# Especificamos que queremos constrir las dependencias de SDL_TTF
set(SDLTTF_VENDORED ON)

# Configuramos una variable para nuestro directorio LIBS
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")

# Agregamos las librerias de SDL desde nuestros submodulos
add_subdirectory(${LIBS_DIR}/SDL)
add_subdirectory(${LIBS_DIR}/SDL_image)
add_subdirectory(${LIBS_DIR}/SDL_ttf)

target_link_libraries(
    ${PROJECT_NAME}
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)