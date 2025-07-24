//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include<stdio.h>
#include<string.h>

int main() {
    char input[100], temp[100], output[100];
    int i, j, k, strlenInput, strlenTemp = 0;
    
    printf("Enter a string to be manipulated: ");
    scanf("%s", input);
    
    strlenInput = strlen(input);
    
    for(i=1; i<strlenInput; i++) {
        for(j=0; j<i; j++) {
            if(input[i] == input[j]) {
                break;
            }
        }
        if(j == i) {
            temp[strlenTemp++] = input[i];
        }
    }
    
    for(i=0; i<strlenInput; i++) {
        if(input[i] == ' ') {
            output[i] = temp[--strlenTemp];
        } else {
            output[i] = input[i];
        }
    }
    
    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);
    
    return 0;
}