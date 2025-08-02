# FileEngine ! 🗃️ ⚙️ (⚠️ In Progress) 
It's a cross-platform C/C++ library which includes multiple libraries for prossessing files like INI (only at this time) , CFG, IMG, NoSQL and more in future  
## Getting Started  🚀
## Prerequisites  
* C & C++ Compiler (GCC/LLVM Clang) (MSVC i don't know)  
* CMake  
* Make or Ninja build system   
## Libraries  
### INI
#### File Class
```c++
    static bool Create(char* filename);
    static bool Exists(char* filename);
    static bool Delete(char* filename);
    static bool Rename(char* filename, char* new_name);
    static bool Copy(char* filename, char* newfilename);
    static bool Move(char* filename, char *path);
```
#### Writter Class
```c++
// Writes an short (primitive signed types) to the file (does not support Sections)
    static int WriteShort(char *filename, char *key, short *value);
    // Writes an int (primitive signed types) to the file (does not support Sections)
    static int WriteInt(char *filename, char *key, int *value);
    // Writes an long (primitive signed types) to the file (does not support Sections)
    static int WriteLong(char *filename, char *key, long *value);
   // Writes an long long (primitive signed types) to the file (does not support Sections)
    static int WriteLongLong(char *filename, char *key, long long *value);
    // Writes an float (primitive signed types) to the file (does not support Sections)
    static int WriteFloat(char *filename, char *key, float *value);
    // Writes an double (primitive signed types) to the file (does not support Sections)
    static int WriteDouble(char *filename, char *key, double *value);
    // Writes an bool (primitive signed types) to the file (does not support Sections)
    static int WriteBool(char *filename, char *key, bool *value);

    // signed writters now (they are same like above but we need handle types)
    // only decimals

    // Writes an int8_t (primitive signed types) to the file (does not support Sections)
    static int WriteInt8(char *filename, char* key, int8_t *value);
    // Writes an int16_t (primitive signed types) to the file (does not support Sections)
    static int WriteInt16(char *filename, char *key, int16_t *value);
    // Writes an int32_t (primitive signed types) to the file (does not support Sections)
    static int WriteInt32(char *filename, char *key, int32_t *value);
    // Writes an int64_t (primitive signed types) to the file (does not support Sections)
    static int WriteInt64(char *filename, char *key, int64_t *value); // if you built the library on 32bit mod , int64_t will be 32bit not 64bit i guess

    // unsigned writters now

    // Writes an uint8_t (primitive unsigned types) to the file (does not support Sections)
    static int WriteUint8(char *filename, char *key, uint8_t *value);
    // Writes an uint16_t (primitive unsigned types) to the file (does not support Sections)
    static int WriteUint16(char *filename, char *key, uint16_t *value);
    // Writes an uint32_t (primitive unsigned types) to the file (does not support Sections)
    static int WriteUint32(char *filename, char *key, uint32_t *value);
    // Writes an uint64_t (primitive unsigned types) to the file (does not support Sections)
    static int WriteUint64(char *filename, char *key, uint64_t *value); 

    // Characters and Strings

    // Writes an char (primitive signed types) to the file (does not support Sections)
    static int WriteChar(char *filename, char *key, char value[1]);
    // Writes an char string (char* or char[]) (primitive signed types) to the file (does not support Sections)
    static int WriteCString(char *filename, char *key, char *value);
    // Writes an std::string (reference signed types) to the file (does not support Sections)
    static int WriteString(char *filename, char *key, std::string *value);

    // Sections
    // Writes an short (primitive signed types) to the file (supports Sections)
    static int WriteShort(char *section, char *filename, char *key, short *value);
    // Writes an int (primitive signed types) to the file (supports Sections)
    static int WriteInt(char *section, char *filename, char *key, int *value);
    // Writes an long (primitive signed types) to the file (supports Sections)
    static int WriteLong(char *section, char *filename, char *key, long *value);
    // Writes an long long (primitive signed types) to the file (supports Sections);
    static int WriteLongLong(char *section, char *filename, char *key, long long *value);
    // Writes an float (primitive signed types) to the file (supports Sections)
    static int WriteFloat(char *section, char *filename, char *key, float *value);
    // Writes an double (primitive signed types) to the file (supports Sections)
    static int WriteDouble(char *section, char *filename, char *key, double *value);
    // Writes an bool (primitive signed types) to the file (supports Sections)
    static int WriteBool(char *section, char *filename, char *key, bool *value);

    // signed writters now (they are same like above but we need handle types)
    // only decimals

    // Writes an int8_t (primitive signed types) to the file (supports Sections)
    static int WriteInt8(char *section, char *filename, char* key, int8_t *value);
    // Writes an int16_t (primitive signed types) to the file (supports Sections)
    static int WriteInt16(char *section, char *filename, char *key, int16_t *value);
    // Writes an int32_t (primitive signed types) to the file (supports Sections)
    static int WriteInt32(char *section, char *filename, char *key, int32_t *value);
    // Writes an int64_t (primitive signed types) to the file (supports Sections)
    static int WriteInt64(char *section, char *filename, char *key, int64_t *value); // if you built the library on 32bit mod , int64_t will be 32bit not 64bit i guess

    // unsigned writters now

    // Writes an uint8_t (primitive unsigned types) to the file (supports Sections)
    static int WriteUint8(char *section, char *filename, char *key, uint8_t *value);
    // Writes an uint16_t (primitive unsigned types) to the file (supports Sections)
    static int WriteUint16(char *section, char *filename, char *key, uint16_t *value);
    // Writes an uint32_t (primitive unsigned types) to the file (supports Sections)
    static int WriteUint32(char *section, char *filename, char *key, uint32_t *value);
    // Writes an uint64_t (primitive unsigned types) to the file (supports Sections)
    static int WriteUint64(char *section, char *filename, char *key, uint64_t *value); 

    // Characters and Strings

    // Writes an char (primitive signed types) to the file (supports Sections)
    static int WriteChar(char *section, char *filename, char *key, char value[1]);
    // Writes an char string (char* or char[]) (primitive signed types) to the file (supports Sections)
    static int WriteCString(char *section, char *filename, char *key, char *value);
    // Writes an std::string (reference types) to the file (supports Sections)
    static int WriteString(char *section, char *filename, char *key, std::string *value);
```
#### Reader Class
```c++
// Reads an short (primitive signed types) from the file
    static int ReadShort(char *filename, char *key, short *value);
    // Reads an int (primitive signed types) from the file
    static int ReadInt(char *filename, char *key, int *value);
    // Reads an long (primitive signed types) from the file
    static int ReadLong(char *filename, char *key, long *value);
    // Reads an long long (primitive signed types) from the file
    static int ReadLongLong(char *filename, char *key, long long *value);
    // Reads an float (primitive signed types) from the file
    static int ReadFloat(char *filename, char *key, float *value);
    // Reads an double (primitive signed types) from the file
    static int ReadDouble(char *filename, char *key, double *value);
    // Reads an bool (primitive signed types) from the file
    static int ReadBool(char *filename, char *key, bool *value);
    

    // signed writters now (they are same like above but we need handle types)
    // only decimals

    // Reads an int8_t (signed types) from the file
    static int ReadInt8(char *filename, char* key, int8_t *value);
    // Reads an int16_t (signed types) from the file
    static int ReadInt16(char *filename, char *key, int16_t *value);
    // Reads an int32_t (signed types) from the file
    static int ReadInt32(char *filename, char *key, int32_t *value);
    // Reads an int64_t (signed types) from the file
    static int ReadInt64(char *filename, char *key, int64_t *value); // if you built the library on 32bit mod , int64_t will be 32bit not 64bit i guess

    // unsigned writters now

    // Reads an uint8_t (unsigned types) from the file
    static int ReadUint8(char *filename, char *key, uint8_t *value);
    // Reads an uint16_t (unsigned types) from the file
    static int ReadUint16(char *filename, char *key, uint16_t *value);
    // Reads an uint32_t (unsigned types) from the file
    static int ReadUint32(char *filename, char *key, uint32_t *value);
    // Reads an uint64_t (unsigned types) from the file
    static int ReadUint64(char *filename, char *key, uint64_t *value); 

    // Characters and Ststatic rings

    // Reads an char (int8_t) (signed types) from the file
    static int ReadChar(char *filename, char *key, char value[1]);
    // Reads an char array or pointer (string) (signed types) from the file
    static int ReadCString(char *filename, char *key, char *value);
    // Reads an std::string (reference types) from the file
    static int ReadString(char *filename, char *key, std::string *value);

    // Sections
    
    // Reads an short (primitive signed types) from the file (supports Sections)
    static int ReadShort(char *section, char *filename, char *key, short *value);
    // Reads an int (primitive signed types) from the file (supports Sections)
    static int ReadInt(char *section, char *filename, char *key, int *value);
    // Reads an long (primitive signed types) from the file (supports Sections)
    static int ReadLong(char *section, char *filename, char *key, long *value);
    // Reads an long long (primitive signed types) from the file (supports Sections);
    static int ReadLongLong(char *section, char *filename, char *key, long long *value);
    // Reads an float (primitive signed types) from the file (supports Sections)
    static int ReadFloat(char *section, char *filename, char *key, float *value);
    // Reads an double (primitive signed types) from the file (supports Sections)
    static int ReadDouble(char *section, char *filename, char *key, double *value);
    // Reads an bool (primitive signed types) from the file (supports Sections)
    static int ReadBool(char *section, char *filename, char *key, bool *value);

    // signed writters now (they are same like above but we need handle types)
    // only decimals

    // Reads an int8_t (primitive signed types) from the file (supports Sections)
    static int ReadInt8(char *section, char *filename, char* key, int8_t *value);
    // Reads an int16_t (primitive signed types) from the file (supports Sections)
    static int ReadInt16(char *section, char *filename, char *key, int16_t *value);
    // Reads an int32_t (primitive signed types) from the file (supports Sections)
    static int ReadInt32(char *section, char *filename, char *key, int32_t *value);
    // Reads an int64_t (primitive signed types) from the file (supports Sections)
    static int ReadInt64(char *section, char *filename, char *key, int64_t *value); // if you built the library on 32bit mod , int64_t will be 32bit not 64bit i guess

    // unsigned writters now

    // Reads an uint8_t (primitive unsigned types) from the file (supports Sections)
    static int ReadUint8(char *section, char *filename, char *key, uint8_t *value);
    // Reads an uint16_t (primitive unsigned types) from the file (supports Sections)
    static int ReadUint16(char *section, char *filename, char *key, uint16_t *value);
    // Reads an uint32_t (primitive unsigned types) from the file (supports Sections)
    static int ReadUint32(char *section, char *filename, char *key, uint32_t *value);
    // Reads an uint64_t (primitive unsigned types) from the file (supports Sections)
    static int ReadUint64(char *section, char *filename, char *key, uint64_t *value); 

    // Characters and Strings

    // Reads an char (primitive signed types) from the file (supports Sections)
    static int ReadChar(char *section, char *filename, char *key, char value[1]);
    // Reads an char string (char* or char[]) (primitive signed types) from the file (supports Sections)
    static int ReadCString(char *section, char *filename, char *key, char *value);
    // Reads an std::string (reference types) from the file (supports Sections)
    static int ReadString(char *section, char *filename, char *key, std::string *value);
```
* 1 example of creating a file
```c++
#include "../../core/INI/iem-ini.h"

using namespace FileEngine::INI;
int main(int argc, char const *argv[])
{
	char filename[Settings::MAX_FILENAME_SIZE] = "test.ini";
	if(!File::Exists(filename))
	{
		File::Create(filename);
	}
	File::Copy(filename, "test_copied.ini");
	File::Rename("test_copied.ini", "test_renamed.ini");
	File::Move("test_copied.ini", "example_dir/test_copied.ini"); // create example_dir
	File::Delete(filename);

	return 0;
}
```
* 2 example of writting a value for a key
```c++
#include "../../core/INI/iem-ini.h"

using namespace FileEngine::INI;
int main(int argc, char const *argv[])
{
	char filename[Settings::MAX_FILENAME_SIZE] = "test.ini";
	short value = 6767;
	int returned_value = Writter::WriteShort(filename, "Adam", &value);
	if(returned_value < 0)
	{
		exit(EXIT_FAILURE);
	}

	return 0;
}
```
* 3 example of reading a value from a key
```c++
#include "../../core/INI/iem-ini.h"

using namespace FileEngine::INI;
int main(int argc, char const *argv[])
{
	char filename[Settings::MAX_FILENAME_SIZE] = "test.ini";
	short value = 0;
	int returned_value = Reader::ReadShort(filename, "Adam", &value);
	if(returned_value < 0)
	{
		exit(EXIT_FAILURE);
	}
  printf("Value : %d", value);
	return 0;
}
```
* 4 example of writting a value for a key in a specified Section
```c++
#include "../../core/INI/iem-ini.h"

using namespace FileEngine::INI;
int main(int argc, char const *argv[])
{
	char filename[Settings::MAX_FILENAME_SIZE] = "test.ini";
	short value = 6767;
	int returned_value = Writter::WriteShort("Hello", filename, "Adam", &value); // Hello is the section
	if(returned_value < 0)
	{
		exit(EXIT_FAILURE);
	}

	return 0;
}
```
* 5 example of reading a value from a key in a specified Section
```c++
#include "../../core/INI/iem-ini.h"

using namespace FileEngine::INI;
int main(int argc, char const *argv[])
{
	char filename[Settings::MAX_FILENAME_SIZE] = "test.ini";
	short value = 0;
	int returned_value = Reader::ReadShort("Hello", filename, "Adam", &value); // Hello is the section
	if(returned_value < 0)
	{
		exit(EXIT_FAILURE);
	}
  printf("Value : %d", value);
	return 0;
}
```

##  Building 🧰  
## Windows   
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
## GNU/Linux (not tested)
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
## Donate 💸
(change this)  

## In Memory Of My Father
