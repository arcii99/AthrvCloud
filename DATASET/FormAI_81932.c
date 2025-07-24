//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    FILE *romeo_file, *juliet_file;
    char romeo_message[1000], juliet_message[1000];

    // Romeo sends a message to Juliet
    romeo_file = fopen("romeo.txt", "w");
    printf("Romeo: My dearest Juliet, I long to see your face.\n");
    fprintf(romeo_file, "My dearest Juliet, I long to see your face.");
    fclose(romeo_file);

    // Juliet reads Romeo's message
    juliet_file = fopen("romeo.txt", "r");
    fgets(juliet_message, 1000, juliet_file);
    printf("Juliet: Romeo, my heart beats with anticipation of our reunion. I shall meet you by the fountain tomorrow.\n");
    fclose(juliet_file);

    // Juliet sends a message to Romeo
    juliet_file = fopen("juliet.txt", "w");
    printf("Juliet: My Romeo, my soul is afire with passion for you. I shall never leave your side.\n");
    fprintf(juliet_file, "My Romeo, my soul is afire with passion for you. I shall never leave your side.");
    fclose(juliet_file);

    // Romeo reads Juliet's message
    romeo_file = fopen("juliet.txt", "r");
    fgets(romeo_message, 1000, romeo_file);
    printf("Romeo: My sweet Juliet, your words bring me joy. I shall cherish them always.\n");
    fclose(romeo_file);

    return 0;
}