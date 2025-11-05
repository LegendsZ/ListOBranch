add_executable(listobranch_terminal main.cpp)

target_link_libraries(listobranch_terminal PRIVATE listobranch)

target_include_directories(listobranch_terminal
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

add_custom_command(TARGET listobranch_terminal POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:listobranch>
        $<TARGET_FILE_DIR:listobranch_terminal>)