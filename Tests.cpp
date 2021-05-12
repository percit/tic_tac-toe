#include "Game.h"
#include "catch/catch.hpp"

TEST_CASE("Game"){
    SECTION("IsMoveAllowed") {
        Game m(3);
        m.fill(); 
        m(1, 1) = 'x';
        REQUIRE(m.isMoveAllowed(1, 1) == false);
    }
    SECTION("Fill/Clear"){
        Game g(3);
        g.fill();
        g(1,1) = 'x';
        REQUIRE(g(0, 0) == '-');
        g.clear();
        REQUIRE(g(0, 0) == '-');
    }
    SECTION("AddSignToMatrix"){
        Game g(3);
        g.fill();
        g(1,1) = 'x';
        REQUIRE(g(1, 1) == 'x');
    }
}

TEST_CASE("Matrix"){
    SECTION("AmountOfMoves") {
        Matrix m(3, 3);
        m.setMoves(5);
        REQUIRE(m.getMoves() == 5);
    }
}

