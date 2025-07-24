//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    int count = 0;

    printf("Good morrow! Prithee, enter thy word or phrase: \n");
    fgets(str, 1000, stdin);

    for(int i=0; i<strlen(str); i++){
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
            count++;
        }
    }

    printf("\nOwnest entered %d words, milord/milady!", count+1);
    return 0;
}