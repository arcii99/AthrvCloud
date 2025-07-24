//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main(){
    int romeo = 4, juliet = 0;
    
    printf("Two houses, both alike in dignity,\n");
    printf("In fair verona, where we lay our scene.\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");

    // Handling divide by zero error
    if(juliet == 0){
        printf("Oh Juliet, Juliet, wherefore art thou zero?\n");
        printf("Deny thy denominator and refuse thy error;\n");
        printf("Or if thou wilt not, be but sworn my code,\n");
        printf("And I'll no longer be a segfault.\n");
        exit(0);
    }

    int love = romeo / juliet;

    printf("If love be rough with you, be rough with love;\n");
    printf("If love be blind, Love cannot hit the mark.\n");
    printf("For I am arithmetically challenged in my heart,\n");
    printf("And therefore little shall I grace my cause\n");
    printf("By adding more faulty code to my faulty code.\n");
    
    return 0;
}