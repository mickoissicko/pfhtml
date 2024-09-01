#include "../../../include/imports.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void MoveString(char String[], size_t Length)
{
    memmove(String, String + Length, strlen(String) - Length);
}

void RemoveKey(char Line[], char Tag[])
{
    if (strcmp(Tag, "#") == 0)
        if (strncmp(Line, "# ", strlen("# ")) == 0)
            MoveString(Line, strlen("# "));

    if (strcmp(Tag, "##") == 0)
        if (strncmp(Line, "## ", strlen("## ")) == 0)
            MoveString(Line, strlen("## "));
}

int WriteHTML(
    char Line[],
    const char FILE_PATH[],
    char TagStart[],
    char TagEnd[],
    const char RAW_TAG[],
    char Tag[]
){
    if (
        strncmp(Line, RAW_TAG, strlen(RAW_TAG)) == 0
    ){
        RemoveKey(Line, Tag);

        char* Prepend = AddTags(Line, TagStart, 'p');

        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, TagEnd, 'a');

        Transpile(Final, FILE_PATH);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

void Parse(char Line[], const char FILE_PATH[])
{
    // TODO: make reader & parser
}
