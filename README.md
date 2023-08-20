# Repository of algorithm studies

[![Licence](https://img.shields.io/github/license/Ileriayo/markdown-badges?style=for-the-badge)](./LICENSE)

Sets of solution to common algorithmic problems. This repository is the authors personal study
notes.

## Quickstart

All compiled modules are in `bin/`. 

The following modules are available.

```console
src
├── array-manipulation
│   # Search max contiguous value and the smallest missing value.
├── binary-gap
│   # Finds the longest sequence of zeroes in array.
├── binary-search-tree
│   # The ever favority binary search tree
├── bit-manipulation
│   # Bit manipulation demonstration
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
├── root-mean-square-error
│   # Computes the root mean square error value
└── sort
    # Does a bubble and quick sort demonstration
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