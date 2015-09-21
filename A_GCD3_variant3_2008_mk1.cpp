#include <stdio.h>
#include <assert.h>

unsigned long long GCD3 (unsigned long long first, unsigned long long second, unsigned long long third);

unsigned long long GCD2 (unsigned long long first, unsigned long long second);

int main()
{
    unsigned long long a = 0, b = 0, c = 0;
    
    scanf ("%llu %llu %llu", &a, &b, &c);
    
    assert (a > 0 && b > 0 && c > 0);
    
    unsigned long long result = GCD3 (a, b, c);
    
    if (result > 0) printf ("%llu \n", result);
    else printf("Problem with gcd function!!!");
}

unsigned long long GCD3 (unsigned long long first, unsigned long long second, unsigned long long third)
{
    if (first > 0 && second > 0 && third > 0)
    {
        unsigned long long tempgcd = GCD2 (second, third);
        return GCD2 (first, tempgcd);
    }
    else return -1;
}

unsigned long long GCD2 (unsigned long long first, unsigned long long second)
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
        return GCD2 (second, first);
    }
}