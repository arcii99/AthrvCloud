//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

void checkForIntrusion(char *input);

int main() {
    char input[MAX_SIZE];
    printf("Enter the text: ");
    fgets(input, MAX_SIZE, stdin);
    checkForIntrusion(input);
    return 0;
}

void checkForIntrusion(char *input) {
    int length = strlen(input);
    int i = 0, j = length - 1;
    while(i < j) {
        if(input[i] != input[j]){
            printf("This text is not secure. There seems to be an intrusion in the input.\n");
            return;
        }
        i++;
        j--;
    }
    printf("This text is secure. No intrusion detected\n");
}