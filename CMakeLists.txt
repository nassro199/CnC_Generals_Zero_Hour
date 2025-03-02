# Top level project, for old thyme sake :D
project(thyme LANGUAGES C CXX)

# Set where the build results will end up
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Find/Add build dependencies and stubs shared by all projects
if(WIN32 AND ${CMAKE_SIZEOF_VOID_P} EQUAL 4)
    add_subdirectory(Dependencies/BinkStub)
    add_subdirectory(Dependencies/MilesStub)
    add_subdirectory(Dependencies/STLPort)

    link_directories(Dependencies/DX8SDK)
    include_directories(Dependencies/DX8SDK)
elseif(UNIX)
    # Add Linux-specific dependencies here
    find_package(OpenGL REQUIRED)
    # Add other Linux-specific dependencies
endif()

include(FetchContent)
set(GS_OPENSSL FALSE)

FetchContent_Declare(
    gamespy
    GIT_REPOSITORY https://github.com/TheAssemblyArmada/GamespySDK.git
    GIT_TAG        6f83d85d6d2e2d9a430301aeef5134578d0ecfcd
)
FetchContent_MakeAvailable(gamespy)

# Do we want to build extra SDK stuff or just the game binary?
option(THYME_ZEROHOUR_PROJECT "Build Zero Hour code." ON)
option(THYME_GENERALS_PROJECT "Build Generals code." OFF) # TODO

if(NOT THYME_ZEROHOUR_PROJECT AND NOT THYME_GENERALS_PROJECT)
    set(THYME_ZEROHOUR_PROJECT TRUE)
    message("You must select one project to build, building Zero Hour by default.")
endif()

add_feature_info(ZeroHourStuff THYME_ZEROHOUR_PROJECT "Build Zero Hour code")
add_feature_info(GeneralsStuff THYME_GENERALS_PROJECT "Build Generals code")

# Add main build targets
if(THYME_ZEROHOUR_PROJECT)
    add_subdirectory(GeneralsMD)
endif()