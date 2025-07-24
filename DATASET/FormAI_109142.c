//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int RecursivePower(int num, int power) {
    if(power == 0) {
        return 1;
    }
    else if(power % 2 == 0){
        int temp= RecursivePower(num, power / 2);
        return temp*temp;
    }
    else {
        return num * RecursivePower(num, power - 1);
    }
}

int main() {
    int num, power;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the power: ");
    scanf("%d", &power);
    int result = RecursivePower(num, power);
    printf("%d to the power of %d = %d", num, power, result);
    return 0;
}