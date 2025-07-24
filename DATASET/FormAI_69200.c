//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

int recursive_bravery(int num) {
    if (num == 0) {
        printf("I am not afraid!");
        return num;  
    } else {
        printf("Bring it on!\n");
        recursive_bravery(num - 1);
    }
}

int main() {
    int count = 10;
    printf("Let's test your bravery!\n");
    printf("------------------------\n");
    recursive_bravery(count);
    return 0;
}