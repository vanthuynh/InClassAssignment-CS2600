#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

/* const variable declaration */
extern const int MAX_BOUND;
enum {DEFAULT_MAX = 10};

void clean_stdin();
int getUserInt(char *prompt);
int getBoundedInt(char *prompt, int lowBound, int highBound);
int getInputWithStopSignal(char *prompt, int lowBound, int highBound);
double getUserDouble(char *prompt);
double getBoundedDouble(char *prompt, double lowBound, double highBound);
int getBool(char *prompt);

#endif