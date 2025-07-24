//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <string.h>

//Surrealist Spam Detection System
int main() {
    char word[50];
    int i,j;
    printf("Welcome to the Surrealist Spam Detection System\n");
    printf("Please enter the word to be checked: ");
    scanf("%s",word);
    for(i=0;i<strlen(word);i++) {
        if(word[i]=='c') {
            for(j=i+1;j<strlen(word);j++) {
                if(word[j]=='o') {
                    for(int k=j+1;k<strlen(word);k++) {
                        if(word[k]=='d' && word[k+1]=='e') {
                            for(int l=k+2;l<strlen(word);l++) {
                                if(word[l]=='r' && word[l+1]=='e' && word[l+2]=='a' && word[l+3]=='m') {
                                    printf("Warning! This word is surreal spam!\n");
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("This word is not surreal spam.\n");
    return 0;
}