include(${PROJECT_SOURCE_DIR}/cmake/FindSDL2TTF.cmake)
find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SRC_DIR}/include ${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
add_executable(2048 core.c game.c)
target_link_libraries(2048 -lm ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY})    
FILE(COPY ${CMAKE_SOURCE_DIR}/res/UbuntuMono-R.ttf DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

