#include "../../core/INI/iem-ini.h"
#include <cstdint>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace FileEngine::INI;

int Writter::WriteShort(char *filename, char *key, short *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt(char *filename, char *key, int *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteLong(char *filename, char *key, long *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%ld", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %ld", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
							memset(buffer_newline, 0, sizeof(buffer_newline));
							memset(key_buffer, 0, sizeof(key_buffer));
							memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteLongLong(char *filename, char *key, long long *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %lld", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
							memset(filelines_buffer, 0, sizeof(filelines_buffer));
							memset(buffer_newline, 0, sizeof(buffer_newline));
							memset(key_buffer, 0, sizeof(key_buffer));
							memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteFloat(char *filename, char *key, float *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%f", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %f", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteDouble(char *filename, char *key, double *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%f", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %f", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
								memset(filelines_buffer, 0, sizeof(filelines_buffer));
								memset(buffer_newline, 0, sizeof(buffer_newline));
								memset(key_buffer, 0, sizeof(key_buffer));
								memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteBool(char *filename, char *key, bool *value)
{
	if(*value == 1 || *value == 0)
	{
		if(File::Exists(filename))
		{
			printf("WriteShort Declared\n");
			int key_length = strlen(key);
			char value_string[Settings::MAX_VALUE_SIZE] = {0};
			sprintf(value_string, "%d", *value);
			int value_length = strlen(value_string);
			FILE* read_handle = fopen(filename, "r");

			uint32_t index = 0;
			char buffer[Settings::MAX_BUFFER_SIZE] = {0};
			char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
			char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

			char key_buffer[Settings::MAX_KEY_SIZE] = {0};
			char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
			bool key_check = false;

			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				strcpy(filelines_buffer[index], buffer);
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}

			fclose(read_handle);


			for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}

			FILE* write_handle = fopen(filename, "w");
			for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
			{
				filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
				if(filelines_buffer[i][0] != 0)
				{
					fprintf(write_handle, "%s\n", filelines_buffer[i]);
					printf("fprintf = %s\n", filelines_buffer[i]);
				}
			}
			fclose(write_handle);

			if(key_check == false)
			{
				memset(buffer, 0, sizeof(buffer));
				memset(filelines_buffer, 0, sizeof(filelines_buffer));
				memset(buffer_newline, 0, sizeof(buffer_newline));
				memset(key_buffer, 0, sizeof(key_buffer));
				memset(value_buffer, 0, sizeof(value_buffer));
				return E_INI_KEY_NOT_FOUND;
			}
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_SUCCESS;
		}
		else
		{

			return E_INI_FILE_NOT_FOUND;
		}
	}
	else
	{
		return E_INI_WRITEBOOL_WRONG_VALUE;
	}
}

int Writter::WriteChar(char *filename, char *key, char value[1])
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		int value_length = strlen(value);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %c", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteCString(char *filename, char *key, char *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		int value_length = strlen(value);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %s", key, value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteString(char *filename, char *key, std::string *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		uint32_t value_length = value->length();
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %s", key, value->c_str());
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt8(char *filename, char *key, int8_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt16(char *filename, char *key, int16_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt32(char *filename, char *key, int32_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt64(char *filename, char *key, int64_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %lld", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint8(char *filename, char *key, uint8_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint16(char *filename, char *key, uint16_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint32(char *filename, char *key, uint32_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %d", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint64(char *filename, char *key, uint64_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		int key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		int value_length = strlen(value_string);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		bool key_check = false;

		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
			{
				if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
				{
					if(filelines_buffer[i][key_length+1] == '=')
					{
						strcpy(buffer, filelines_buffer[i]);
						buffer[key_length] = '\0';
						printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
						if(strcmp(key, buffer) == 0)
						{
							sprintf(buffer_newline, "%s = %lld", key, *value);
							strcpy(filelines_buffer[i], buffer_newline);
							printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
							key_check = true;
							break;
						}
						memset(buffer, 0, sizeof(buffer));
					}
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					memset(filelines_buffer, 0, sizeof(filelines_buffer));
					memset(buffer_newline, 0, sizeof(buffer_newline));
					memset(key_buffer, 0, sizeof(key_buffer));
					memset(value_buffer, 0, sizeof(value_buffer));
					return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
				}
			}
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			return E_INI_KEY_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

// Section Writters

int Writter::WriteShort(char *section, char *filename, char *key, short *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt(char *section, char *filename, char *key, int *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteLong(char *section, char *filename, char *key, long *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%ld", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %ld", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteLongLong(char *section, char *filename, char *key, long long *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %lld", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteFloat(char *section, char *filename, char *key, float *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%f", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %f", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteDouble(char *section, char *filename, char *key, double *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%f", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %f", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteBool(char *section, char *filename, char *key, bool *value)
{
	if(*value == 1 || *value == 0)
	{
		if(File::Exists(filename))
		{
			printf("WriteShort Declared\n");
			uint32_t key_length = strlen(key);
			char value_string[Settings::MAX_VALUE_SIZE] = {0};
			sprintf(value_string, "%d", *value);
			uint32_t value_length = strlen(value_string);
			uint32_t section_length = strlen(section);
			FILE* read_handle = fopen(filename, "r");

			uint32_t index = 0;
			char buffer[Settings::MAX_BUFFER_SIZE] = {0};
			char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
			char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

			char key_buffer[Settings::MAX_KEY_SIZE] = {0};
			char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
			char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
			char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
			bool key_check = false;
			bool section_check = false;
			bool section_entries_parse = false;
			sprintf(section_buffer, "[%s section begin]", section);
			sprintf(section_end_buffer, "[%s section end]", section);
			if(section_length + 2 > Settings::MAX_SECTION_SIZE)
			{
				memset(buffer, 0, sizeof(buffer));
				memset(filelines_buffer, 0, sizeof(filelines_buffer));
				memset(buffer_newline, 0, sizeof(buffer_newline));
				memset(key_buffer, 0, sizeof(key_buffer));
				memset(value_buffer, 0, sizeof(value_buffer));
				memset(section_buffer, 0, sizeof(section_buffer));
				memset(section_end_buffer, 0, sizeof(section_end_buffer));
				return E_INI_SECTION_PASSED_BUFFER_SIZE;
			}
			while(fgets(buffer, sizeof(buffer), read_handle))
			{
				strcpy(filelines_buffer[index], buffer);
				printf("filelines_buffer = %s\n", filelines_buffer[index]);
				index++;
			}

			fclose(read_handle);


			for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
			{
				filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
				if(strcmp(filelines_buffer[i], section_buffer) == 0)
				{
					printf("Section Declared true\n");
					section_entries_parse = true;
					section_check = true;
				}

				if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
				{
					printf("Section Declared false\n");
					section_entries_parse = false;
				}

				if(section_entries_parse == true)
				{
					if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
					{
						if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
						{
							if(filelines_buffer[i][key_length+1] == '=')
							{
								strcpy(buffer, filelines_buffer[i]);
								buffer[key_length] = '\0';
								printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
								if(strcmp(key, buffer) == 0)
								{
									sprintf(buffer_newline, "%s = %d", key, *value);
									strcpy(filelines_buffer[i], buffer_newline);
									printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
									key_check = true;
									section_entries_parse = false;
									break;
								}
								memset(buffer, 0, sizeof(buffer));
							}
						}
						else
						{
							memset(buffer, 0, sizeof(buffer));
							memset(filelines_buffer, 0, sizeof(filelines_buffer));
							memset(buffer_newline, 0, sizeof(buffer_newline));
							memset(key_buffer, 0, sizeof(key_buffer));
							memset(value_buffer, 0, sizeof(value_buffer));
							memset(section_buffer, 0, sizeof(section_buffer));
							memset(section_end_buffer, 0, sizeof(section_end_buffer));
							return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
						}
					}
				}
				
			}

			FILE* write_handle = fopen(filename, "w");
			for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
			{
				filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
				if(filelines_buffer[i][0] != 0)
				{
					fprintf(write_handle, "%s\n", filelines_buffer[i]);
					printf("fprintf = %s\n", filelines_buffer[i]);
				}
			}
			fclose(write_handle);
	
			if(key_check == false)
			{
				memset(buffer, 0, sizeof(buffer));
				memset(filelines_buffer, 0, sizeof(filelines_buffer));
				memset(buffer_newline, 0, sizeof(buffer_newline));
				memset(key_buffer, 0, sizeof(key_buffer));
				memset(value_buffer, 0, sizeof(value_buffer));
				memset(section_buffer, 0, sizeof(section_buffer));
				memset(section_end_buffer, 0, sizeof(section_end_buffer));
				return E_INI_KEY_NOT_FOUND;
			}
	
			if(section_check == false)
			{
				memset(buffer, 0, sizeof(buffer));
				memset(filelines_buffer, 0, sizeof(filelines_buffer));
				memset(buffer_newline, 0, sizeof(buffer_newline));
				memset(key_buffer, 0, sizeof(key_buffer));
				memset(value_buffer, 0, sizeof(value_buffer));
				memset(section_buffer, 0, sizeof(section_buffer));
				memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
			}
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SUCCESS;
		}
		else
		{
			return E_INI_FILE_NOT_FOUND;
		}
	}
	else
	{
		return E_INI_WRITEBOOL_WRONG_VALUE;
	}
}

int Writter::WriteInt8(char *section, char *filename, char *key, int8_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt16(char *section, char *filename, char *key, int16_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt32(char *section, char *filename, char *key, int32_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteInt64(char *section, char *filename, char *key, int64_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %lld", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint8(char *section, char *filename, char *key, uint8_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint16(char *section, char *filename, char *key, uint16_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint32(char *section, char *filename, char *key, uint32_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%d", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %d", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteUint64(char *section, char *filename, char *key, uint64_t *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%lld", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %lld", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteChar(char *section, char *filename, char *key, char value[1])
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%c", *value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %c", key, *value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteCString(char *section, char *filename, char *key, char *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%s", value);
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %s", key, value);
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}

int Writter::WriteString(char *section, char *filename, char *key, std::string *value)
{
	if(File::Exists(filename))
	{
		printf("WriteShort Declared\n");
		uint32_t key_length = strlen(key);
		char value_string[Settings::MAX_VALUE_SIZE] = {0};
		sprintf(value_string, "%s", value->c_str());
		uint32_t value_length = strlen(value_string);
		uint32_t section_length = strlen(section);
		FILE* read_handle = fopen(filename, "r");

		uint32_t index = 0;
		char buffer[Settings::MAX_BUFFER_SIZE] = {0};
		char filelines_buffer[Settings::MAX_FILE_LINES][Settings::MAX_BUFFER_SIZE] = {{0}};
		char buffer_newline[Settings::MAX_BUFFER_SIZE] = {0};

		char key_buffer[Settings::MAX_KEY_SIZE] = {0};
		char value_buffer[Settings::MAX_VALUE_SIZE] = {0};
		char section_buffer[Settings::MAX_SECTION_SIZE] = {0};
		char section_end_buffer[Settings::MAX_SECTION_SIZE] = {0};
		bool key_check = false;
		bool section_check = false;
		bool section_entries_parse = false;
		sprintf(section_buffer, "[%s section begin]", section);
		sprintf(section_end_buffer, "[%s section end]", section);
		if(section_length + 2 > Settings::MAX_SECTION_SIZE)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_PASSED_BUFFER_SIZE;
		}
		while(fgets(buffer, sizeof(buffer), read_handle))
		{
			strcpy(filelines_buffer[index], buffer);
			printf("filelines_buffer = %s\n", filelines_buffer[index]);
			index++;
		}

		fclose(read_handle);


		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(strcmp(filelines_buffer[i], section_buffer) == 0)
			{
				printf("Section Declared true\n");
				section_entries_parse = true;
				section_check = true;
			}

			if(strcmp(filelines_buffer[i], section_end_buffer) == 0)
			{
				printf("Section Declared false\n");
				section_entries_parse = false;
			}

			if(section_entries_parse == true)
			{
				if(filelines_buffer[i][0] != ';' || filelines_buffer[i][0] != '/' || filelines_buffer[i][0] != '#' || filelines_buffer[i][0] != '*' || filelines_buffer[i][0] != '[' || filelines_buffer[i][0] != ' ')
				{
					if(key_length + value_length + 2 < Settings::MAX_BUFFER_SIZE)
					{
						if(filelines_buffer[i][key_length+1] == '=')
						{
							strcpy(buffer, filelines_buffer[i]);
							buffer[key_length] = '\0';
							printf("\nBuffer %s | filelines_buffer[%d] = %s", buffer, i, filelines_buffer[i]);
							if(strcmp(key, buffer) == 0)
							{
								sprintf(buffer_newline, "%s = %s", key, value->c_str());
								strcpy(filelines_buffer[i], buffer_newline);
								printf("Declared fileline_buffer[i] = %s\n", filelines_buffer[i]);
								key_check = true;
								section_entries_parse = false;
								break;
							}
							memset(buffer, 0, sizeof(buffer));
						}
					}
					else
					{
						memset(buffer, 0, sizeof(buffer));
						memset(filelines_buffer, 0, sizeof(filelines_buffer));
						memset(buffer_newline, 0, sizeof(buffer_newline));
						memset(key_buffer, 0, sizeof(key_buffer));
						memset(value_buffer, 0, sizeof(value_buffer));
						memset(section_buffer, 0, sizeof(section_buffer));
						memset(section_end_buffer, 0, sizeof(section_end_buffer));
						return E_INI_KEY_OR_VALUE_PASSED_BUFFER_SIZE;
					}
				}
			}
			
		}

		FILE* write_handle = fopen(filename, "w");
		for(uint32_t i = 0; i < Settings::MAX_FILE_LINES; i++)
		{
			filelines_buffer[i][strcspn(filelines_buffer[i], "\n")] = 0;
			if(filelines_buffer[i][0] != 0)
			{
				fprintf(write_handle, "%s\n", filelines_buffer[i]);
				printf("fprintf = %s\n", filelines_buffer[i]);
			}
		}
		fclose(write_handle);

		if(key_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_KEY_NOT_FOUND;
		}

		if(section_check == false)
		{
			memset(buffer, 0, sizeof(buffer));
			memset(filelines_buffer, 0, sizeof(filelines_buffer));
			memset(buffer_newline, 0, sizeof(buffer_newline));
			memset(key_buffer, 0, sizeof(key_buffer));
			memset(value_buffer, 0, sizeof(value_buffer));
			memset(section_buffer, 0, sizeof(section_buffer));
			memset(section_end_buffer, 0, sizeof(section_end_buffer));
			return E_INI_SECTION_NOT_FOUND;
		}
		memset(buffer, 0, sizeof(buffer));
		memset(filelines_buffer, 0, sizeof(filelines_buffer));
		memset(buffer_newline, 0, sizeof(buffer_newline));
		memset(key_buffer, 0, sizeof(key_buffer));
		memset(value_buffer, 0, sizeof(value_buffer));
		memset(section_buffer, 0, sizeof(section_buffer));
		memset(section_end_buffer, 0, sizeof(section_end_buffer));
		return E_INI_SUCCESS;
	}
	else
	{
		return E_INI_FILE_NOT_FOUND;
	}
}