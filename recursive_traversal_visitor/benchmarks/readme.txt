
-------------------------------------------------------------------------------
tiny tree string
  iterate counting [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100           198      3.465 ms
                                        172.157 ns    170.121 ns    178.343 ns
                                        15.7749 ns    2.45812 ns    34.1819 ns

ShrPtrNode<value_type>::visit                  100            83     3.4943 ms
                                        420.349 ns    418.675 ns     423.88 ns
                                        11.8318 ns    7.13916 ns    22.6257 ns


-------------------------------------------------------------------------------
tiny tree string
  iterate recursive counting [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100           151     3.4881 ms
                                        223.325 ns    220.887 ns    229.947 ns
                                        18.7758 ns    7.23849 ns    39.0912 ns

ShrPtrNode<value_type>::visit                  100            80       3.48 ms
                                        432.625 ns    431.988 ns    434.813 ns
                                        5.35635 ns    1.76117 ns    12.0165 ns


-------------------------------------------------------------------------------
tiny tree string
  to xml [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            21       3.57 ms
                                        1.69938 us    1.69243 us    1.72824 us
                                         63.168 ns    10.1832 ns     148.73 ns

ShrPtrNode<value_type>::visit                  100            19      3.572 ms
                                        1.97337 us    1.91095 us    2.07468 us
                                        396.835 ns    273.137 ns     544.55 ns


-------------------------------------------------------------------------------
tiny tree int
  iterate counting [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100           199     3.4825 ms
                                        176.206 ns    175.945 ns    176.814 ns
                                        1.91604 ns   0.990396 ns    3.85181 ns

ShrPtrNode<value_type>::visit                  100            82     3.5096 ms
                                        405.537 ns    404.512 ns    407.573 ns
                                        7.09705 ns    4.20792 ns    11.8339 ns


-------------------------------------------------------------------------------
tiny tree int
  iterate recursive counting [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100           156     3.4632 ms
                                        218.641 ns    218.321 ns    219.468 ns
                                        2.44918 ns     1.1801 ns    5.17388 ns

ShrPtrNode<value_type>::visit                  100            81     3.4911 ms
                                        433.383 ns    431.864 ns    438.395 ns
                                        12.5178 ns    2.48988 ns    27.8501 ns


-------------------------------------------------------------------------------
tiny tree int
  to xml [N=6]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             9     3.5694 ms
                                        4.08078 us    4.06344 us    4.15989 us
                                        160.564 ns    19.2129 ns    380.293 ns

ShrPtrNode<value_type>::visit                  100             9     3.8169 ms
                                          4.213 us    4.18367 us    4.27367 us
                                        206.311 ns    125.918 ns    408.144 ns


-------------------------------------------------------------------------------
small tree string
  iterate counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            15     3.6015 ms
                                        2.41553 us      2.412 us     2.4256 us
                                        27.9606 ns    11.9844 ns    59.3525 ns

ShrPtrNode<value_type>::visit                  100             6      4.143 ms
                                        6.90133 us    6.88383 us    6.95117 us
                                        139.202 ns    61.2599 ns    301.259 ns


-------------------------------------------------------------------------------
small tree string
  iterate recursive counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            11     3.6751 ms
                                        3.25809 us    3.23964 us    3.29945 us
                                        133.438 ns    72.7679 ns    267.372 ns

ShrPtrNode<value_type>::visit                  100             5      3.651 ms
                                          7.311 us     7.2914 us     7.3578 us
                                        145.052 ns    75.6825 ns    293.507 ns


-------------------------------------------------------------------------------
small tree string
  to xml [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             2     4.5824 ms
                                         22.988 us      22.88 us     23.291 us
                                        818.665 ns    154.158 ns    1.72814 us

ShrPtrNode<value_type>::visit                  100             2     5.3632 ms
                                         26.808 us    26.4175 us    27.6405 us
                                        2.77775 us     1.5129 us    4.71966 us


-------------------------------------------------------------------------------
small tree int
  iterate counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            15     3.5775 ms
                                        2.35187 us    2.34873 us    2.36127 us
                                        25.4051 ns    10.3835 ns    55.3082 ns

ShrPtrNode<value_type>::visit                  100             6     4.1496 ms
                                        6.92317 us    6.90667 us      6.973 us
                                        132.592 ns    38.9387 ns    287.645 ns


-------------------------------------------------------------------------------
small tree int
  iterate recursive counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            12     3.7104 ms
                                        3.13858 us    3.12492 us     3.1705 us
                                        100.415 ns    53.0419 ns    204.942 ns

ShrPtrNode<value_type>::visit                  100             5      3.653 ms
                                          7.249 us     7.2324 us     7.3144 us
                                        147.299 ns    30.1164 ns    343.424 ns


-------------------------------------------------------------------------------
small tree int
  to xml [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     6.6867 ms
                                         67.471 us     67.294 us     67.787 us
                                         1.1685 us    349.964 ns    2.26501 us

ShrPtrNode<value_type>::visit                  100             1     7.0769 ms
                                         71.257 us     71.022 us      72.06 us
                                        1.99476 us    638.683 ns    4.52035 us


-------------------------------------------------------------------------------
medium tree string
  iterate counting [N=1111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             2     4.7284 ms
                                         27.246 us    25.9825 us    29.1055 us
                                        7.69878 us    5.77757 us    10.2846 us

ShrPtrNode<value_type>::visit                  100             1     6.9276 ms
                                         68.435 us     67.964 us     69.949 us
                                         3.8516 us     1.0469 us    8.52633 us


-------------------------------------------------------------------------------
medium tree string
  iterate recursive counting [N=1111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             2     6.6928 ms
                                         33.604 us    33.5135 us     33.758 us
                                        584.204 ns     371.26 ns    945.168 ns

ShrPtrNode<value_type>::visit                  100             1     7.2655 ms
                                         72.585 us     72.241 us     74.189 us
                                         3.2082 us    331.294 ns    7.61548 us


-------------------------------------------------------------------------------
medium tree string
  to xml [N=1111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    22.2254 ms
                                         222.27 us    221.793 us    223.226 us
                                        3.32823 us    2.02614 us    6.35278 us

ShrPtrNode<value_type>::visit                  100             1    26.0687 ms
                                         261.77 us    261.244 us    264.071 us
                                        4.83472 us    703.474 ns    11.4307 us


-------------------------------------------------------------------------------
medium tree int
  iterate counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            15      3.588 ms
                                         2.5158 us     2.4358 us      2.643 us
                                        507.863 ns    358.335 ns    692.306 ns

ShrPtrNode<value_type>::visit                  100             6     4.1064 ms
                                         6.9715 us     6.9445 us    7.04033 us
                                        194.551 ns    27.7809 ns    353.384 ns


-------------------------------------------------------------------------------
medium tree int
  iterate recursive counting [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100            12     3.7344 ms
                                        3.15092 us    3.10908 us    3.32858 us
                                        385.856 ns    52.1392 ns    912.001 ns

ShrPtrNode<value_type>::visit                  100             5      3.639 ms
                                         7.2532 us     7.2382 us     7.3122 us
                                        132.588 ns    27.6919 ns    308.815 ns


-------------------------------------------------------------------------------
medium tree int
  to xml [N=111]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     6.3059 ms
                                          70.04 us     68.119 us     73.092 us
                                        12.1403 us    8.52887 us    16.3173 us

ShrPtrNode<value_type>::visit                  100             1     7.1326 ms
                                         64.718 us     64.483 us     65.643 us
                                        2.09268 us    421.591 ns    4.88656 us


-------------------------------------------------------------------------------
big tree string
  iterate counting [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    44.8475 ms
                                        453.529 us    450.447 us    459.323 us
                                        20.9293 us    12.7669 us    32.9385 us

ShrPtrNode<value_type>::visit                  100             1    123.428 ms
                                        1.23602 ms    1.22783 ms    1.25707 ms
                                        61.7967 us     19.563 us    118.372 us


-------------------------------------------------------------------------------
big tree string
  iterate recursive counting [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    62.4816 ms
                                        611.003 us    607.877 us    616.058 us
                                        19.9137 us    14.2411 us    32.3572 us

ShrPtrNode<value_type>::visit                  100             1    128.586 ms
                                        1.32475 ms    1.30356 ms    1.35906 ms
                                        135.001 us    95.2579 us    192.157 us


-------------------------------------------------------------------------------
big tree string
  to xml [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    410.028 ms
                                        4.09785 ms     4.0743 ms    4.12212 ms
                                        121.614 us    107.031 us    147.097 us

ShrPtrNode<value_type>::visit                  100             1     484.86 ms
                                        4.75689 ms    4.72116 ms    4.80192 ms
                                        204.391 us    169.793 us    263.925 us


-------------------------------------------------------------------------------
big tree int
  iterate counting [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    44.7887 ms
                                        448.684 us    447.437 us    452.598 us
                                        10.1551 us    3.68416 us    22.3904 us

ShrPtrNode<value_type>::visit                  100             1     123.49 ms
                                         1.2294 ms    1.22276 ms     1.2438 ms
                                        47.5542 us    26.3923 us     90.233 us


-------------------------------------------------------------------------------
big tree int
  iterate recursive counting [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1    59.1307 ms
                                         584.83 us    579.415 us    603.858 us
                                        46.0666 us    13.7507 us    104.749 us

ShrPtrNode<value_type>::visit                  100             1    128.714 ms
                                        1.31674 ms    1.30321 ms    1.33475 ms
                                        79.5824 us    63.6707 us    98.4342 us


-------------------------------------------------------------------------------
big tree int
  to xml [N=19531]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     1.13741 s
                                        11.5018 ms    11.4392 ms    11.5743 ms
                                        343.858 us    300.261 us    424.832 us

ShrPtrNode<value_type>::visit                  100             1     1.27695 s
                                        12.6647 ms    12.5801 ms     12.744 ms
                                        417.618 us    374.612 us    467.355 us


-------------------------------------------------------------------------------
huge tree string
  iterate counting [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     1.42847 s
                                        14.3297 ms    14.2887 ms    14.3808 ms
                                        233.155 us    189.551 us    292.112 us

ShrPtrNode<value_type>::visit                  100             1     4.36558 s
                                        42.9782 ms    42.9029 ms    43.0649 ms
                                        413.422 us    343.667 us    501.309 us


-------------------------------------------------------------------------------
huge tree string
  iterate recursive counting [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     1.82824 s
                                        18.2571 ms    18.2156 ms    18.3108 ms
                                        237.863 us    189.158 us    293.629 us

ShrPtrNode<value_type>::visit                  100             1     4.35114 s
                                        43.5261 ms    43.4534 ms    43.6407 ms
                                        456.792 us     325.05 us    758.504 us


-------------------------------------------------------------------------------
huge tree string
  to xml [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1      11.132 s
                                        110.793 ms    110.687 ms    110.911 ms
                                        568.307 us    473.445 us     746.99 us

ShrPtrNode<value_type>::visit                  100             1     13.7565 s
                                        137.463 ms    137.319 ms    137.651 ms
                                        835.803 us    650.344 us    1.18463 ms


-------------------------------------------------------------------------------
huge tree int
  iterate counting [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(27)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     1.32481 s
                                         13.222 ms    13.1819 ms    13.2828 ms
                                        249.524 us    186.404 us    385.531 us

ShrPtrNode<value_type>::visit                  100             1     4.02273 s
                                        39.8632 ms    39.7713 ms    39.9735 ms
                                        510.089 us    427.212 us    704.502 us


-------------------------------------------------------------------------------
huge tree int
  iterate recursive counting [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(46)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     1.67494 s
                                         16.743 ms    16.6973 ms    16.7987 ms
                                        255.762 us    210.366 us    327.407 us

ShrPtrNode<value_type>::visit                  100             1     4.05351 s
                                        40.7302 ms    40.6447 ms    40.8677 ms
                                        543.958 us    391.289 us    886.019 us


-------------------------------------------------------------------------------
huge tree int
  to xml [N=488281]
-------------------------------------------------------------------------------
..\..\..\recursive_traversal_visitor\benchmarks\benchmark_visit.cpp(67)
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Node<value_type>::visit                        100             1     30.3628 s
                                        303.022 ms    302.745 ms     303.37 ms
                                        1.57689 ms    1.29194 ms    2.07436 ms

ShrPtrNode<value_type>::visit                  100             1     33.4727 s
                                        327.417 ms     327.08 ms    327.804 ms
                                        1.84086 ms    1.58403 ms    2.20486 ms


===============================================================================
test cases: 10 | 10 passed
assertions:  0 |  0 passed


