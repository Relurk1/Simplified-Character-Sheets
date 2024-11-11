#include <string.h>
#include "model.h"



Skills skillStrToEnum (const char *str) {
    int i;
    for (i = 0;  i < sizeof (skillConversion) / sizeof (skillConversion[0]);  i++)
        if (!strcmp (str, skillConversion[i].str))
            return skillConversion[i].val;    
    return NONE;
}

