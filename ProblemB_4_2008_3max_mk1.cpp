#include <stdio.h>

unsigned long long Input (const char name[]);

int scanformax (long long currentnum, long long max[]);

int outres (long long output);

int main()
{
    unsigned long long numberof = Input ("the number");
    
    long long maxnumbers[3] = {0,0,0};
    
    int number_of_differ_numbers = 0;
    
    for (unsigned long long i = 0; i < numberof; i++)
    {
        long long currentnum;
        scanf("%lld", &currentnum);
        number_of_differ_numbers += scanformax (currentnum, maxnumbers);
    }
    
    if (number_of_differ_numbers > 3) number_of_differ_numbers = 3;
    for (int i = 0; i < number_of_differ_numbers; i++)
    {
        outres(maxnumbers[i]);
    }
}

unsigned long long Input (const char name[])
{
    printf ("Input %s -> ", name);
    
    long long val = 0;
    
    if (scanf ("%llu", &val) != 1) return -1;
    
    return val;
}

int scanformax (long long currentnum, long long max[])
{
    if (currentnum > max[2])
    {
        if (currentnum > max[1])
        {
            if (currentnum > max[0])
            {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = currentnum;
                return 1;
            }
            else if (currentnum < max[0])
            {
                max[2] = max[1];
                max[1] = currentnum;
                return 1;
            }
        }
        else if (currentnum < max[1])
        {
            max[2] = currentnum;
            return 1;
        }
    }
    return 0;
}

int outres (long long output)
{
    if (output != 0) printf("%lld ", output);
    return 0;
}