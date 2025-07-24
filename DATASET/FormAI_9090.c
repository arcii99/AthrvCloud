//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#define MEOW 100
#define PURR 200
#define HISS 300
#define GROWL 400

int main() {
    int input;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a command (meow, purr, hiss, or growl):\n");

    // Take user input
    scanf("%d", &input);

    // Translate input into cat language
    switch (input) {
        case MEOW:
            printf("Meow!");
            break;
        case PURR:
            printf("Purr...");
            break;
        case HISS:
            printf("Hiss!");
            break;
        case GROWL:
            printf("Grrrr...");
            break;
        default:
            printf("I'm sorry, I don't speak human.");
            break;
    }

    return 0;
}