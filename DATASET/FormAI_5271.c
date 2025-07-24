//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>

int main(){
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms you want to display: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms:\n",n);

    for(int i = 0; i < n; ++i){
        if(i == 0){
            printf("%d, ", first);
            continue;
        }
        if(i == 1){
            printf("%d, ", second);
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        printf("%d, ", next);
    }

    return 0;
}