#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void preprocessMasks(char *pattern, int m, unsigned long *M);

bool shiftAndSearch(char *text, int n, char *pattern, int m);

#endif