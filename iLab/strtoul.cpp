#include <stdio.h>
#include <stdlib.h>

long mystrtoul (char* str, char endptr, int base);

int main()
{
    char* str = "1560";
    
    long num = mystrtoul (str, NULL, 7);
    unsigned long ctrlnum = strtoul (str, NULL, 7);
    
    if (num < 0) printf("This function can't convert this string into unsigned long!!\n");
    
    if (num == ctrlnum) printf("GOOD\n");
    else printf ("VERY BAD\n");
}

long mystrtoul (char* str, char endptr, int base)
{
    unsigned long result = 0;
    int i = 0;
    char cur = str[i];
    while (cur != endptr)
    {
        result *= base;
        if (cur >= '0' && cur <= '9')
        {
            result += cur-'0';
        }
        else if (cur >= 'A' && cur <= 'Z')
        {
            result += cur - 'A' + 10;
        }
        i++;
        cur = str[i];
    }
    return result;
}