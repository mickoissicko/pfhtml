#include "../include/imports.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_FILE_NAME 64

int main(int argc, char* argv[])
{
    char Filename[MAX_FILE_NAME];

    if (argc < 2)
    {
        printf("Usage: %s -f <filename>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-f") == 0)
    {
        if (strlen(argv[2]) > MAX_FILE_NAME)
        {
            printf("You know exactly why this happened, don't you?\n");
            exit(1);
        }

        strcpy(Filename, argv[2]);
    }

    FileManager(Filename, NULL, "r");
}
