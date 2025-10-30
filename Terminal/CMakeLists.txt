add_executable(listobranch_terminal main.cpp)

target_link_libraries(listobranch_terminal PRIVATE listobranch)

target_include_directories(listobranch_terminal
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
