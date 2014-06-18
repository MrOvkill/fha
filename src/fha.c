/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.0.1
    * Date: 06/18/2014

*/

#include "fha/fha.h"

int randr(int min, int max)
{
    double scaled = (double)rand()/RAND_MAX;
    return (max - min +1)*scaled + min;
}

void fhaInit(char* file)
{
    __fhaLength = strlen(file);
    __fhaStr = (char*)malloc(sizeof(char)*__fhaLength);
    int i;
    for(i = 0; i < __fhaLength; i++)
    {
        __fhaStr[i] = file[i];
    }
}

char* fhaHash()
{
    char* hash = (char*)malloc(sizeof(char)*__fhaLength);
    
    int stc = 0;
    
    int i;
    for(i = 0; i < __fhaLength; i++)
    {
        stc += ((int)__fhaStr[i]*i);
    }
    
    while(stc < 100000)
    {
        stc -= 100;
    }
    
    srand(__fhaLength+stc);
    
    for(i = 0; i < __fhaLength; i++)
    {
        hash[i] = randr(33, 123);
    }
    
    return hash;
}

void fhaClear()
{
    free(__fhaStr);
    __fhaLength = 0;
}
