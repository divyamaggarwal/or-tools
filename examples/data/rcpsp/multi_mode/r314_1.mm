************************************************************************
file with basedata            : cr314_.bas
initial value random generator: 29173
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  140
RESOURCES
  - renewable                 :  3   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       24        4       24
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           5  10
   3        3          3           7   8   9
   4        3          3           9  11  12
   5        3          3           6  11  13
   6        3          3          14  16  17
   7        3          1          17
   8        3          2          11  13
   9        3          2          15  16
  10        3          2          12  17
  11        3          2          14  16
  12        3          2          13  14
  13        3          1          15
  14        3          1          15
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  R 3  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0    0
  2      1     2       9    8    6    8    0
         2     6       8    4    6    8    0
         3     8       8    3    5    0    8
  3      1     6      10    2    4    0    9
         2     8       7    2    2    0    5
         3    10       4    1    2    0    5
  4      1     5       7    9    8    7    0
         2     6       7    7    5    0    7
         3    10       7    2    4    5    0
  5      1     3       4    9    9    0    7
         2     4       4    7    8    6    0
         3    10       3    5    8    0    3
  6      1     1       2    6    5    0   10
         2     3       1    5    4    0    6
         3     7       1    5    3    0    3
  7      1     8       7    7    6    0    6
         2     9       3    7    5    3    0
         3    10       3    6    5    2    0
  8      1     6       4    7    8    0    7
         2     7       2    6    7    6    0
         3     7       2    7    6    0    7
  9      1     6       3    9    5    1    0
         2     8       3    7    3    0    2
         3    10       3    1    3    0    2
 10      1     1       6    9    8    0    5
         2     9       5    5    7    0    2
         3    10       5    1    7    0    2
 11      1     5       9    8    9    0   10
         2     7       9    8    9   10    0
         3     8       6    7    9    0   10
 12      1     5       6    8    7    5    0
         2     6       5    7    5    3    0
         3     8       5    7    2    0    4
 13      1     6       6    4    4    6    0
         2     9       5    4    4    5    0
         3     9       6    4    4    4    0
 14      1     2       6    9    7    9    0
         2     4       4    8    5    7    0
         3     6       3    8    5    4    0
 15      1     5       8    6    7    0    2
         2     5       8    7    6    0    1
         3     9       7    6    5    4    0
 16      1     2      10    6    7    4    0
         2     4      10    5    5    2    0
         3     8      10    2    5    0    8
 17      1     2       4    8    4    5    0
         2     5       4    8    4    4    0
         3    10       3    8    3    0    9
 18      1     0       0    0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  R 3  N 1  N 2
   19   20   19   41   52
************************************************************************