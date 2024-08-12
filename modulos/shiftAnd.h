#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void preprocessShiftAnd(char *pattern, int m, bool **M);

void shiftRight(bool *R, int m);

bool shiftAndSearch(char *text, int n, char *pattern, int m);

#endif