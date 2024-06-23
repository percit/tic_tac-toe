#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#include "Game.h"  // Assuming Game class and aiMove are defined in Game.h

void BM_Board3(benchmark::State& state) {
    for (auto _ : state) {
        Game board(3);
        board.addMove(1, 1, 'X');
        aiMove(board);
    }
}
BENCHMARK(BM_Board3);

void BM_Board5(benchmark::State& state) {
    for (auto _ : state) {
        Game board(5);
        board.addMove(1, 1, 'X');
        aiMove(board);
    }
}
BENCHMARK(BM_Board5);

void BM_Board7(benchmark::State& state) {
    for (auto _ : state) {
        Game board(7);
        board.addMove(1, 1, 'X');
        aiMove(board);
    }
}
BENCHMARK(BM_Board7);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int test_result = RUN_ALL_TESTS();

    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();

    return test_result;
}
