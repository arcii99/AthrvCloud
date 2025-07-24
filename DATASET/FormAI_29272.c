//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include<stdio.h>
int main(){
    printf("Hurray! Get ready to see an awesome C Pattern!\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("Wow, that Looks great, right?\n");
    printf("But wait, let me make it even more awesome!\n");
    for(int i = 5; i > 0; i--){
        for(int j = 0; j < i; j++){
            printf("# ");
        }
        printf("\n");
    }
    printf("Amazing, isn't it?\n");
    printf("Hey, Let's try something new now!\n");
    for(int i = 1; i <= 5; i++){
        for(int j = i; j < 5; j++){
            printf("  ");
        }
        for(int k = 0; k < i; k++){
            printf("* ");
        }
        printf("\n");
    }
    printf("Cool, isn't it?\n");
    printf("But wait, the best is yet to come!\n");
    for(int i = 5; i >= 1; i--){
        for(int j = i; j <= 4; j++){
            printf("  ");
        }
        for(int k = 1; k <= i; k++){
            printf("$ ");
        }
        printf("\n");
    }
    printf("Surprised, right?\n");
    printf("This is what I call a masterpiece!\n");
    printf("Stay Happy, Stay Creative!\n");
    return 0;
}