//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter string in Cat Language: ");
    fgets(input,100,stdin);

    int length = strlen(input);

    for(int i=0;i<length;i++){
        if(input[i] == 'C') {
            printf("1");
        }
        else if(input[i] == 'a') {
            printf("2");
        }
        else if(input[i] == 't') {
            printf("3");
        }
        else if(input[i] == ' ') {
            printf("4");
        }
        else {
            printf("%c", input[i]);
        }
    }

    return 0;
}