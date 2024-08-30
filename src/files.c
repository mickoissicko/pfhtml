#include "../include/imports.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void FileManager(char FilePath[], char String[], const char Mode[])
{
    FILE* File = fopen(FilePath, Mode);

    if (File == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }

    FileHandler(File, String, Mode);
    fclose(File);
}

char* FileHandler(FILE* File, char String[], const char Mode[])
{
    size_t MAX_LINE_LENGTH = 2048;

    char* Line = (char*)malloc(sizeof(char) * MAX_LINE_LENGTH);

    if (strcmp(Mode, "r") == 0)
    {
        while (fgets(Line, MAX_LINE_LENGTH, File) != NULL)
            Transpile(Line);
    }

    else
    {
        if (strcmp(String, NULL) == 0 || strcmp(String, "NULL") == 0)
        {
            printf("Malformed or NULL string!\n");
            exit(1);
        }

        //
    }

    return Line;
}
