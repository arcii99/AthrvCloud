//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include<stdio.h>
#include<string.h>

//Defining variables in multi-variable style
char c_name[20], c_sound[20], c_color[20];
char en_name[20], en_sound[20], en_color[20];

int main(){
    //Getting input from user
    printf("Enter the name of a cat in C Cat Language: ");
    scanf("%s", c_name);
    printf("Enter the sound of the cat in C Cat Language: ");
    scanf("%s", c_sound);
    printf("Enter the color of the cat in C Cat Language: ");
    scanf("%s", c_color);
    
    //Storing values in variables
    strcpy(en_name, "No match found!");
    strcpy(en_sound, "No match found!");
    strcpy(en_color, "No match found!");
    
    //Translating C Cat Language to English 
    if(strcmp(c_name, "Meowingtons") == 0){
        strcpy(en_name, "Whiskers");
    }
    
    if(strcmp(c_sound, "Purr") == 0){
        strcpy(en_sound, "Purrs");
    }
    
    if(strcmp(c_color, "Orange") == 0){
        strcpy(en_color, "Ginger");
    }
    
    //Displaying the translated values to user
    printf("\nEnglish Translation:\n");
    printf("Name: %s\n", en_name);
    printf("Sound: %s\n", en_sound);
    printf("Color: %s\n", en_color);
    
    return 0;
}