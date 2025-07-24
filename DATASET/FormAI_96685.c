//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Async function to generate a random number after 5 seconds
void generate_random_number() {
    srand(time(NULL));
    int r = rand() % 10 + 1;
    printf("Your lucky number is: %d\n", r);
}

// Async function to shuffle fortune messages after 3 seconds
void shuffle_fortune_messages(char **messages, int size) {
    int i, j;
    char *temp;
    srand(time(NULL));
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        // Swap messages
        temp = messages[i];
        messages[i] = messages[j];
        messages[j] = temp;
    }
}

int main() {
    char *fortune_messages[] = {
        "You will receive a great news tomorrow!",
        "Someone you love will surprise you soon.",
        "You will soon come into a lot of money!",
        "A new opportunity will knock on your door!",
        "Your hard work will pay off soon."
    };
    int num_fortunes = 5;
    
    // Display welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    
    // Shuffle fortune messages
    shuffle_fortune_messages(fortune_messages, num_fortunes);
    
    // Display shuffled fortune messages
    printf("Here are your shuffled fortune messages:\n");
    for (int i = 0; i < num_fortunes; i++) {
        printf("%s\n", fortune_messages[i]);
    }
    
    // Generate a random number after 5 seconds
    printf("Generating a lucky number...\n");
    sleep(5);
    generate_random_number();
    
    // Display thank you message
    printf("Thank you for using the Automated Fortune Teller.\n");
    
    return 0;
}