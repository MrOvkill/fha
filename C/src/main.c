/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.1.0
    * Date: 06/18/2014

*/

#include "fha/fha.h"

FILE* f;

int ivc(char c)
{
    int i;
    for(i = 33; i < 123; i++)
    {
        if(c == i)
        {
            return 1;
        }
    }
    return 0;
}

int gvl(char* str)
{
    int len = strlen(str);
    int i;
    int vlen = 0;
    for(i = 0; i < len; i++)
    {
        if(ivc(str[i]))
        {
            vlen++;
        }
    }
    return vlen;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    
    f = fopen(argv[1], "r");
    
    if(!f)
    {
        printf("Error: No such file \"%s\"\n", argv[1]);
        return 0;
    }
    
    fseek(f, 0L, SEEK_END);
    
    int size = ftell(f);
    
    fseek(f, 0L, SEEK_SET);
    
    char* str = (char*)malloc(sizeof(char)*size);
    
    int i;
    char c;
    for(i = 0; i < size; i++)
    {
        c = fgetc(f);
        str[i] = c;
    }
    
    char* sstr = (char*)malloc(sizeof(char)*gvl(str));
    
    int p = 0;
    
    for(i = 0; i < size; i++)
    {
        if(ivc(str[i]))
        {
            sstr[p] = str[i];
            p++;
        }
    }
    
    fhaInit(sstr);
    printf("%s\n", fhaHash());
    fhaClear();
    return 0;
}
