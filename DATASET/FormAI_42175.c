//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char cat_meow[1024];
    printf("Greetings, my lord. I have created a Cat Language Translator for us to communicate with the feline kind.\n\n");
    printf("Please enter the meow of the cat you wish to converse with:\n");
    gets(cat_meow);
    
    if(strcasecmp(cat_meow, "meow") == 0) {
        printf("Cat: Hello human.\n");
        printf("Human: Greetings, oh whiskered one. How are you?\n");
        printf("Cat: I am doing well, thank you. How about you, human?\n");
        printf("Human: I am doing fine, thank you for asking.\n");
    } else if(strcasecmp(cat_meow, "purr") == 0) {
        printf("Cat: Greetings, human. How may I be of service?\n");
        printf("Human: Hello, oh furry one. I was wondering if you could catch a mouse for me.\n");
        printf("Cat: Of course, human. It would be my pleasure to assist you.\n");
    } else if(strcasecmp(cat_meow, "hiss") == 0) {
        printf("Cat: What do you want, human?\n");
        printf("Human: I meant no harm, oh sharp-toothed one. I was merely passing by.\n");
        printf("Cat: You better watch your step, human. You never know when a cat may strike.\n");
    } else {
        printf("Cat: I do not understand your language, human. Speak in meows or purrs.\n");
    }
  
    return 0;
}