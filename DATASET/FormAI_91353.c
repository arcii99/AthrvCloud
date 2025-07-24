//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char name[15] = "Love";
    char partner[15] = "Passion";
    char sentence_1[40] = "";
    char sentence_2[40] = "";
    char sentence_3[40] = "";
    char sentence_4[40] = "";
    
    // Manipulating the strings to form romantic sentences
    strcat(sentence_1, "My dearest ");
    strcat(sentence_1, partner);
    strcat(sentence_1, ", ");
    strcat(sentence_2, "You are the flame that ");
    strcat(sentence_2, "ignites my ");
    strcat(sentence_2, name);
    strcat(sentence_2, ", ");
    strcat(sentence_3, "My love for you is a ");
    strcat(sentence_3, "rose that blossoms ");
    strcat(sentence_3, "with each passing day, ");
    strcat(sentence_4, "The sound of your ");
    strcat(sentence_4, "voice is like music to ");
    strcat(sentence_4, "my ears, ");
    
    // Prints out romantic sentences for the lovers
    printf("%s\n%s\n%s\n%s", sentence_1, sentence_2, sentence_3, sentence_4);
    
    return 0;
}