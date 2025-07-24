//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>

int main() {

    int x, y, z;
    printf("Enter three integer values to check if they form a Pythagorean triplet: \n");
    scanf("%d%d%d", &x, &y, &z);

    if((x * x + y * y == z * z) || (y * y + z * z == x * x) || (z * z + x * x == y * y)){
        printf("The given integers form a Pythagorean triplet.\n");
    } else {
        printf("The given integers do not form a Pythagorean triplet.\n");
    }
    
    return 0;
}