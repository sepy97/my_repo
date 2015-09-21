#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long Input (const char name[]);

int longtobool (long long input_number, int resultarray[], long long *size);

int booltopow (int pows_two[], long long size, long long resultpows[]);

long long booloutput (long long result[], long long boolsize);

int main()
{
    long long input_number;
    input_number = Input ("number");
    
    long long boolsize = log10(input_number)/log10(2) + 1;
    
    int *pows_two = (int*) calloc (boolsize, sizeof(int));
    
    longtobool (input_number, pows_two, &boolsize);
    
    long long *resultpows = (long long *) calloc(boolsize, sizeof(long long));
    booltopow (pows_two, boolsize, resultpows);
    
    booloutput(resultpows, boolsize);
}

long long Input (const char name[])
{
    printf ("Input %s -> ", name);
    
    long long val = 0;
    
    if (scanf ("%lld", &val) != 1) return -1;
    
    return val;
}

int longtobool (long long input_number, int resultarray[], long long *size)
{
    for (long long i = *size; --i >= 0; )
    {
        resultarray[i] = input_number%2;
        input_number /= 2;
    }
    return 0;
}

int booltopow (int pows_two[], long long size, long long resultpows[])
{
    for (long long i = 0; i < size; i++)
    {
        if (pows_two[size-(i+1)] == 1)
        {
            resultpows[i] = pow(2, i);
        }
    }
    return 0;
}

long long booloutput (long long result[], long long boolsize)
{
    for (int i = 0; i < boolsize; i++)
    {
        if (result[i]!=0)
        {
            printf("%lld ", result[i]);
        }
    }
    printf("\n");
    return 0;
}