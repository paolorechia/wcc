# wcc - cheap copy of Unix wc - C++ package template

## Why?
Useful as an C++ template for small projects, and for learning.

### Installation

#### pybind11
This package depends on pybind11. Easiest way to install is to do:

```bash
git clone https://github.com/pybind/pybind11.git
```

I've used version `2.12.0.dev1`.


#### CMake
To prepare cmake run:

```bash
cmake .
```

This will download the dependencies and generate the appropriate build files.
Then compile the program with:

```bash
cmake --build .
```

A binary named 'wcc' will be generated.

#### Python Extension
Additionally, the build should create a `python_extension.cpython-...` file. This can be used as follows:

```python
import python_extension
python_extension.add(3, 5)
```

