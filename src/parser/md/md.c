#include "../../../include/imports.h"

#include <string.h>
#include <stdio.h>

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

void WriteHTML(
    char Line[],
    const char FILE_PATH[],
    char TagStart[],
    char TagEnd[],
    const int ESCAPE_TAG,
    const int RAW_TAG,
    char Tag[]
){
    // Line = String we are checking inside
    // FILE_PATH = File to write to
    // ESCAPE_LIMIT = Escaped Tag we don't want to check for
    // ESCAPE_TAG = Escaped Tag we are excluding
    // RAW_LIMIT = Tag we don't want to check for
    // RAW_TAG = Tag we need to replace
    // Tag = Tag to target
    // TagStart = HTML tag start
    // TagEnd = HTML tag end


}

void Parse(char Line[], const char FILE_PATH[])
{
    if (
        strncmp(Line, "# ", strlen("# ")) == 0
    ){
        RemoveKey(Line, "#");

        char* Prepend = AddTags(Line, "<h1>", 'p');

        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, "</h1>", 'a');

        Transpile(Final, FILE_PATH);
    }

    else if (
        strncmp(Line, "## ", strlen("## ")) == 0
    ){
        RemoveKey(Line, "##");

        char* Prepend = AddTags(Line, "<h2>", 'p');

        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, "</h2>", 'a');

        Transpile(Final, FILE_PATH);
    }

    else
        Transpile(Line, FILE_PATH);
}
