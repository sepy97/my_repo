#include <stdio.h>

int Input (char name[], char input[]);

int deletespace (char input[], char output[], int size);

int main()
{
    printf ("Deleting of spaces mk1 by SEPY \n");
    
    char inputstring[100000];
    int size = Input ("string", inputstring);
    
    char resultstr[100000];
    int newsize = deletespace (inputstring, resultstr, size);
    
    for (int i = 0; i < newsize; i++)
    {
        printf ("%c", resultstr[i]);
    }
}

int Input (char name[], char input[])
{
    printf ("Input %s -> ", name);
    int size = 0;
    char c;
    c = getchar();
    while (c != EOF)
    {
        size++;
        input[size-1] = c;
        c = getchar();
    }
    return size;
}

int deletespace (char input[], char output[], int size)
{
    int numofspace = 0;
    int newsize = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == ' ' && numofspace == 0)
        {
            numofspace++;
            newsize++;
            output[newsize-1] = input[i];
        }
        else if (input[i] == ' ' && numofspace > 0) numofspace++;
        else if (input[i] != ' ')
        {
            numofspace = 0;
            newsize++;
            output[newsize-1] = input[i];
        }
    }
    return newsize;
}