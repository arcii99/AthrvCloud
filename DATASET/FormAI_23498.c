//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[100000];
    char output[100000];
    char temp[100000];
    int line_num = 0;
    int line_lens[100000];
    int start_pos[100000];
    int end_pos[100000];

    printf("Enter the text:\n");
    fgets(input, 100000, stdin);
    strcat(input, "\n");

    printf("Processing the text...\n");

    // Processing text line by line
    int i, j, k;
    for(i=0, j=0, k=0; i<strlen(input); i++){
        if(input[i] == '\n'){
            line_lens[line_num] = k+1;
            start_pos[line_num] = j;
            end_pos[line_num] = i;
            line_num++;
            j = i + 1;
            k = 0;
            continue;
        }
        if(input[i] == ',' || input[i] == '.')
            continue;
        temp[k] = input[i];
        k++;
    }

    // Capitalizing first letter of each sentence
    int caps = 1;
    for(i=0; i<strlen(temp); i++){
        output[i] = temp[i];
        if(caps){
            if(output[i] >= 97 && output[i] <= 122)
                output[i] -= 32;
            caps = 0;
        }
        if(output[i] == ' ')
            caps = 1;
        if(i > 0 && (output[i-1] == '.' || output[i-1] == '?' || output[i-1] == '!'))
            caps = 1;
    }
    output[i] = '\0';

    printf("Processed text:\n");

    // Printing processed text
    for(i=0; i<line_num; i++){
        printf("%d. ", i+1);
        for(j=start_pos[i]; j<start_pos[i]+line_lens[i]-1; j++){
            printf("%c", output[j]);
        }
        printf("\n");
    }

    return 0;
}