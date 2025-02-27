cmake_minimum_required(VERSION 3.30.0)
project(star VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wno-unused-value)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")
file(GLOB_RECURSE Sources "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.cxx" "${SRC_DIR}/*.cc")
set(MainSources "${Sources}")
list(FILTER MainSources INCLUDE REGEX "main.*\\.(cpp|cc|cxx)")

#auto create executable
foreach(item IN LISTS MainSources)
    string(REGEX REPLACE "/[^/]+$" "" FOLDER "${item}")
    string(REGEX MATCH "[^/]+$" NAME "${FOLDER}")
    string(REGEX REPLACE "/${NAME}$" "" PARENT "${FOLDER}")
    string(REGEX REPLACE "^${SRC_DIR}[/]?" "" PATH "${PARENT}")
    string(REGEX REPLACE "${SRC_DIR}" "${INCLUDES_DIR}" Header_Dir "${FOLDER}")

    set(active_sources "")
    foreach(item1 IN LISTS Sources)
        string(REGEX REPLACE "/[^/]+$" "" SUBS "${item1}")
        if("${FOLDER}" MATCHES "${SUBS}.*")
            list(APPEND active_sources "${item1}")
        endif()
    endforeach()

    add_executable("${NAME}" "${active_sources}")
    target_include_directories("${NAME}" PUBLIC "${Header_Dir}")
    target_include_directories("${NAME}" PUBLIC "${INCLUDES_DIR}")
    message("${INCLUDES_DIR}")
    if(NOT ("${PATH}" STREQUAL ""))
        set_target_properties("${NAME}" PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/"${PATH}"
        )
    endif()


    #message("${SRC_DIR}/${PATH}")
endforeach()

#message("erym\n" ${folder1})