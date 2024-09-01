#include "../../../include/imports.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const static int True = 1;

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

void ParseMarkdown(char Line[], const char FILE_PATH[])
{
    // yea.. idk either man

    if (WriteHTML(Line, FILE_PATH, "<h1>", "</h1>", "#") != 0)
        if (WriteHTML(Line, FILE_PATH, "<h2>", "</h2>", "##") != 0)
            if (WriteHTML(Line, FILE_PATH, "<ul><li>", "</li></ul>", ">") != 0)
                Transpile(Line, FILE_PATH);
}
