#include "Game.h"
#include <gtest/gtest.h>

TEST(Game, IsMoveAllowed) {
    Game g(3);
    g(1, 1) = 'x';
    EXPECT_FALSE(g.isMoveAllowed(1, 1));
}

TEST(Game, AddMove) {
    Game g(3);
    g.addMove(1, 1, 'X');
    EXPECT_EQ(g(1, 1), 'X');
}

TEST(Game, FillClear) {
    Game g(3);
    g(1, 1) = 'X';
    EXPECT_EQ(g(0, 0), '-');
    g.clear();
    EXPECT_EQ(g(0, 0), '-');
}

TEST(Game, AddSignToMatrix) {
    Game g(3);
    g(1, 1) = 'X';
    EXPECT_EQ(g(1, 1), 'X');
}

TEST(NoWinnerRand, Rand00) {
    Game g(3);
    g.addMove(0, 0, 'X');           // X - -
    EXPECT_EQ(g.Winner(), 0);
}

TEST(NoWinnerRand, Rand01) {
    Game g(3);
    g.addMove(0, 1, 'X');           // - X -
    EXPECT_EQ(g.Winner(), 0);
}

TEST(NoWinnerRand, Rand10) {
    Game g(3);
    g.addMove(1, 0, 'X');           // X - -
    EXPECT_EQ(g.Winner(), 0);
}

TEST(NoWinnerRand, Rand11) {
    Game g(3);
    g.addMove(1, 1, 'X');           // - X -
    EXPECT_EQ(g.Winner(), 0);
}

TEST(NoWinnerRand, Rand22) {
    Game g(3);
    g.addMove(2, 2, 'X');           // - - -
    EXPECT_EQ(g.Winner(), 0);
}

// Tests for Winner3
TEST(Winner3, Poziomy3X) {
    Game g(3);
    g.addMove(0, 0, 'X');        // X X X
    g.addMove(0, 1, 'X');        // - - -
    g.addMove(0, 2, 'X');        // - - -
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner3, Poziomy3O) {
    Game g(3);
    g.addMove(0, 0, 'O');        // O O O
    g.addMove(0, 1, 'O');        // - - -
    g.addMove(0, 2, 'O');        // - - -
    EXPECT_EQ(g.Winner(), -10);
}

TEST(Winner3, Pionowy3) {
    Game g(3);
    g.addMove(0, 0, 'X');        // X - -
    g.addMove(1, 0, 'X');        // X - -
    g.addMove(2, 0, 'X');        // X - -
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner3, Pionowy3O) {
    Game g(3);
    g.addMove(0, 0, 'O');        // O - -
    g.addMove(1, 0, 'O');        // O - -
    g.addMove(2, 0, 'O');        // O - -
    EXPECT_EQ(g.Winner(), -10);
}

TEST(Winner3, Diagnonal3) {
    Game g(3);
    g.addMove(0, 0, 'X');        // X - -
    g.addMove(1, 1, 'X');        // - X -
    g.addMove(2, 2, 'X');        // - - X
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner3, Diagnonal3O) {
    Game g(3);
    g.addMove(0, 0, 'O');        // O - -
    g.addMove(1, 1, 'O');        // - O -
    g.addMove(2, 2, 'O');        // - - O
    EXPECT_EQ(g.Winner(), -10);
}

TEST(Winner3, RevDiagnonal3) {
    Game g(3);
    g.addMove(0, 2, 'X');        // - - X
    g.addMove(1, 1, 'X');        // - X -
    g.addMove(2, 0, 'X');        // X - -
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner3, RevDiagnonal3O) {
    Game g(3);
    g.addMove(0, 2, 'O');        // - - O
    g.addMove(1, 1, 'O');        // - O -
    g.addMove(2, 0, 'O');        // O - -
    EXPECT_EQ(g.Winner(), -10);
}

// Tests for Winner5
TEST(Winner5, Poziomy5) {
    Game g(5);
    g.addMove(2, 0, 'X');        // - - - - -
    g.addMove(2, 1, 'X');        // - - - - -
    g.addMove(2, 2, 'X');        // X X X X X
    g.addMove(2, 3, 'X');        // - - - - -
    g.addMove(2, 4, 'X');        // - - - - -
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner5, Pionowy5) {
    Game g(5);
    g.addMove(2, 0, 'X');        // - - X - -
    g.addMove(2, 1, 'X');        // - - X - -
    g.addMove(2, 2, 'X');        // - - X - -
    g.addMove(2, 3, 'X');        // - - X - -
    g.addMove(2, 4, 'X');        // - - X - -
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner5, Diagnonal5) {
    Game g(5);
    g.addMove(0, 0, 'X');        // X - - - -
    g.addMove(1, 1, 'X');        // - X - - -
    g.addMove(2, 2, 'X');        // - - X - -
    g.addMove(3, 3, 'X');        // - - - X -
    g.addMove(4, 4, 'X');        // - - - - X
    EXPECT_EQ(g.Winner(), 10);
}

TEST(Winner5, RevDiagnonal5) {
    Game g(5);
    g.addMove(0, 4, 'X');        // - - - - X
    g.addMove(1, 3, 'X');        // - - - X -
    g.addMove(2, 2, 'X');        // - - X - -
    g.addMove(3, 1, 'X');        // - X - - -
    g.addMove(4, 0, 'X');        // X - - - -
    EXPECT_EQ(g.Winner(), 10);
}



// TEST("Benchmarking-aiMove") {
// // #if 0
//     BENCHMARK("Board-3") {
//         Game board(3);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };
//     BENCHMARK("Board-5") {
//         Game board(5);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };

//     BENCHMARK("Board-7") {
//         Game board(7);
//         board.addMove(1, 1, 'X');
//         aiMove(board);
//     };
// // #endif
// }


// TEST("No-Winner-rand"){
//     Game g(3);
//     SECTION("Rand00"){

//         g.addMove(0,0, 'X');           // X - -
//         // g.addMove(0,1, 'X');        // - - -
//         // g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }
//     SECTION("Rand01"){
//         g.addMove(0,1, 'X');           // - X -
//         // g.addMove(0,1, 'X');        // - - -
//         // g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }

//     SECTION("Rand10"){
//         // g.addMove(0,0, 'X');         // - - -
//         g.addMove(1,0, 'X');            // X - -
//         //   g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 0);
//     }
//     SECTION("Rand11"){
//         // g.addMove(0,0, 'X');        // - - -
//         g.addMove(1,1, 'X');           // - X -
//         //   g.addMove(0,2, 'X');      // - - -
//         REQUIRE(g.Winner() == 0);
//     }

//     SECTION("Rand22"){
//         // g.addMove(0,0, 'X');        // - - -
//         g.addMove(2,2, 'X');          // - - -
//         //g.addMove(0,2, 'X');        // - - X
//         REQUIRE(g.Winner() == 0);
//     }

// }

// TEST("Winner3"){
//     Game g(3);
//     SECTION("Poziomy3X"){
//         g.addMove(0,0, 'X');        // X X X
//         g.addMove(0,1, 'X');        // - - -
//         g.addMove(0,2, 'X');        // - - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("Poziomy3O"){
//         g.addMove(0,0, 'O');        // O O O
//         g.addMove(0,1, 'O');        // - - -
//         g.addMove(0,2, 'O');        // - - -
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("Pionowy3"){
//         g.addMove(0,0, 'X');        // X - -
//         g.addMove(1,0, 'X');        // X - -
//         g.addMove(2,0, 'X');        // X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("Pionowy3O"){
//         g.addMove(0,0, 'O');        // O - -
//         g.addMove(1,0, 'O');        // O - -
//         g.addMove(2,0, 'O');        // O - -
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("diagnonal3"){
//         g.addMove(0,0, 'X');        // X - -
//         g.addMove(1,1, 'X');        // - X -
//         g.addMove(2,2, 'X');        // - - X
//         REQUIRE(g.Winner() == 10);
//     }

//     SECTION("diagnonal3O"){
//         g.addMove(0,0, 'O');        // O - -
//         g.addMove(1,1, 'O');        // - O -
//         g.addMove(2,2, 'O');        // - - O
//         REQUIRE(g.Winner() == -10);
//     }

//     SECTION("rev-diagnonal3"){
//         g.addMove(0,2, 'X');            // - - X
//         g.addMove(1,1, 'X');            // - X -
//         g.addMove(2,0, 'X');            // X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("rev-diagnonal3O"){
//         g.addMove(0,2, 'O');            // - - O
//         g.addMove(1,1, 'O');            // - O -
//         g.addMove(2,0, 'O');            // O - -
//         REQUIRE(g.Winner() == -10);
//     }

// }

// TEST("Winner5"){
//     Game g(5);
//     SECTION("Poziomy5"){
//         g.addMove(2,0, 'X');        // - - - - -
//         g.addMove(2,1, 'X');        // - - - - -
//         g.addMove(2,2, 'X');        // X X X X X
//         g.addMove(2,3, 'X');        // - - - - -
//         g.addMove(2,4, 'X');        // - - - - -
//         REQUIRE(g.Winner() == 10);
//     }

//     SECTION("Pionowy5"){
//         g.addMove(2,0, 'X');        // - - X - -
//         g.addMove(2,1, 'X');        // - - X - -
//         g.addMove(2,2, 'X');        // - - X - -
//         g.addMove(2,3, 'X');        // - - X - -
//         g.addMove(2,4, 'X');        // - - X - -
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("diagnonal5"){
//         g.addMove(0,0, 'X');        // X - - - -
//         g.addMove(1,1, 'X');        // - X - - -
//         g.addMove(2,2, 'X');        // - - X - -
//         g.addMove(3,3, 'X');        // - - - X -
//         g.addMove(4,4, 'X');        // - - - - X
//         REQUIRE(g.Winner() == 10);
//     }
//     SECTION("rev-diagnonal5"){
//         g.addMove(0,4, 'X');            // - - - - X
//         g.addMove(1,3, 'X');            // - - - X -
//         g.addMove(2,2, 'X');            // - - X - -
//         g.addMove(3,1, 'X');            // - X - - -
//         g.addMove(4,0, 'X');            // X - - - -
//         REQUIRE(g.Winner() == 10);
//     }
// }
// TEST("Game"){
//     Game g(3);
//     SECTION("IsMoveAllowed") {
//         g(1, 1) = 'x';
//         REQUIRE(g.isMoveAllowed(1, 1) == false);
//     }
//     SECTION("AddMove"){
//         g.addMove(1, 1, 'X');
//         REQUIRE(g(1, 1) == 'X');
//     }
//     SECTION("Fill/Clear"){
//         g(1,1) = 'X';
//         REQUIRE(g(0, 0) == '-');
//         g.clear();
//         REQUIRE(g(0, 0) == '-');
//     }
//     SECTION("AddSignToMatrix"){
//         g(1,1) = 'X';
//         REQUIRE(g(1, 1) == 'X');
//     }
// }


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}