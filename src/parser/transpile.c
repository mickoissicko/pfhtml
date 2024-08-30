#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_FILENAME_LENGTH 128
#define MAX_LINE_LENGTH 8192

void AppendString(char String[], const char FILE_PATH[])
{
    FILE* Result = fopen(FILE_PATH, "a");

    if (Result == NULL)
    {
        perror("Could not open file");
        fclose(Result);
        exit(1);
    }

    String[strcspn(String, "\n")] = '\0';

    fprintf(Result, "%s\n", String);
    fclose(Result);
}

void Transpile(char String[], const char FILE_PATH[])
{
    char ProcessedFilePath[MAX_FILENAME_LENGTH];
    snprintf(ProcessedFilePath, MAX_FILENAME_LENGTH, "%s.html", FILE_PATH);

    AppendString(String, ProcessedFilePath);
}
