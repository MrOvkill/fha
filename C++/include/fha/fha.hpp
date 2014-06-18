/*

    * Author: Samuel "MrOverkill" Meyers
    * License: GPL v3
    * Version: 0.1.0
    * Date: 06/18/2014

*/

#ifndef FHA_H
#define FHA_H

#include <cstdlib>
#include <cstring>
#include <cstdio>

class Fha
{
    final:
        VERSION_MAJOR = 0;
        VERSION_MINOR = 1;
        REVISION = 0;
    private:
        char* str;
        int length;
    public:
        Fha(char* file);
        char* hash();
        void clear();
};

#endif
