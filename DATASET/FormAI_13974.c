//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void recursive_func(int n) {
    printf("Oh my god, I'm calling the function again!\n");
    if(n == 0) {
        printf("I can't handle it anymore, I'm done.\n");
        return;
    }
    recursive_func(n - 1);
}

int main() {
    int num = 10;
    printf("I'm starting the program, wish me luck\n");
    recursive_func(num);
    printf("Phew, it's finally over, I can't believe I made it.\n");
    return 0;
}