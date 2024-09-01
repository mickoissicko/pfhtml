#include "../include/imports.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define PATH_FILE "path.txt"
#define MAX_FILE_PATH 128

char* FileHandler(const char FILE_PATH[], FILE* File, char String[], const char Mode[])
{
    size_t MAX_LINE_LENGTH = 2048;

    char* Line = (char*)malloc(sizeof(char) * MAX_LINE_LENGTH);

    if (strcmp(Mode, "r") == 0)
    {
        char FinalFilePath[MAX_FILE_PATH];
        char FilePath[MAX_FILE_PATH];
        strcpy(FilePath, FILE_PATH);

        FILE* Path = fopen(PATH_FILE, "w");

        int Max = strlen(FilePath);
        int Index = 0;

        while (Index < (Max - strlen(".md")))
            fputc(FilePath[Index++], Path);

        fclose(Path);

        FILE* ReadPath = fopen(PATH_FILE, "r");
        fgets(FinalFilePath, MAX_FILE_PATH, ReadPath);
        fclose(ReadPath);

        FinalFilePath[strcspn(FinalFilePath, "\n")] = '\0';

        while (fgets(Line, MAX_LINE_LENGTH, File) != NULL)
            ParseMarkdown(Line, FinalFilePath);
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

void FileManager(char FilePath[], char String[], const char Mode[])
{
    FILE* File = fopen(FilePath, Mode);

    if (File == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }

    FileHandler(FilePath, File, String, Mode);
    fclose(File);
}
