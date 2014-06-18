/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.1.0
    * Date: 06/18/2014

*/

#include "fha/fha.hpp"

int randr(int min, int max)
{
    double scaled = (double)rand()/RAND_MAX;
    return (max - min +1)*scaled + min;
}

Fha::Fha(char* file)
{
    length = strlen(file);
    str = (char*)malloc(sizeof(char)*length);
    int i;
    for(i = 0; i < length; i++)
    {
        str[i] = file[i];
    }
}

char* Fha::hash()
{
    char* hash = (char*)malloc(sizeof(char)*length);
    
    int stc = 0;
    
    int i;
    for(i = 0; i < length; i++)
    {
        stc += ((int)str[i]*i);
    }
    
    while(stc < 100000)
    {
        stc -= 100;
    }
    
    srand(length+stc);
    
    for(i = 0; i < length; i++)
    {
        hash[i] = randr(33, 123);
    }
    
    return hash;
}

void Fha::clear()
{
    free(str);
    length = 0;
}
