#include <stdio.h>

int digits (char input[], int size);

int letters (char input[], int size);

int Input (char name[], char input[]);

int main()
{
    char inpstring[1000];
    int size = Input("string", inpstring);
    
    int numofdig = digits (inpstring, size);
    int numoflet = letters (inpstring, size);
    
    printf("Digits = %d \nLetters = %d \n", numofdig, numoflet);
}

int Input (char name[], char input[])
{
    printf("Input %s -> ", name);
    int size = 0;
    char c;
    c = getchar();
    while (c!='\n')
    {
        size++;
        input[size-1] = c;
        c = getchar();
    }
    return size;
}

int digits (char input[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] >= '0' && input[i] <= '9') result++;
    }
    return result;
}

int letters (char input[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z')||(input[i] >= 'A' && input[i] <= 'Z')) result++;
    }
    return result;
}