add_executable(listobranch_gui main.cpp)

target_link_libraries(listobranch_gui PRIVATE listobranch)

target_include_directories(listobranch_gui
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
