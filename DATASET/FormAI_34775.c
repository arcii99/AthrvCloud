//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void callback(int sum){
    printf("The sum of two randomly generated numbers is %d\n", sum);
}

void generate_random_number(int* ptr, void (*callback)(int)){
    int num = rand() % 10 + 1;
    *ptr = num;
    callback(num);
}

int main() {
    srand(time(0));
    int x, y, sum;
    
    generate_random_number(&x, callback);
    generate_random_number(&y, callback);
    
    sum = x + y;
    printf("Sum of %d and %d is %d\n", x, y, sum);

    return 0;
}