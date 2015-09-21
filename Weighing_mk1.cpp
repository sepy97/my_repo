#include <stdio.h>

int func (unsigned long long input);

unsigned long long Input (char name[], int *test);

int main () {
    printf ("Weighing_mk1 by SEPY \n");
    
    unsigned long long N;
    int test = 0;
    N = Input("N", &test);
    if (test) printf("Wring input with number %llu", N);
    
    if (func(N)) printf ("YES\n");
    else printf ("NO\n");
}

unsigned long long Input (char name[], int *test) {
    *test = 0;
    printf ("Input %s -> ", name);
    
    double val = 0;
    
    char c; //here we are controlling the input
    c = getchar();
    while (c!='\n'){
        if (c >= '0' && c <= '9') {
            val *= 10;
            val += c - '0';
        } else {
            *test = -1;
        }
        c = getchar();
    }
    
    return val;
}

int func (unsigned long long number) {
    if (number == 1) return 1;
    
    int mod = number%4;
    switch (mod) {
        case 0: return func (number/4);                                                  break;
        case 1: return func ((number-1)/4);                                              break;
        case 3: return func ((number+1)/4);                                              break;
        case 2: return 0;                                                                break;
        default: printf ("Something is going wrong! Input = %llu \n", number); return 0; break;
    }
}
