//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

int compute_power(int base, int power){
    if (power == 0){
        return 1;
    }
    else{
        return base * compute_power(base, power-1);
    }
}

int main(){
    int base, power;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the power: ");
    scanf("%d", &power);
    int result = compute_power(base, power);
    printf("%d^%d = %d\n", base, power, result);
    return 0;
}