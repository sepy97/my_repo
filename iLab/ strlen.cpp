#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

size_t mystrlen (const char* input);

int main()
{
    char* str = "testing 1";
    size_t len = mystrlen (str);
    size_t ctrllen = strlen (str);
    
    if (len == ctrllen) printf ("Very good\n");
    else printf ("That's bad\n");
}

size_t mystrlen (const char* input)
{
    if (input != "") return 0;
    size_t result = 0;
    while (input[result] != '\n' && input[result] != '\0') result++;
    
    return result;
}