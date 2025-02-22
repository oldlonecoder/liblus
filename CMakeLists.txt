cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(liblus 
    VERSION 0.1.0
    DESCRIPTION "A non-standard c++ framework suite of my personal projects"
    LANGUAGES CXX)

OPTION(LUS_CORE         "Build the core sublib..........................[liblus.a]" ON)
OPTION(LUS_IOLISTENER   "Build the IO sublib............................[lus_iolistener.a]" OFF)
OPTION(LUS_LEXER        "Build the lexer sublib.........................[lus_lexer.a]" OFF)
OPTION(LUS_EST          "Build the est (Expression Syntax Tree) sublib..[lus_est.a]" OFF)
OPTION(LUS_TUI          "Build the console ANSI UI  sublib..............[lus_tui.a]" OFF)
OPTION(LUS_TESTS        "Build the tests................................[framework_tests_app/tests.app]" OFF)


if(LUS_CORE)
    message(STATUS "Building liblus.a")
    add_subdirectory(lus)
endif()

if(LUS_IOLISTENER)
    message(STATUS "Building lus_iolistener.a")
    add_subdirectory(lus_iolistener)
endif()

if(LUS_LEXER)
    message(STATUS "Building lus_lexer.a")
    add_subdirectory(lus_lexer)
endif()

if(LUS_EST)
    message(STATUS "Building lus_est.a")
    add_subdirectory(lus_est)
endif()

if(LUS_TUI)
    message(STATUS "Building lus_tui.a")
    add_subdirectory(lus_tui)
endif()

if(LUS_TESTS)
    message(STATUS "framework tests:")
    add_subdirectory(framework_tests_app)
endif()

