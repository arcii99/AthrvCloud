//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {

    char alpha[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
                    
    int max_chars = 100;
    char input_text[max_chars];
    int total_chars = 0;
    int errors = 0;
    time_t start, end;
    double time_taken;
    
    time(&start);
    system("clear");
    printf("Welcome to the Typing Speed Test!\nType the following text:\n\n");
    
    for(int i = 0; i < max_chars; i++) {
        int random_idx = rand() % 52;
        printf("%c", alpha[random_idx]);
    }
    
    printf("\n");
    fgets(input_text, max_chars, stdin);
    
    for(int i = 0; i < max_chars; i++) {
        if(input_text[i] != '\n') {
            total_chars++;
            if(tolower(input_text[i]) != tolower(alpha[i])) {
                errors++;
            }
        }
    }

    time(&end);
    time_taken = (double)(end - start);
    
    system("clear");
    
    if(errors > 0) {
        printf("You have completed the typing speed test.\nYou made %d errors and completed it in %0.2f seconds.\n", errors, time_taken);
    } else {
        printf("Congratulations! You have completed the typing speed test in %0.2f seconds.\n", time_taken);
    }
    
    return 0;
}