# holbertonschool-system_algorithms

Projects of the **System - Algorithms** track at Holberton School.

This repository gathers C implementations of advanced data structures and
algorithms, with a focus on how they work in memory and on their complexity.

## Projects

| Project | Description |
| --- | --- |
| [red_black_tree](./red_black_tree) | Red-Black trees: self-balancing binary search trees |

## Requirements

* Ubuntu 20.04 LTS
* `gcc 9.4.0` with the flags `-Wall -Werror -Wextra -pedantic`
* Code written in the [Betty](https://github.com/hs-hq/Betty) style
* No global variables
* No more than 5 functions per file

## Usage

Each project lives in its own folder with its own `README.md`. To compile a
project with a test `main.c` file:

```
cd red_black_tree
gcc -Wall -Werror -Wextra -pedantic *.c -o rb_trees
```

## Author

* CHERMAT Mustapha - [@stafach](https://github.com/stafach)