//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
//It was a foggy day in London when Dr. Watson came to visit Sherlock Holmes.
#include <stdlib.h>
#include <stdio.h>

int main() {

    //The room was dimly lit and Sherlock Holmes was engrossed in his work.
    int *ptr = (int*) malloc(sizeof(int));

    //Dr. Watson cleared his throat to get Sherlock's attention.
    printf("Sherlock, I was wondering if you could explain to me how memory management works in C.\n");
    printf("Certainly, Watson. Let me show you an example.\n");

    //Sherlock Holmes stood up and walked to his desk to retrieve a few papers.
    int *arr = (int*) calloc(5, sizeof(int));

    //He spread them out on the table and started to explain.
    printf("Here, I have allocated space for a pointer 'ptr' of type integer using the malloc function.\n");
    printf("And here, I have allocated space for an array 'arr' with 5 integers using the calloc function.\n");

    //Dr. Watson leaned in to get a better look.
    printf("But Sherlock, what if we need more space?\n");

    //Sherlock Holmes smiled and reached for his pen.
    int *new_ptr = (int*) realloc(ptr, 2*sizeof(int));

    // "Fear not Watson, we can always use the rebuild function, called realloc, to allocate more space." 
    printf("See here, I have reallocated the space for 'ptr' to 2 integers.\n");

    //Dr. Watson nodded in understanding.
    printf("And remember, if we no longer need this allocated memory, we must free it to avoid memory leaks.\n");
    free(ptr);
    free(arr);
    printf("Well done, Watson. You are learning quickly. Now, shall we solve a case?\n");

    //And with that, Sherlock Holmes and Dr. Watson set out to solve their next mystery.
    return 0;
}