set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(lus_tests.app
    main.cc
)

target_link_libraries(lus_tests.app
    lus
    lus_io
    lus_lexer
    lus_est
    lus_tui
)

