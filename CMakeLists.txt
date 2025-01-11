# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(ServerClientExample)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the server executable
add_executable(server server.cpp)

# Add the client executable
add_executable(client client.cpp)

# Link libraries if needed (e.g., pthread)
# target_link_libraries(server PRIVATE pthread)
# target_link_libraries(client PRIVATE pthread)
