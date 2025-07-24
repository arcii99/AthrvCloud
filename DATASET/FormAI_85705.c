//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter the number of rows: ");
    scanf("%d", &num);
    
    int spaces = num-1;
    
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n");
        spaces--;
    }
    
    spaces = 1;
    
    for (int i = num-1; i >= 1; i--) {
        for (int j = 1; j <= spaces; j++) {
            printf(" "); 
        }
        
        for (int j = 1; j <= i; j++) {
            printf("*"); 
        }
        
        printf("\n");
        spaces++;
    }
    
    return 0;
}