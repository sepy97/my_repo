#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    assert (first != NULL);
    assert (second != NULL);
    
    int firstsize  = strlen (first);
    int secondsize = strlen (second);
    for (int i = firstsize; i < firstsize + secondsize; i++)
    {
        assert (i < strlen (first) + strlen (second));
        
        int j = i - firstsize;
        assert (j < strlen (first));
        
        first[j] = second[i];
        
    }
    return 0;
}