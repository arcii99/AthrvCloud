//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include<stdio.h>
#include<string.h>

int main() {
    char text[1000];
    int count = 0;
    int flag = 0;
    printf("Please enter a string to count the words:\n");
    fgets(text, 1000, stdin);
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            flag = 0;
        }
        else if(flag == 0) {
            flag = 1;
            count++;
        }
    }
    printf("The number of words in the string is: %d\n", count);
    return 0;
}