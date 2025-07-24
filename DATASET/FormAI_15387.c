//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include<stdio.h>

int main(){
    char text[1000];
    int char_count=0, word_count=0, line_count=0;

    printf("Enter some text: \n");

    while(fgets(text, 1000, stdin)){
        if(text[0]=='\n')
            break;
        char_count+=strlen(text);

        //count words and lines
        int i=0;
        for(i=0;text[i]!='\n';i++){
            if(text[i]==' ' || text[i]=='\t')
                word_count++;
        }
        line_count++;
        word_count++;
    }

    printf("\nNumber of characters: %d\n", char_count-1);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}