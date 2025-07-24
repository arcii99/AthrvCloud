//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>
#include <stdlib.h>

void recursive_function(int num) {
    if(num <= 0) {
        printf("Done with recursion!\n");
        return;
    }
    else {
        printf("Current number: %d\n", num);
        recursive_function(num-1);
        printf("Number after recursion: %d\n", num);
    }
}

int main() {
    int start_num;
    printf("Enter a starting number for recursion: ");
    scanf("%d", &start_num);
    recursive_function(start_num);

    return 0;
}