#include "../../../include/imports.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

char* WriteHTML(
    char Line[],
    char TagStart[],
    char TagEnd[],
    char Tag[]
){
    static char Result[MAX_LINE_LENGTH];

    if (strcmp(Tag, "*") == 0)
    {
        char EscapeTag[(strlen(Tag) + 1)];

        int Index = 0, Cursor = 0;
        int TagCount = 0;

        snprintf(EscapeTag, sizeof(EscapeTag), "\\%s", Tag);

        while (Line[Index] != '\0')
        {
            if (Line[Index] == '*' && (Index == 0 || Line[Index - 1] != '\\'))
            {
                if (TagCount)
                    Result[Cursor++] = '<',
                    Result[Cursor++] = '/',
                    Result[Cursor++] = 'e',
                    Result[Cursor++] = 'm',
                    Result[Cursor++] = '>',
                    TagCount = 0;

                else
                    Result[Cursor++] = '<',
                    Result[Cursor++] = 'e',
                    Result[Cursor++] = 'm',
                    Result[Cursor++] = '>',
                    TagCount = 1;

                Index++;
            }

            else
                Result[Cursor++] = Line[Index++];
        }

        Result[Cursor] = '\0';
        return Result;
    }

    char RawTag[(strlen(Tag)) + 2];
    snprintf(RawTag, sizeof(RawTag), "%s ", Tag);

    if (strncmp(Line, RawTag, strlen(RawTag)) == 0)
    {
        RemoveKey(Line, RawTag);

        char* Prepend = AddTags(Line, TagStart, 'p');
        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, TagEnd, 'a');
        strncpy(Result, Final, MAX_LINE_LENGTH);
        return Result;
    }

    return Line;
}

void InsertBreaks(
    int Symbol,
    char Tag[],
    char Line[]
){
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
    InsertBreaks('$', "<br>", Line);

    char* Format;

    Format = WriteHTML(Line, "<h1>", "</h1>", "#");
    Format = WriteHTML(Format, "<h2>", "</h2>", "##");
    Format = WriteHTML(Format, "<ul><li>", "</li></ul>", ">");
    Format = WriteHTML(Format, "<em>", "</em>", "*");

    DeleteBackslashes(Format);

    Transpile(Format, FILE_PATH);
}
