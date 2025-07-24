//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include<stdio.h>
#include<string.h>

void main() {

 printf("Welcome to the C Alien Language Translator.\n");

 char alienLanguage[20], englishTranslation[20];

 printf("Please enter the Alien Language: \n");
 scanf("%s", alienLanguage);

 if(strcmp(alienLanguage, "Kuzmed") == 0) {
    strcpy(englishTranslation, "Hello");
 } else if(strcmp(alienLanguage, "Mortz") == 0) {
    strcpy(englishTranslation, "Goodbye");
 } else if(strcmp(alienLanguage, "Xorpl") == 0) {
    strcpy(englishTranslation, "Thank You");
 } else if(strcmp(alienLanguage, "Glooz") == 0) {
    strcpy(englishTranslation, "I Love You");
 } else {
    printf("Sorry, the Alien Language is not recognized.\n");
 } 

 if(strcmp(englishTranslation, "Sorry") != 0) {
    printf("The English translation of %s is %s.\n", alienLanguage, englishTranslation);
 } else {
    printf("Try again.\n");
 } 

 return 0;
}