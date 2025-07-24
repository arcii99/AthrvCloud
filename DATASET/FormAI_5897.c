//FormAI DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>

void drawTree(int height);

int main(){
    int n;
    printf("Enter the height of the tree: ");
    scanf("%d", &n);
    drawTree(n);
    return 0;
}

void drawTree(int height){
    if(height == 0){
        return;
    }
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= height - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i * 2 - 1; j++){
            printf("*");
        }
        printf("\n");
    }
    drawTree(height-1);
    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= height - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i * 2 - 1; j++){
            printf("*");
        }
        printf("\n");
    }
}