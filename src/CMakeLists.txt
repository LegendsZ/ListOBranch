set(LISTOBRANCH_SOURCES listobranch.cpp)

if (LISTOBRANCH_BUILD_SHARED)
    add_library(listobranch SHARED ${LISTOBRANCH_SOURCES})
else()
    add_library(listobranch STATIC ${LISTOBRANCH_SOURCES})
endif()

target_include_directories(listobranch PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Handle export macros for cross-platform shared libs
target_compile_definitions(listobranch PRIVATE LISTOBRANCH_EXPORTS)
