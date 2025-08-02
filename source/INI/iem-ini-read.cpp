#include "../../core/INI/iem-ini.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>

using namespace FileEngine::INI;

int Reader::ReadShort(char *filename, char *key, short *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt(char *filename, char *key, int *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadLong(char *filename, char *key, long *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stol(&filelines_buffer[index][key_length+3], &p_index, 10);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadLongLong(char *filename, char *key, long long *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index, 10);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadFloat(char *filename, char *key, float *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stof(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadDouble(char *filename, char *key, double *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stof(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadBool(char *filename, char *key, bool *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;
		bool temp_variable = false;
		bool wrong_bool_val = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					strcpy(filelines_buffer[index], buffer);
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						temp_variable = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
						if(temp_variable == 0 || temp_variable == 1)
						{
							*value = temp_variable;
						}
						else
						{
							memset(buffer, 0, sizeof(buffer));
							memset(filelines_buffer, 0, sizeof(filelines_buffer));
							fclose(read_handle);
							wrong_bool_val = true;
						}
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}

		if(wrong_bool_val == true)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_READBOOL_WRONG_VALUE;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt8(char *filename, char *key, int8_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt16(char *filename, char *key, int16_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt32(char *filename, char *key, int32_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt64(char *filename, char *key, int64_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint8(char *filename, char *key, uint8_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint16(char *filename, char *key, uint16_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint32(char *filename, char *key, uint32_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint64(char *filename, char *key, uint64_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadChar(char *filename, char *key, char value[1])
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{			
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						sprintf(value, "%c", filelines_buffer[index][key_length+3]);
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadCString(char *filename, char *key, char *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = filelines_buffer[index][key_length+3];
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadString(char *filename, char *key, std::string *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		bool key_check = false;

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);
				if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
				{
					buffer[key_length] = '\0';
					if(strcmp(buffer, key) == 0)
					{
						*value = filelines_buffer[index][key_length+3];
						key_check = true;
						break;
					}
				}
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

// Sections

int Reader::ReadShort(char *section, char *filename, char *key, short *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt(char *section, char *filename, char *key, int *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadLong(char *section, char *filename, char *key, long *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stol(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadLongLong(char *section, char *filename, char *key, long long *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadFloat(char *section, char *filename, char *key, float *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stof(&filelines_buffer[index][key_length+3], &p_index);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadDouble(char *section, char *filename, char *key, double *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stof(&filelines_buffer[index][key_length+3], &p_index);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadBool(char *section, char *filename, char *key, bool *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool temp_variable = false;
		bool wrong_bool_val = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							temp_variable = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							if(temp_variable == 0 || temp_variable == 1)
							{
								*value = temp_variable;
							}
							else
							{
								memset(buffer, 0, sizeof(buffer));
								memset(filelines_buffer, 0, sizeof(filelines_buffer));
								fclose(read_handle);
								wrong_bool_val = true;
							}
							key_check = true;
							section_entries_parse = false;
							break;
						}

					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt8(char *section, char *filename, char *key, int8_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt16(char *section, char *filename, char *key, int16_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt32(char *section, char *filename, char *key, int32_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadInt64(char *section, char *filename, char *key, int64_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint8(char *section, char *filename, char *key, uint8_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint16(char *section, char *filename, char *key, uint16_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint32(char *section, char *filename, char *key, uint32_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoi(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadUint64(char *section, char *filename, char *key, uint64_t *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = std::stoll(&filelines_buffer[index][key_length+3], &p_index, 10);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadChar(char *section, char *filename, char *key, char *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							sprintf(value, "%c", filelines_buffer[index][key_length+3]);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadCString(char *section, char *filename, char *key, char *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							sprintf(value, "%s", &filelines_buffer[index][key_length+3]);
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}

int Reader::ReadString(char *section, char *filename, char *key, std::string *value)
{
	if(File::Exists(filename))
	{
		FILE* read_handle = fopen(filename, "r");
		uint32_t index = 0;
		size_t p_index = 0;
		uint32_t key_length = strlen(key);
		uint32_t section_length = strlen(section);
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;

		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}

		if((key_length + 1) < Settings::MAX_KEY_SIZE)
		{
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				buffer[strcspn(buffer, "\n")] = 0;
				strcpy(filelines_buffer[index], buffer);

				if(strcmp(filelines_buffer[index], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[index], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[index][0] != ';' || filelines_buffer[index][0] != '/' || filelines_buffer[index][0] != '#' || filelines_buffer[index][0] != '*' || filelines_buffer[index][0] != '[' || filelines_buffer[index][0] != ' ')
					{
						buffer[key_length] = '\0';
						if(strcmp(buffer, key) == 0)
						{
							*value = &filelines_buffer[index][key_length+3];
							key_check = true;
							section_entries_parse = false;
							break;
						}
					}
					printf("filelines_buffer = %s\n", filelines_buffer[index]);
				}
				
				index++;
			}
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			fclose(read_handle);
			return E_INI_KEY_NOT_FOUND;
		}


		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		fclose(read_handle);
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
	return E_INI_SUCCESS;
}



