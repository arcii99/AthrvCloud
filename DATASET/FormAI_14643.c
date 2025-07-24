//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to translate English into Alien Language
void translate(char input[]) {
    // Check if input is not empty
    if (strlen(input) == 0) {
        printf("No input detected.\n");
        return;
    }

    // Loop through each character in the input
    for (int i = 0; i < strlen(input); i++) {
        // Switch case for each character
        switch (input[i]) {
            case 'a':
                printf("glo");
                break;
            case 'b':
                printf("jik");
                break;
            case 'c':
                printf("muv");
                break;
            case 'd':
                printf("skel");
                break;
            case 'e':
                printf("lirp");
                break;
            case 'f':
                printf("tib");
                break;
            case 'g':
                printf("zorp");
                break;
            case 'h':
                printf("bif");
                break;
            case 'i':
                printf("vum");
                break;
            case 'j':
                printf("wip");
                break;
            case 'k':
                printf("yod");
                break;
            case 'l':
                printf("nir");
                break;
            case 'm':
                printf("lum");
                break;
            case 'n':
                printf("gim");
                break;
            case 'o':
                printf("frap");
                break;
            case 'p':
                printf("plif");
                break;
            case 'q':
                printf("snik");
                break;
            case 'r':
                printf("flom");
                break;
            case 's':
                printf("nup");
                break;
            case 't':
                printf("kif");
                break;
            case 'u':
                printf("zul");
                break;
            case 'v':
                printf("lak");
                break;
            case 'w':
                printf("mif");
                break;
            case 'x':
                printf("nop");
                break;
            case 'y':
                printf("bop");
                break;
            case 'z':
                printf("rip");
                break;
            default:
                printf("%c", input[i]);
                break;
        }
    }

    // Add a new line character at the end
    printf("\n");
}

int main() {
    // Test cases
    char input1[] = "hello world";
    char input2[] = "this is a test message";
    char input3[] = "alien";
    char input4[] = "C programming is cool";

    // Call the translate function for each test case
    translate(input1);
    translate(input2);
    translate(input3);
    translate(input4);

    return 0;
}