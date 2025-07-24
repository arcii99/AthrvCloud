//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include<stdio.h>
#include<string.h>

int main() {
    char love1[] = "Roses are red";
    char love2[] = "Violets are blue";
    char myLove[] = "I am in love with you";
    char heart[] = "You stole my heart away";
    
    printf("%s\n%s\n%s\n%s\n", love1, love2, myLove, heart); //displaying the love sentences
    
    //concatenate the love1 and love2 strings
    strcat(love1, " ");
    strcat(love1, love2);
    printf("\n%s\n", love1); //displaying concatenated string
    
    //replace the word 'you' with 'my love' in myLove string
    char *replace = strstr(myLove, "you");
    if(replace != NULL) {
        strncpy(replace, "my love", 7);
    }
    printf("%s\n", myLove); //displaying replaced string
    
    //find the length of heart string and remove the last nine characters
    int heartLength = strlen(heart);
    heart[heartLength - 9] = '\0';
    printf("%s", heart); //displaying truncated string
    
    return 0;
}