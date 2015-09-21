#include <stdio.h>

unsigned long long GCD (unsigned long long first, unsigned long long second);

unsigned long long LCM (unsigned long long first, unsigned long long second);

unsigned long long Input (const char name[]);

int main()
{
    unsigned long long first = 0, second = 0;
    first = Input("first number");
    second = Input("second number");
    
    unsigned long long result = LCM(first, second);
    
    printf("LCM of %llu & %llu is %llu \n", first, second, result);
}

unsigned long long GCD (unsigned long long first, unsigned long long second)
{
    if (first > second)
    {
        unsigned long long tmp = first % second;
        while (tmp != 0)
        {
            first = second;
            second = tmp;
            tmp = first % second;
        }
        return second;
    }
    else if (first == second)
    {
        return second;
    }
    else
    {
        return GCD (second, first);
    }
}

unsigned long long LCM (unsigned long long first, unsigned long long second)
{
    return first*second/GCD(first, second);
}

unsigned long long Input (const char name[])
{
    printf ("Input %s -> ", name);
    
    long long val = 0;
    
    if (scanf ("%llu", &val) != 1) return -1;
    
    return val;
}