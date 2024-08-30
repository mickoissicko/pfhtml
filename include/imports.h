#ifndef IMPORTS_H
#define IMPORTS_H

#include <stdio.h>

char* FileHandler(FILE* File, char String[], const char Mode[]);
char* AddTags(char Line[], const char Tag[], int Mode);

void FileManager(char FilePath[], char String[], const char Mode[]);
void Transpile(char String[]);
void Parse(char Line[]);

#endif //IMPORTS_H
