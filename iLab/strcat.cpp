#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrcat (char* first, char* second);

int main()
{
    char* first  = "first string\0                    ";
    char* second =              "adding second string";
    
    mystrcat (first, second);
    // почему-то не выводится нормальный first!!!
    printf("%s \n", first);
}

int mystrcat (char* first, char* second)
{
    int firstsize  = strlen (first);
    int secondsize = strlen (second);
    for (int i = firstsize; i < firstsize + secondsize; i++)
    {
        int j = i - firstsize;
        first[j+1] = second[i+1];
    }
    return 0;
}