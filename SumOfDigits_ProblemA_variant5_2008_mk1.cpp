#include <stdio.h>
#include <assert.h>

long long sum (long long number);

long long Input (const char name[]);

int main()
{
    printf ("Sum_of_digits_mk1 by SEPY \n");
    
    long long input_num;
    input_num = Input ("input_num");
    
    assert (input_num >= 0);
    
    long long result = sum (input_num);
    printf ("Sum of digits = %llu \n", result);
}

long long Input (const char name[]) {
    printf ("Input %s -> ", name);
    
    long long val = 0;
    
    if (scanf ("%llu", &val) != 1) return -1;
    
    return val;
}

long long sum (long long number)
{
    if (number / 10 == 0) return number;
    else
    {
        return (number%10 + sum(number/10));
    }
}