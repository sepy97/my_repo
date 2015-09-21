#include <stdio.h>
#include <assert.h>

int erat_alg (const int M, int list[]) {
    for (int i = 2; i < M; i++) {
        if (list[i] == 0) {
            list[i] = -1; //marking prime numbers
            for (int j = 2*i; j < M; j += i) {
                list[j] = 1; //marking not prime numbers
            }
        }
    }
    
    return 0;
}

int main () {
    printf("Prime_numbers_mark_1 by SEPY\n");
    
    const int M = 100000;
    int N = 4;
    
    int list[M];
    erat_alg (M, list); //creating of euclid table
    
    int element[4] = {3, 9, 11, 3};
    for (int i = 0; i < N; i++) {
        
        assert (element[i] > 1);
        assert (element[i] < M);
        
        if (list[element[i]] == -1) printf("%d ", element[i]);
    }
}
