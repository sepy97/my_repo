#include <stdio.h>

int Input (char* name, long long *input);

long long finding_max_divisors (long long *input);

int main()
{
    printf ("Solving_the_problem_of_maximal_divisor_mk1 by SEPY\n");
    
    long long inputNumber;
    Input ("inputNumber", &inputNumber);
    
    long long result = finding_max_divisors (&inputNumber);
    
    if (result == 0) printf ("Something is going wrong: can't find any divisors!!!\n");
    else printf ("Maximum divisor = %lld \n", result);
}

int Input (char* name, long long *input)
{
    printf ("Input %s -> ", name);
    int trouble = scanf ("%lld", input);
    return trouble;
}

long long finding_max_divisors (long long *input)
{
    long long result = 0;
    for (long long i = (*input + 1) / 2; i > 1; i--)
    {
        if (*input % i == 0)
        {
            result = i;
            return result;
        }
    }
    return result;
}