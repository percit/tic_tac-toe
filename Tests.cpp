#include "Game.h"
#include "catch/catch.hpp"


#if 0
 TEST_CASE("Benchmarking-aiMove") {


    BENCHMARK("Board-3") {
        Game board(3);
        board.fill();
        board.addMove(1, 1, 'X');
        aiMove(board);
    };
    BENCHMARK("Board-5") {
        Game board(5);
        board.fill();
        board.addMove(1, 1, 'X');
        aiMove(board);
    };

    BENCHMARK("Board-7") {
        Game board(7);
        board.fill();
        board.addMove(1, 1, 'X');
        aiMove(board);
    };
#endif
}


TEST_CASE("winner-rand"){

    SECTION("Rand00"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'X');           // X - -
        // g.addMove(0,1, 'X');        // - - -
        // g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 0);
    }
    SECTION("Rand01"){
        Game g(3);
        g.fill();
        g.addMove(0,1, 'X');           // - X -
        // g.addMove(0,1, 'X');        // - - -
        // g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 0);
    }

    SECTION("Rand10"){
        Game g(3);
        g.fill();
        // g.addMove(0,0, 'X');         // - - -
        g.addMove(1,0, 'X');            // X - -
        //   g.addMove(0,2, 'X');        // - - -
        REQUIRE(g.Winner() == 0);
    }
    SECTION("Rand11"){
        Game g(3);
        g.fill();
        // g.addMove(0,0, 'X');        // - - -
        g.addMove(1,1, 'X');           // - X -
        //   g.addMove(0,2, 'X');      // - - -
        REQUIRE(g.Winner() == 0);
    }

    SECTION("Rand22"){
        Game g(3);
        g.fill();
        // g.addMove(0,0, 'X');        // - - -
        g.addMove(2,2, 'X');          // - - -
        //g.addMove(0,2, 'X');        // - - X
        REQUIRE(g.Winner() == 0);
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
    SECTION("Poziomy3O"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'O');        // X X X
        g.addMove(0,1, 'O');        // - - -
        g.addMove(0,2, 'O');        // - - -
        REQUIRE(g.Winner() == -10);
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
    SECTION("Pionowy3O"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'O');        // X - -
        g.addMove(1,0, 'O');        // X - -
        g.addMove(2,0, 'O');        // X - -
        REQUIRE(g.Winner() == -10);
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

    SECTION("diagnonal3O"){
        Game g(3);
        g.fill();
        g.addMove(0,0, 'O');        // X - -
        g.addMove(1,1, 'O');        // - X -
        g.addMove(2,2, 'O');        // - - X
        REQUIRE(g.Winner() == -10);
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
    SECTION("rev-diagnonal3O"){
        Game g(3);
        g.fill();
        g.addMove(0,2, 'O');            // - - X
        g.addMove(1,1, 'O');            // - X -
        g.addMove(2,0, 'O');            // X - -
        REQUIRE(g.Winner() == -10);
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
}


