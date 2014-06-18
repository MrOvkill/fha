/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.0.1
    * Date: 06/18/2014

*/

#ifndef FHA_H
#define FHA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

char* __fhaStr;
int __fhaLength;

void fhaInit(char* file);
char* fhaHash();
void fhaClear();

#endif
