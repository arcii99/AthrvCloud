//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    printf("Hey buddy! Welcome to Memory Management Comedy Club\n");
    printf("We'll take care of all your memory related needs\n");
    printf("Let's start with a classic\n");
    printf("Knock knock\n");
    printf("Who's there?\n");
    printf("Malloc\n");
    printf("Malloc who?\n");

    ptr = (int*) malloc(sizeof(int));

    if(ptr == NULL){
        printf("Oh no, looks like you couldn't handle the joke. Malloc failed!\n");
        printf("Better luck next time\n");
        exit(1);
    }

    printf("Malloc glad you're still laughing\n");
    printf("But wait, we have more\n");
    printf("A guy walks into a Memory Allocation Club\n");
    printf("He asks the bartender for a drink and a memory allocation\n");
    printf("The bartender says, 'Sure, but first you have to free the space in your head'\n");

    free(ptr);

    printf("Looks like we're the ones serving here\n");
    printf("Next up, we have a dramatic piece\n");
    printf("Alloca, Alloca, Alloca\n");
    printf("Why'd you have to go and leave me alone-ca?\n");
    printf("My stack just wasn't big enough for you, Alloca\n");

    ptr = (int*)alloca(sizeof(int));

    printf("Okay okay, enough drama. Let's get back to the jokes\n");
    printf("Why did the programmer quit his job? He didn't get arrays\n");
    printf("But don't worry, we've got you covered\n");
    printf("Introducing the dynamic duo: calloc and realloc\n");
    printf("They're like Batman and Robin, except they don't wear tights\n");

    ptr = (int*)calloc(10, sizeof(int));

    printf("I've never seen so many zeros in one place before, it's like a graveyard for integers\n");

    ptr = (int*)realloc(ptr, 20 * sizeof(int));

    printf("Reallocating memory is our specialty\n");
    printf("We can make your array as big as you want\n");
    printf("Just don't try to allocate negative memory, our servers are allergic\n");

    free(ptr);

    printf("Thanks for coming to our show tonight\n");
    printf("We hope you had a great time laughing and learning about memory management\n");
    printf("Now go out there and make some great programs with your newfound knowledge\n");

    return 0;
}