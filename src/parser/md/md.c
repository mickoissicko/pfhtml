#include "../../../include/imports.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void MoveString(char String[], size_t Length)
{
    memmove(String, String + Length, strlen(String) - Length);
}

void RemoveKey(char Line[], char Tag[])
{
    if (strncmp(Line, Tag, strlen(Tag)) == 0)
        MoveString(Line, strlen(Tag));
}

int WriteHTML(
    char Line[],
    const char FILE_PATH[],
    char TagStart[],
    char TagEnd[],
    char Tag[]
){
    char RawTag[(strlen(Tag)) + 2];
    snprintf(RawTag, sizeof(RawTag), "%s ", Tag);

    if (strncmp(Line, RawTag, strlen(RawTag)) == 0)
    {
        RemoveKey(Line, RawTag);

        char* Prepend = AddTags(Line, TagStart, 'p');

        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, TagEnd, 'a');

        Transpile(Final, FILE_PATH);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

void InsertBreaks(char Escape[], int Symbol, char Tag[], char Line[], const char FILE_PATH[])
{
    // if Line has $ but not \$, proceed

    char Result[MAX_LINE_LENGTH];

    char* Cursor = Line;
    char* Buffer = Result;

    while (*Cursor)
    {
        if (*Cursor == Symbol && (Cursor == Line || *(Cursor - 1) != '\\'))
        {
            strcpy(Buffer, Tag);
            Buffer += strlen(Tag);
        }

        else
            *Buffer++ = *Cursor;

        Cursor++;
    }

    *Buffer = '\0';
    strcpy(Line, Result);
}

void DeleteBackslashes(char Line[])
{
    int Index = 0, Cursor = 0;

    while (Line[Index] != '\0')
    {
        if (Line[Index] != '\\')
            Line[Cursor++] = Line[Index];

        Index++;
    }

    Line[Cursor] = '\0';
}

void ParseMarkdown(char Line[], const char FILE_PATH[])
{
    InsertBreaks("\\$", '$', "<br>", Line, FILE_PATH);

    if (strchr(Line, '\\') != NULL)
        DeleteBackslashes(Line);

    // yea.. idk either man
    if (WriteHTML(Line, FILE_PATH, "<h1>", "</h1>", "#") != 0)
        if (WriteHTML(Line, FILE_PATH, "<h2>", "</h2>", "##") != 0)
            if (WriteHTML(Line, FILE_PATH, "<ul><li>", "</li></ul>", ">") != 0)
                Transpile(Line, FILE_PATH);
}
