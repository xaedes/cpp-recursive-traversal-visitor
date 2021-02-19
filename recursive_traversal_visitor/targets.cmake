cmake_minimum_required(VERSION 3.8)

add_library(
    ${PROJECT_NAME} 
    STATIC
    
    include/${PROJECT_NAME}/version.h
    include/${PROJECT_NAME}/recursive_traversal_visitor.h
    
    src/recursive_traversal_visitor.cpp
)

# target_link_libraries(${PROJECT_NAME} PUBLIC glm)

# target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})
# target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_executable(${PROJECT_NAME}_app src/main.cpp)

target_link_libraries(${PROJECT_NAME}_app PRIVATE ${PROJECT_NAME})

if (TARGET Catch2::Catch2)
    # CatchMain library containing Catch2 main function
    # each test module gets a seperate test program.
    # a test program containing all tests will be built by linking against all test modules.
    set(
        TEST_MODULES
    )
    set(
        BENCHMARK_MODULES
    )
    include(CTest)
    include(Catch)

    set(NAME_ALL_TESTS "test_all_${PROJECT_NAME}")
    set(NAME_ALL_BENCHMARKS "benchmark_all_${PROJECT_NAME}")
    set(NAME_CATCH_MAIN "${PROJECT_NAME}_CatchMain")
    set(NAME_CATCH_MAIN_BENCHMARK "${PROJECT_NAME}_CatchMainBenchmark")
    add_library( ${NAME_CATCH_MAIN} OBJECT src/catch_main.cpp )
    target_link_libraries(${NAME_CATCH_MAIN} PUBLIC Catch2::Catch2)

    add_library( ${NAME_CATCH_MAIN_BENCHMARK} OBJECT src/catch_main.cpp )
    target_compile_definitions(${NAME_CATCH_MAIN_BENCHMARK} PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING) 
    target_link_libraries(${NAME_CATCH_MAIN_BENCHMARK} PUBLIC Catch2::Catch2)

    add_executable(${NAME_ALL_TESTS})
    target_link_libraries(${NAME_ALL_TESTS} PUBLIC ${NAME_CATCH_MAIN})

    add_executable(${NAME_ALL_BENCHMARKS})
    target_link_libraries(${NAME_ALL_BENCHMARKS} PUBLIC ${NAME_CATCH_MAIN_BENCHMARK})
    target_compile_definitions(${NAME_ALL_BENCHMARKS} PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING) 

    foreach(NAME ${TEST_MODULES})
        add_library("${NAME}_obj" OBJECT tests/${NAME}.cpp)
        target_link_libraries(${NAME}_obj PUBLIC ${PROJECT_NAME})
        target_link_libraries(${NAME}_obj PUBLIC Catch2::Catch2)
        target_link_libraries(${NAME_ALL_TESTS} PUBLIC ${NAME}_obj)
        add_executable(${NAME})
        target_link_libraries(${NAME} PUBLIC ${NAME_CATCH_MAIN})
        target_link_libraries(${NAME} PUBLIC ${NAME}_obj)
        catch_discover_tests(${NAME})
    endforeach()
    catch_discover_tests(${NAME_ALL_TESTS})

    foreach(NAME ${BENCHMARK_MODULES})
        add_library("${NAME}_obj" OBJECT benchmarks/${NAME}.cpp)
        target_link_libraries(${NAME}_obj PUBLIC ${PROJECT_NAME})
        target_link_libraries(${NAME}_obj PUBLIC Catch2::Catch2)
        target_link_libraries(${NAME_ALL_BENCHMARKS} PUBLIC ${NAME}_obj)
        add_executable(${NAME})
        # target_compile_definitions(${NAME} PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING) 
        target_link_libraries(${NAME} PUBLIC ${NAME_CATCH_MAIN_BENCHMARK})
        target_link_libraries(${NAME} PUBLIC ${NAME}_obj)
        catch_discover_tests(${NAME})
    endforeach()
    catch_discover_tests(${NAME_ALL_BENCHMARKS})
else()
    message("Catch2::Catch2 not found, won't build tests.")
endif()
