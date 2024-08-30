#ifndef IMPORTS_H
#define IMPORTS_H

#include <stdio.h>

char* FileHandler(const char FILE_PATH[], FILE* File, char String[], const char Mode[]);
char* AddTags(char Line[], const char Tag[], int Mode);

void FileManager(char FilePath[], char String[], const char Mode[]);
void Transpile(char String[], const char FILE_PATH[]);
void Parse(char Line[], const char FILE_PATH[]);

#endif //IMPORTS_H
