//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_punct(char* str) {
    int i=0,j=0;
    while(str[i]) {
        if(isalnum(str[i]) || str[i]==' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

void to_lower(char* str) {
    int i=0;
    while(str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char text[] = "Two households, both alike in dignity, In fair Verona, where we lay our scene, From ancient grudge break to new mutiny, Where civil blood makes civil hands unclean. From forth the fatal loins of these two foes A pair of star-cross'd lovers take their life; Whose misadventured piteous overthrows Do with their death bury their parents' strife.";
    char words[100][100];
    int count[100] = {0};
    int i,j,k;
    remove_punct(text);
    to_lower(text);
    i = 0;
    j = 0;
    while(text[i]) {
        char word[100];
        k = 0;
        while(text[i] && text[i]!=' ') {
            word[k++] = text[i++];
        }
        word[k] = '\0';
        int is_present = 0;
        for(int l=0; l<j; l++) {
            if(strcmp(word,words[l])==0) {
                count[l]++;
                is_present = 1;
                break;
            }
        }
        if(!is_present) {
            strcpy(words[j],word);
            count[j++] = 1;
        }
        if(text[i]==' ')
            i++;
    }
    printf("Word Frequency Counter\n\n");
    printf("+------------------+----------+\n");
    printf("|        Word      |  Count   |\n");
    printf("+------------------+----------+\n");
    for(int l=0; l<j; l++) {
        printf("|%18s|%10d|\n",words[l],count[l]);
    }
    printf("+------------------+----------+\n");
    return 0;
}