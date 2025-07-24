//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>
 
int main()
{
    char alien_language[] = "Kupo Xurit chii b'aa xurit Kupo";
    char english_translation[100];
    int i,j;
 
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Alien language: %s\n",alien_language);
 
    // Alien dictionary
    char alien_alphabet[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\''};
    char alien_translation[] = {' ','K','u','p','o',' ','X','u','r','i','t',' ','c','h','i','i',' ','b','\'','a','a',' ','x','u','r','i','t',' ','K','u','p','o','\0'};
    
    int alien_length = strlen(alien_language); // get length of alien language
    int translation_length = 0; // initialize length of english translation
 
    // Translate from alien to english
    for(i = 0; i < alien_length; i++)
    {
        for(j = 0; j < 29; j++) // 29 is length of alien_alphabet array
        {
            if(alien_language[i] == alien_translation[j])
            {
                english_translation[translation_length] = alien_alphabet[j]; // add corresponding english letter
                translation_length++;
            }
        }
    }
    english_translation[translation_length] = '\0'; // add null character at end
 
    printf("\nEnglish translation: %s\n",english_translation);
 
    return 0;
}