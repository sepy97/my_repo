#include <stdio.h>
#include <stdlib.h>

double mystrtod (const char* input, char** endptr);

int main() //made without exponential form
{
    char* str = "97,25";
    double num = mystrtod (str, NULL);
    double ctrlnum = strtod (str, NULL);
    
    if (num == ctrlnum) printf ("GOOD\n");
    else printf("VERY BAD\n");
    //printf("%lg\n", num);
}

double mystrtod (const char* input, char** endptr)
{
    double resultnum = 0;
    double resultden = 0;
    int isnumerator = 1;
    int isminus = 0;
    int counttens = 0;
    int i = 0;
    char c = input[i];
    while (c != '\0')
    {
        if (c == '+' && i != 0) return 0;
        else if (c == '-')
        {
            if (i == 0) isminus = 1;
            else return 0;
        }
        else if (c == '.') isnumerator = 0;
        else if (c >= '0' && c <= '9')
        {
            if (isnumerator)
            {
                resultnum *= 10;
                resultnum += c - '0';
            }
            else
            {
                resultden *= 10;
                resultden += c - '0';
                counttens++;
            }
        }
        else
        {
            return resultnum;
        }
        i++;
        c = input[i];
    }
    
    for (int i = 0; i < counttens; i++)
    {
        resultden /= 10;
    }
    
    resultnum += resultden;
    if (isminus) resultnum *= -1;
    
    return resultnum;
}