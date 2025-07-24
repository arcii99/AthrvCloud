//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
// Here's an example code snippet that illustrates memory allocation and deallocation in C:

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p = NULL;
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    p = (int*) malloc(sizeof(int) * n);
    
    if(p == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("The elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    
    free(p);
    p = NULL;
    
    return 0;
}