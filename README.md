# Repository of algorithm studies

[![Licence](https://img.shields.io/github/license/Ileriayo/markdown-badges?style=for-the-badge)](./LICENSE)

A collection of study on algorithmic problems, implemented in C. 

## Quickstart

All compiled modules are in `bin/`. 

The following modules are available.

```console
study
├── array-manipulation
│   # Search max contiguous value and the smallest missing value.
├── binary-gap
│   # Finds the longest sequence of zeroes in array.
├── binary-search-tree
│   # The ever favority binary search tree
├── bit-manipulation
│   # Bit manipulation demonstration
├── bubble-sort
│   # Does a bubble demonstration
├── dijkstra-shortest-path
│   # Find shortest path using Dijkstra algorithm
├── fibonacci
│   # Computing fibonacci value
├── fizzbuzz
│   # Does a fizzbuzz sequence
├── flood-fill
│   # Maze solving algorithm flood fill.
├── pascals-triangle
│   # Building a pascal triangle
├── product-code
│   # Linked listing a product code
├── quick-sort
│   # Does a quick sort demonstration
└── root-mean-square-error
    # Computes the root mean square error value
```

### Build all modules

Do a `make` or `make all` to build all modules within the `src/` directory.


### Build specific module

To build a specific module, do a make and specify the `MODULE`.

```console
%> make study MODULE=root-mean-square-error
```


### Example run

```console
%> ./bin/root-mean-square-error 
Predicted: { 4.00 25.00 0.75 11.00  }
Observed : { 3.00 21.00 -1.25 13.00  }
Root-Mean-Square Error: 2.500

```


## License

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

[MIT](LICENSE) © Chris Cabang