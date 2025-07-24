//FormAI DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <ctype.h>

int main(){

    char word[50];
    char dict[100][50] = {"apple", "banana", "carrot", "dog", "elephant", "frog", "grape", "happy", "iguana", "jacket", 
    "kangaroo", "lion", "monkey", "nectarine", "oatmeal", "pear", "question", "rabbit", "strawberry", "tiger",
    "umbrella", "violin", "watermelon", "xylophone", "yacht", "zebra"};

    printf("Enter a word to check spelling: ");
    scanf("%s", word);

    for(int i=0; i<strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    int len_dict = sizeof(dict)/sizeof(dict[0]);
    int found = 0;

    for(int i=0; i<len_dict; i++){
        if(strcmp(dict[i], word) == 0){
            found = 1;
            break;
        }
    }

    if(found){
        printf("\n%s is spelled correctly.\n", word);
    }else{
        printf("\nDid you mean: \n");
        for(int i=0; i<len_dict; i++){
            int count = 0;
            for(int j=0; j<strlen(word); j++){
                if(word[j] != dict[i][j]){
                    count++;
                }
            }
            if(count <= 1){
                printf("%s\n", dict[i]);
            }
        }
    }

    return 0;
}