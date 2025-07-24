//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Function that translates C Cat language to English
void* translate(void* arg){
    char* sentence = (char*)arg;
    if(strcmp(sentence, "Meow") == 0) printf("Hello\n");
    else if(strcmp(sentence, "Purr") == 0) printf("Goodbye\n");
    else if(strcmp(sentence, "Hiss") == 0) printf("No\n");
    else if(strcmp(sentence, "Scratch") == 0) printf("Yes\n");
    else printf("Unknown phrase\n");
    pthread_exit(NULL);
}

int main(){
    char input[100];
    pthread_t threads[10];
    int i = 0;

    printf("Welcome to the C Cat language translator!\n");

    // Loop to accept user input and start a new thread for each phrase to be translated
    while(i < 10){
        printf("Please enter a phrase in C Cat language (type 'exit' to quit): ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

        if(strcmp(input, "exit") == 0) break;

        pthread_create(&threads[i], NULL, translate, (void*)input);
        i++;
    }

    // Join threads once they finish translating their respective phrases
    for(int j = 0; j < i; j++){
        pthread_join(threads[j], NULL);
    }

    printf("Thank you for using the C Cat language translator!\n");
    return 0;
}