//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    int len;
    printf("> Please enter a string: ");
    fgets(string, 100, stdin); // read input from user

    len = strlen(string);

    printf("> Your input with each character represented by its ASCII decimal value:\n");
    for(int i=0; i<len-1; i++){ 
        // Loop through each character in the string 
        int val = string[i]; 
        printf("%d ", val);             // Print ASCII decimal value
        
        // Output a random word based on ASCII value and index position
        if((val >= 65 && val <= 90) || (val >= 97 && val <= 122)){ // Check if character is a letter
            int index = (val + i) % 5; // Determine index based on ASCII value and position
            switch(index){
                case 0:
                    printf("bee ");
                    break;
                case 1:
                    printf("hawk ");
                    break;
                case 2:
                    printf("zebra ");
                    break;
                case 3:
                    printf("lion ");
                    break;
                case 4:
                    printf("tiger ");
                    break;
            }
        }
    }
    printf("\n");

    return 0;
}