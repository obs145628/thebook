set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++17 -O0 -g")


set(SRC
  src/automata.cc
  src/main.cc
  src/regex.cc
)
add_executable(res ${SRC})
