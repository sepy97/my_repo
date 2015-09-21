#include <stdio.h>
#include <stdlib.h>

int delrep (int input[], int output[], int inputsize);

int main()
{
    printf ("Delete_repeats_mk1 by SEPY\n");
    
    int number;
    scanf ("%d", &number);
    
    int *inputarr = (int*)calloc (number, sizeof(int));
    
    for (int i = 0; i < number; i++)
    {
        scanf ("%d", &inputarr[i]);
    }
    
    int outputarr[1000];
    for (int i = 0; i < 1000; i++) outputarr[i] = 0;
    delrep (inputarr, outputarr, number);
    
    for (int i = 0; i < 1000; i++)
    {
        if (outputarr[i] == 1) printf ("%d ", i);
    }
    
}

int delrep (int input[], int output[], int inputsize)
{
    for (int i = 0; i < inputsize; i++)
    {
        if (output[input[i]] == 0) output[input[i]] = 1;
        else if (output[input[i]] > 0) output[input[i]] = -1;
    }
    return 0;
}