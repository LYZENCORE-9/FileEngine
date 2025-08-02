# FileEngine ! 🗃️ ⚙️ (⚠️ In Progress) 
It's a cross-platform library which includes multiple libraries for prossessing files like INI (only at this time) , CFG, IMG, NoSQL and more in future  
## Getting Started  🚀
### Prequists  
* C & C++ Compiler (GCC/LLVM Clang) (MSVC i don't know)  
* CMake  
* Make or Ninja build system   
###  Project Structure 🗒️
* ``core`` folder includes the headers of libraries in FileEngine every folder in ``core`` is specified for one library like **INI** .  
* ``source`` folder includes source and mimics the same structure as ``core`` but there is difference every class in header file have his own source file (check ``source/INI`` file) .
###  Building 🧰  
#### Windows   
* Make   
```shell
cmake -S . -B build -G "Unix Makefiles"
cd build
make
```
* Ninja
```shell
cmake -S . -B build -G "Ninja"
cd build
Ninja
```
#### GNU/Linux (not tested)
```shell
cmake -S . -B build -G "Unix Makefiles"
cd build
make
```
* Ninja
```shell
cmake -S . -B build -G "Ninja"
cd build
Ninja
```
### Donate 💸
(change this)  

### In Memory Of My Father
