#!/bin/bash

cmake -H. -Bbuild && cd build && make VERBOSE=1 all && cd .. && build/game
