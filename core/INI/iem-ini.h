/*
 *			FileEngine INI Library
 *			https://github.com/LYZENCORE-9/FileEngine
 *
 *	Creator     : LYZENCORE-9
 *  Maintainer  : LYZENCORE-9
 *	Date	    : 30 7 2025 (31 Decembre 2024 the date of idea and prototype)
 *	Update      : 1 8 2025
 *
 *	Under MIT License
 *
 *	Feel free to ask me in discord (distroxyde/lyzencore9_official)
 *	or follow me in github (https://github.com/LYZENCORE-9)
 ****************************************************
 */
#include <cstdint>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#if !defined(_FILEENGINE_INI_LIB_H_) || !defined(_FILEENGINE_INI_H_)
#define _FILEENGINE_INI_LIB_H_
#define _FILEENGINE_INI_H_



namespace FileEngine::INI {

enum INIReturnedValues
{
    E_INI_SUCCESS = 0,
    E_INI_FILE_NOT_FOUND = -1,
    E_INI_KEY_NOT_FOUND = -2,
    E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE = -3,
    E_INI_WRITEBOOL_WRONG_VALUE = -4,
    E_INI_SECTION_NOT_FOUND = -5,
    E_INI_SECTION_PASSED_BUFFER_SIZE = -6,
    E_INI_READBOOL_WRONG_VALUE = -4,
};

class Settings
{
public:
    static const int MAX_FILE_LINES = 512;
    static const int MAX_BUFFER_SIZE = 1024;
    static const int MAX_FILENAME_SIZE = 128;
    static const int MAX_SECTIONS = 512;
    static const int MAX_FILE_HANDLES = 2;

    static const int MAX_SECTION_SIZE = 128;
    static const int MAX_KEY_SIZE = 256;
    static const int MAX_VALUE_SIZE = 256;
    static const int MAX_COMMENT_SIZE = 128; 

};



class File {
public:
    File() { }

    static bool Create(char* filename);
    static bool Exists(char* filename);
    static bool Delete(char* filename);
    static bool Rename(char* filename, char* new_name);
    static bool Copy(char* filename, char* newfilename);
    static bool Move(char* filename, char *path);

    ~File() { }
};

class Writter {
public:
    Writter() {}

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


    ~Writter() {}
};

class Reader {
public:
    Reader() { }

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
    ~Reader() { }
};

class Key {
public:
    Key() { }

    static int Create(char *filename, char *key);
    static int Remove(char *filename, char *key);
    static int Rename(char *filename, char *oldname_key, char *newname_key);
    static int Exists(char *filename, char *key);
    static int GenerateValue(char *filename, char *key);

    ~Key() { }
};

class Comment
{
public:
    //static int AddKeyComment(char *filename, char *key, char *comment); untill release of v 1.0.0-
    //static int EditKeyComment(char *filename, char *key, char *new_comment);
    //static int DeleteKeyComment(char *filename, char *key);

    static int AddComment(char *filename, char *comment);
    static int EditComment(char *filename, char *old_comment, char *new_comment);
    static int DeleteComment(char *filename, char* comment);
};

class Section
{
public:
    static int Create(char *filename, char* section_name);
    static int Delete(char *filename, char* section_name);
    static int Rename(char *filename, char* section_name);
};

}

#endif
