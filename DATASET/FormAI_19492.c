//FormAI DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_comment(char* text);

int main(){
    
    char* comment = "Hello, this is a sample comment for our text processing program.";
    print_comment(comment);

    return 0;
}

void print_comment(char* text){
    //count the number of vowels in the comment
    int vowel_count=0;
    for(int i=0; i<strlen(text); i++){
        char lower_char = tolower(text[i]);
        switch(lower_char){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel_count++;
                break;
            default:
                break;
        }
    }

    //print the comment with a header displaying the vowel count
    printf("=== Comment (with %d vowels) ===\n", vowel_count);
    printf("%s\n", text);
    printf("==============================\n");
}