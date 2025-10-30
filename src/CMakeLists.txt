add_library(listobranch SHARED
    listobranch.cpp
)

target_include_directories(listobranch
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

if(WIN32)
    target_compile_definitions(listobranch PRIVATE LISTOBRANCH_EXPORTS)
endif()