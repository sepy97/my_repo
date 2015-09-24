#include <stdio.h>

int Input (char* name, long long* input);

long long sumofdivisors (long long* input);

int main()
{
    printf ("Solving_the_sum_of_divisors_mk1 by SEPY\n");
    
    long long inputNumber = 0;
    Input ("inputNumber", &inputNumber);
    
    long long result = sumofdivisors (&inputNumber);
    
    printf("Sum of divisors = %lld \n", result);
}

int Input (char* name, long long* input)
{
    printf ("Input %s -> ", name);
    return scanf("%lld", input);
}

long long sumofdivisors (long long* input)
{
    long long sum = 0;
    for (int i = 1; i <= *input; i++)
    {
        if (!(*input % i)) sum += i;
    }
    return sum;
}