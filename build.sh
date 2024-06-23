#!/bin/bash

cd build
cmake .. -DBUILD_TESTS=ON
make -j8