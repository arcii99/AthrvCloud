//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char input[500], output[200];
    int i, j, k = 0, length, index[200], temp, flag;

    printf("Enter the input: ");
    fgets(input, 500, stdin);

    length = strlen(input);

    for(i=0; i<length; i++) {
        if(input[i] == '.' || input[i] == '?' || input[i] == '!') {
            index[k++] = i;
        }
    }

    index[k++] = -1;

    for(i=0; i<k-1; i++) {
        temp = index[i] + 1;
        flag = 0;
        for(j=temp; j<index[i+1]; j++) {
            if(isalpha(input[j])) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            strcpy(output, "");
            for(j=temp; j<index[i+1]; j++) {
                if(isalpha(input[j])) {
                    strncat(output, &input[j], 1);
                }
            }
            printf("%s\n", output);
        }
    }

    return 0;
}