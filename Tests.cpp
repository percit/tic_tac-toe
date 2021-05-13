#include "Game.h"
#include "catch/catch.hpp"

TEST_CASE("Game"){
    SECTION("IsMoveAllowed") {
        Game m(3);
        m.fill();
        m(1, 1) = 'x';
        REQUIRE(m.isMoveAllowed(1, 1) == false);
    }
    SECTION("AddMove"){
        Game g(3);
        Player player1(1, 'X');
        g.fill();
        g.addMove(1, 1, player1);
        REQUIRE(g(1, 1) == 'X');
    }
    SECTION("Fill/Clear"){
        Game g(3);
        g.fill();
        g(1,1) = 'X';
        REQUIRE(g(0, 0) == '-');
        g.clear();
        REQUIRE(g(0, 0) == '-');
    }
    SECTION("AddSignToMatrix"){
        Game g(3);
        g.fill();
        g(1,1) = 'X';
        REQUIRE(g(1, 1) == 'X');
    }
}

TEST_CASE("Winner"){
    SECTION("Poziomy"){                 // X X X
        Game g(3);          // - - -
        g.fill();                        // - - -
        Player player1(1, 'X');
        g.addMove(0,0, player1);
        g.addMove(0,1, player1);
        g.addMove(0,2, player1);
        REQUIRE(g.Winner() == 1);
    }

    SECTION("Pionowy"){                  // X - -
        Game g(3);           // X - -
        g.fill();                         // X - -
        Player player1(1, 'X');
        g.addMove(0,0, player1);
        g.addMove(1,0, player1);
        g.addMove(2,0, player1);
        REQUIRE(g.Winner() == 1);
    }

    SECTION("diagnonal1"){                 // X - -
        Game g(3);             // - X -
        g.fill();                          // - - X
        Player player1(1, 'X');
        g.addMove(0,0, player1);
        g.addMove(1,1, player1);
        g.addMove(2,2, player1);
        REQUIRE(g.Winner() == 1);
    }
    SECTION("diagnonal2"){                 // - - X
        Game g(3);             // - X -
        g.fill();                          // X - -
        Player player1(1, 'X');
        g.addMove(0,2, player1);
        g.addMove(1,1, player1);
        g.addMove(2,0, player1);
        REQUIRE(g.Winner() == 1);
    }

}

TEST_CASE("Matrix"){
    SECTION("AmountOfMoves") {
        Matrix m(3, 3);
        m.setMoves(5);
        REQUIRE(m.getMoves() == 5);
    }
}

