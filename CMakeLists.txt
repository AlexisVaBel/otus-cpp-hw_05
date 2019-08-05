cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)

project(matrix)

if ($ENV{TRAVIS_BUILD_NUMBER})
 project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
 project(${PROJECT_NAME}  VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)



set (INC_DIRS "." "./matrix")
set (SRC_LIST "main.cpp")
set (SRC_LIST_TEST "./tests/test_starter")


include_directories(${INC_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

add_executable(${PROJECT_NAME}_test ${SRC_LIST_TEST})



set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

set_target_properties(${PROJECT_NAME}_test PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR} ${INC_DIRS}

        )



target_link_libraries(${PROJECT_NAME}_test
    ${Boost_LIBRARIES}
)


install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
include(CPack)

enable_testing()
add_test(matrix_create_empty ${PROJECT_NAME}_test)

add_test(matrix_create_default ${PROJECT_NAME}_test)

add_test(matrix_fill_default ${PROJECT_NAME}_test)

add_test(matrix_fill_some_check_some ${PROJECT_NAME}_test)

add_test(matrix_fill_some_fill_default ${PROJECT_NAME}_test)

add_test(matrix_with_idxs ${PROJECT_NAME}_test)

add_test(matrix_with_three ${PROJECT_NAME}_test)

add_test(matrix_with_six ${PROJECT_NAME}_test)

add_test(matrix_only_filled ${PROJECT_NAME}_test)


