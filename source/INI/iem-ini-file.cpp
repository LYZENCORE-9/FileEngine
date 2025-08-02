#include "../../core/INI/iem-ini.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace FileEngine::INI;

bool File::Create(char *filename)
{
	FILE* handle = fopen(filename, "w");
	if(handle != NULL)
	{
		fclose(handle);
		return true;
	}
	fclose(handle);
	return false;
}

bool File::Exists(char *filename)
{
	FILE* handle = fopen(filename, "r");
	if(handle != NULL)
	{
		fclose(handle);
		return true;
	}
	fclose(handle);
	return false;
}

bool File::Delete(char *filename)
{
	if(remove(filename) == 0)
	{
		return true;
	}
	return false;
}

bool File::Rename(char *filename, char *new_name)
{
	if(File::Exists(filename))
	{
		char buffer[1024] = {0};
		size_t bytesread = 0;
		FILE* read_handle = fopen(filename, "r");
		FILE* write_handle = fopen(new_name, "w");
		
		while((bytesread = fread(buffer, 1, sizeof(buffer), read_handle) > 0))
		{
			fwrite(buffer, 1, bytesread, write_handle);
		}

		fclose(read_handle);
		fclose(write_handle);
		memset(buffer, 0, sizeof(buffer));
		memset(&bytesread, 0, sizeof(bytesread));
		if(File::Delete(filename))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool File::Copy(char *filename, char* newfilename)
{
	if(File::Exists(filename))
	{
		char buffer[1024] = {0};
		size_t bytesread = 0;
		FILE* read_handle = fopen(filename, "r");
		FILE* write_handle = fopen(newfilename, "w");
		
		while((bytesread = fread(buffer, 1, sizeof(buffer), read_handle) > 0))
		{
			fwrite(buffer, 1, bytesread, write_handle);
		}

		fclose(read_handle);
		fclose(write_handle);
		memset(buffer, 0, sizeof(buffer));
		memset(&bytesread, 0, sizeof(bytesread));
		return true;
	}
	return false;
}

bool File::Move(char *filename, char *path)
{
	if(rename(filename, path) == 0)
	{
		return true;
	}
	return false;
}