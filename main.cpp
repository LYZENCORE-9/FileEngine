#include <cstdint>
#include <cstdio>
#include <stdio.h>
#include "core/INI/iem-ini.h"

using namespace FileEngine::INI;

int main(int argc, char const *argv[])
{
	/*File::Create("test.ini");
	getchar();
    if(!File::Exists("test.ini")) { printf("\nExists Error"); }
    getchar();
    File::Rename("test.ini", "test_renamed.ini");
    getchar();
    File::Copy("test_renamed.ini", "test_copied.ini");
    getchar();
    File::Move("test_copied.ini", "source/test_copied.ini");
    getchar();
    File::Delete("test_renamed.ini");
    getchar();
    File::Create("test.ini");
    getchar();*/
    //File::Create("test.ini");
    char value = 0;
    int returned_value = 0;
    if((returned_value = Reader::ReadChar("Hello", "test_section.ini", "Amy", &value)) < 0) { 

        if(returned_value == -1)
        {
            printf("E_INI_FILE_NOT_FOUND\n");
        }
        else if(returned_value == -2)
        {
            printf("E_INI_KEY_NOT_FOUND\n");
        }
        else if(returned_value == -3)
        {
            printf("E_INI_VALUE_OR_KEY_PASSED_BUFFER_SIZE\n");
        }
        else if(returned_value == -4)
        {
            printf("E_INI_WRITEBOOL_WRONG_VALUE\n");
        }
        else if(returned_value == -5)
        {
            printf("E_INI_SECTION_NOT_FOUND\n");
        }
        else if(returned_value == -6)
        {
            printf("E_INI_SECTION_PASSED_BUFFER_SIZE\n");
        }
    }

    
    printf("\nValue = %c", value);
	return 0;
}