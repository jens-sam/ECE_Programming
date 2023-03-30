#!/usr/bin/env -S gnuplot -persist

set key top right
set term pngcairo size 800,600
set output "plot_2.png"
plot '../test/data.csv' with lines linetype 1, \
     '../test/data_a.out' with lines linetype 2, \
     '../test/data_b.out' with lines linetype 3
