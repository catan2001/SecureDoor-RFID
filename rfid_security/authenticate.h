#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include "stdio.h"
#include "string.h"
#include "sha256.h"

#define ERROR_FILE -202
#define ERROR_SHA -303
#define ERROR_WRNG_PASS -505
#define SUCCESS_PASS 0

int authenticate(char *);

#endif // AUTHENTICATE_H
