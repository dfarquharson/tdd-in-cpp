# Things I Need To Learn About C and C++

## Keywords
- [x] extern
  - [link](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Programming_Languages/C%2B%2B/Code/Keywords/extern)
  - Tells the compiler that the variable is declared in another source module.
  - The linker figures out where this declaration actually is and sets that variable up to point to that location. 
- [ ] explicit

## Syntax Quirks
- [x] ~Thing
   - That's a destructor.
   - Destructors get called when:
     - An object goes out of scope
     - When you use the `delete` operator
     - When the program ends

## Concepts
- [ ] Const Correctness
- [ ] Move Semantics
- [ ] RAII

## Tools
- [ ] CMake
- [ ] Valgrind

## Libraries
- [eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)
- [boost](https://www.boost.org/)
- [openframeworks](https://openframeworks.cc/)

## Meta-Reference
- [awesome-modern-cpp](https://github.com/rigtorp/awesome-modern-cpp)
- [awesome-cpp-1](https://github.com/fffaraz/awesome-cpp)
- [awesome-cpp-2](https://github.com/uhub/awesome-cpp)

## TODO
- [ ] get openframeworks working from CMake and CLion