//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Alien Language Dictionary */
char* alien_dictionary[] = {"Koil", "Ong", "Erv", "Zul", "Yen", "Blup", "Cen", "Dor", "Fud", "Gok"};

/* Function to decode the alien language */
void decode_alien_language(char* alien_language) {
    int i, j;
    int len_alien_language = strlen(alien_language);
    int len_alien_dictionary = sizeof(alien_dictionary) / sizeof(char*);
    int flag = 0;
    
    /* Loop through the alien language */
    for(i = 0; i < len_alien_language; i++) {
        int ascii_val = alien_language[i];
        
        if(ascii_val < 65 || ascii_val > 90) {
            continue;
        }
        
        /* Loop through the alien dictionary */
        for(j = 0; j < len_alien_dictionary; j++) {
            char* dict_word = alien_dictionary[j];
            
            /* If match found, print the decoded word */
            if(strncmp(dict_word, &alien_language[i], strlen(dict_word)) == 0) {
                printf("%c", j + 65);
                i += (strlen(dict_word)-1);
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("%c", ascii_val);
        }
        flag = 0;
    }
}

int main() {
    char alien_language[100] = "KoilDoraBoduZulYenCen";
    decode_alien_language(alien_language);
    return 0;
}