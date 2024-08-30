#include "../../include/imports.h"

#include <string.h>
#include <stdio.h>

#define SUB_HEADING_SIZE 3
#define HEADING_SIZE 2
#define TERMINATOR 1

void RemoveHash(char Line[])
{
    if (Line[0] == '#' && Line[1] == ' ')
        memmove(Line, Line + HEADING_SIZE, strlen(Line) - TERMINATOR);

    else if (Line[0] == '#' && Line[1] == '#' && Line[2] == ' ')
        memmove(Line, Line + SUB_HEADING_SIZE, strlen(Line) - TERMINATOR);
}

void Parse(char Line[])
{
    char StartTag[] = "<h1>";
    char EndTag[] = "</h1>";

    char* EscapeTag = strstr(Line, "\\#");
    char* RawTag = strstr(Line, "# ");

    if (RawTag && !EscapeTag)
    {
        RemoveHash(Line);

        char* Prepend = AddTags(Line, StartTag, 'p');

        Prepend[strcspn(Prepend, "\n")] = '\0';

        char* Final = AddTags(Prepend, EndTag, 'a');

        Transpile(Final);
    }
}
