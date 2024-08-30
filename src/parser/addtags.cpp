#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

extern "C"
{
    char* AddTags(char Line[], const char Tag[], int Mode);
}

char* AddTags(char Line[], const char Tag[], int Mode)
{
    std::string String = Line;

    if (Mode == 'p')
        String.insert(0, Tag);

    else if (Mode == 'a')
        String.append(Tag);

    char* ModifiedString = (char*)malloc(sizeof(char) * (strlen(Line) + strlen(Tag) + 1));

    snprintf(ModifiedString, (strlen(Line) + strlen(Tag) + 1), "%s", String.c_str());

    return ModifiedString;
}
