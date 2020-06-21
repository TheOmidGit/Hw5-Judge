#pragma once

// declare your functions and global variables here
struct files
{
    char inputsPath[500],inputsNames[101][101];
};

struct files inputsAndFiles;

int compile();

int getTestsPath();

int generate();

