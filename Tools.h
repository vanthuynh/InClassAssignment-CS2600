#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int getUserInt(char *prompt);
int getBoundedInt(char *prompt, int lowBound, int highBound);
double getUserDouble(char *prompt);
double getBoundedDouble(char *prompt, double lowBound, double highBound);
int getBool(char *prompt);

#endif