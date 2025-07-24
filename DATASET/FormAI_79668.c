//FormAI DATASET v1.0 Category: Recursive ; Style: artistic
/* The Tree of Possibilities */

#include<stdio.h>
#include<stdlib.h>

void createTree(int depth) {
    int i;
    if(depth == 0) {
        return;
    }
    for(i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("🌳\n");
    for(i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("|");
    createTree(depth - 1);
    printf("\n");
    for(i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("|");
    createTree(depth - 1);
}

int main() {
    int depth;
    printf("Enter the depth of the Tree of Possibilities: ");
    scanf("%d", &depth);
    createTree(depth);
    return 0;
}