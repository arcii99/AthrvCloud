//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include<stdio.h>

int main(){
    //Romeo and Juliet inspired C Text Summarizer
    printf("Enter text to summarize: \n"); 
    char text[1000];
    fgets(text, 1000, stdin);

    printf("Verily, in brief, this passage saith: ");
    int i = 0, j = 0;
    while (text[i] != '\0'){
        //find beginning of sentence
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            printf("%c", text[i]);
            i++;
            while(text[i] == ' '){
                i++;
            }
            printf(" ");
            j=0;
        }else{
            printf("%c", text[i]);
            j++;
            i++;
        }
        //summary should not exceed 140 characters
        if(j > 140) {
            printf("\n\n Alas, the passage is too verbose for our brief attention.. *sigh* \n");
            return 0;
        }
    }
    printf("\n\n Thus, in summary it saith: \n"); 
    return 0;
}