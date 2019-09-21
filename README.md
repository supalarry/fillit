# fillit
Given tetris pieces, find the smallest possible square to fit the pieces together.

## Project folder structure
```
fillit
├── fillit-files [source files for project + header file]
├── libft [my library with various functions]
Makefile [compiles the project]
author [my and my teammates usernames]
```

## Allowed pieces
The input file containing tetris pieces can contain following pieces. Furthermore, each
piece needs to be 4x4 square consisting of dots and hashes. The input is validated. Thus, invalid
input would be rejected.

```
....
..##
..#.
..#.

....
....
..##
..##

####
....
....
....

.##.
..##
....
....

....
.##.
##..
....

.#..
###.
....
....

....
.##.
..#.
..#.
```
## Usage
Run **make** to create **fillit executable**. As an argument, file containing tetriminos is passed and
result is smallest square that fits all pieces. Each tetrimino is represented as letters to understand which piece is which.
## Input
Below is an input file consisting of tetriminos to be put within a square.
```
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....

```

# Output
After running fillit executable with the input file above
```
./fillit map
```
the output is the following square. Thus, tetriminos have been placed in smallest possible square.

```
DDAA
CDDA
CCCA
BBBB
```
Each tetrimino is represted with letters to distinguish which one is which.
