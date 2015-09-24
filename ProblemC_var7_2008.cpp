#include <stdio.h>

#define MAXSIZE 9000

int Input (char* name, int* input);

int numofnumbers (int* a, int* inputnumber);

int sumofdigits (int num);

int main()
{
    int inputNumber = 0;
    Input ("inputNumber", &inputNumber);
    
    if (inputNumber == 0 || inputNumber > 36)
    {
        printf("Here are no numbers with this sum of digits\n");
        return 0;
    }
    
    int a[MAXSIZE] = {};
    int result = numofnumbers (a, &inputNumber);
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (a[i] == 1) printf ("%d ", 1000+i);
    }
    printf("\n%d \n", result);
}

int Input (char* name, int* input)
{
    printf("Input %s -> ", name);
    scanf("%d", input);
    return 0;
}

int numofnumbers (int *a, int* inputnumber)
{
    int count = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        int num = 1000+i;
        if (sumofdigits (1000+i) == *inputnumber)
        {
            count++;
            a[i] = 1;
        }
    }
    return count;
}

int sumofdigits (int num)
{
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    
    return result;
}