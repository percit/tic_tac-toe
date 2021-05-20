#include "Game.h"
#include "catch/catch.hpp"


/*
 TEST_CASE("Fibonacci") {
    CHECK(Fibonacci(0) == 1);
    // some more asserts..
    CHECK(Fibonacci(5) == 8);
    // some more asserts..

    // now let's benchmark:
    BENCHMARK("Fibonacci 20") {
        return Fibonacci(20);
    };

    BENCHMARK("Fibonacci 25") {
        return Fibonacci(25);
    };

    BENCHMARK("Fibonacci 30") {
        return Fibonacci(30);
    };

    BENCHMARK("Fibonacci 35") {
        return Fibonacci(35);
    };
}

//return {MinMaxValue, move};
TEST_CASE("MIN_MAX"){
    SECTION("first_test"){
        Game g(3);
        //CHECK( expression )

        int a = ...;
        int b = ...;
        CHECKED_IF( a == b ) {
            // This block is entered when a == b
        } CHECKED_ELSE ( a == b ) {
            // This block is entered when a != b
        }

    }
}
 */

TEST_CASE("winner-rand"){

    SECTION("Rand1"){ //przechodzi?!!!
        Game g(3);
        g.fill();
        g.addMove(0,0, 'X');          // X - -
        // g.addMove(0,1, 'X');        // - - -
        // g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 10);
    }

    SECTION("Rand2"){ //tylko to nie przechodzi
        Game g(3);
        g.fill();
        // g.addMove(0,0, 'X');        // - - -
        g.addMove(1,0, 'X');          // X - -
        //   g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 10);
    }

    SECTION("Rand3"){ //przechodzi?!!!
        Game g(3);
        g.fill();
        // g.addMove(0,0, 'X');        // - - -
        g.addMove(1,1, 'X');          // - X -
        //   g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 10);
    }
}
TEST_CASE("Winner"){
    SECTION("Poziomy3"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'X');        // X X X
        g.addMove(0,1, 'X');        // - - -
        g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 10);
    }
    SECTION("Poziomy5"){
        Game g(5);
        g.fill();
        g.addMove(2,0, 'X');        // - - - - -
        g.addMove(2,1, 'X');        // - - - - -
        g.addMove(2,2, 'X');        // X X X X X
        g.addMove(2,3, 'X');        // - - - - -
        g.addMove(2,4, 'X');        // - - - - -
        REQUIRE(g.Winner() == 10);
    }

    SECTION("Pionowy3"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'X');        // X - -
        g.addMove(1,0, 'X');        // X - -
        g.addMove(2,0, 'X');        // X - -
        REQUIRE(g.Winner() == 10);
    }
    SECTION("Pionowy5"){
        Game g(5);
        g.fill();
        g.addMove(2,0, 'X');        // - - X - -
        g.addMove(2,1, 'X');        // - - X - -
        g.addMove(2,2, 'X');        // - - X - -
        g.addMove(2,3, 'X');        // - - X - -
        g.addMove(2,4, 'X');        // - - X - -
        REQUIRE(g.Winner() == 10);
    }

    SECTION("diagnonal3"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'X');        // X - -
        g.addMove(1,1, 'X');        // - X -
        g.addMove(2,2, 'X');        // - - X
        REQUIRE(g.Winner() == 10);
    }

    SECTION("diagnonal5"){
        Game g(5);
        g.fill();
        g.addMove(0,0, 'X');        // X - - - -
        g.addMove(1,1, 'X');        // - X - - -
        g.addMove(2,2, 'X');        // - - X - -
        g.addMove(3,3, 'X');        // - - - X -
        g.addMove(4,4, 'X');        // - - - - X
        REQUIRE(g.Winner() == 10);
    }

    SECTION("rev-diagnonal3"){
        Game g(3);
        g.fill();
        g.addMove(0,2, 'X');            // - - X
        g.addMove(1,1, 'X');            // - X -
        g.addMove(2,0, 'X');            // X - -
        REQUIRE(g.Winner() == 10);
    }
    SECTION("rev-diagnonal5"){
        Game g(5);
        g.fill();
        g.addMove(0,4, 'X');            // - - - - X
        g.addMove(1,3, 'X');            // - - - X -
        g.addMove(2,2, 'X');            // - - X - -
        g.addMove(3,1, 'X');            // - X - - -
        g.addMove(4,0, 'X');            // X - - - -
        REQUIRE(g.Winner() == 10);
    }

}

TEST_CASE("Game"){
    Game g(3);
    g.fill();
    SECTION("IsMoveAllowed") {
        g(1, 1) = 'x';
        REQUIRE(g.isMoveAllowed(1, 1) == false);
    }
    SECTION("AddMove"){
        g.addMove(1, 1, 'X');
        REQUIRE(g(1, 1) == 'X');
    }
    SECTION("Fill/Clear"){
        g(1,1) = 'X';
        REQUIRE(g(0, 0) == '-');
        g.clear();
        REQUIRE(g(0, 0) == '-');
    }
    SECTION("AddSignToMatrix"){
        g(1,1) = 'X';
        REQUIRE(g(1, 1) == 'X');
    }
    SECTION("playerMove"){

    }
}
TEST_CASE("Matrix"){
    SECTION("AmountOfMoves") {
        Matrix m(3, 3);
        m.setMoves(5);
        REQUIRE(m.getMoves() == 5);
    }
}

