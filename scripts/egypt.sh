#!/bin/bash
cd ..
egypt-1.10/egypt build/CMakeFiles/lifegame.dir/src/*.expand | dot -Gsize=8,11  -Tpdf -o callgraph.pdf 
