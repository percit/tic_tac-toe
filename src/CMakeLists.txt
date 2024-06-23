add_executable(tic_tac_toe
    Game.cpp
    Game.h
    main.cpp
    matrix.cpp
    matrix.h
)

add_library(tic_tac_toe_lib
    Game.cpp
    Game.h
    matrix.cpp
    matrix.h
)
target_link_libraries(tic_tac_toe tic_tac_toe_lib)