add_executable(abu_debug_tests
    test_debug.cpp
)

target_link_libraries(abu_debug_tests PRIVATE GTest::gtest_main abu::debug)
#target_code_coverage(abu_debug_tests EXCLUDE *gtest*)

if (MSVC)
    target_compile_options(abu_debug_tests PRIVATE /W4 /WX)
else()
    target_compile_options(abu_debug_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_test(abu_debug_tests abu_debug_tests)