#include <stdio.h>
#include <stdlib.h>

int filter (char input[], int *size);

int Input (char name[], char input[]);

int main()
{
    printf ("Filter of symbols mk1 by SEPY!\n");
    
    char inputstr[1000];
    int size = Input ("Unfiltered string", inputstr);
    
    filter (inputstr, &size);
    
    printf("%s \n", inputstr);
    
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

int filter (char input[], int *size)
{
    int wasspace = 0;
    char *newinput = (char*)calloc (*size, sizeof(char));
    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            newinput[j] = input[i];
            j++;
            wasspace = 0;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            newinput[j] = input[i]-('A'-'a');
            j++;
            wasspace = 0;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            newinput[j] = '#';
            j++;
            wasspace = 0;
        }
        else if (input[i] == ' ' && wasspace == 0)
        {
            newinput[j] = ' ';
            j++;
            wasspace = 1;
        }
    }
    
    for (int i = 0; i < j; i++)
    {
        input[i] = newinput[i];
    }
    for (int i = j; i < *size; i++)
    {
        input[i] = '\0';
    }
    *size = j;
    
    return 0;
}
