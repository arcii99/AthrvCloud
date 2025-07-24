//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void tellAJoke() {
    printf("Why do programmers prefer dark mode? Because light attracts bugs!\n");
}

int main() {
    char* data = "Hello, my name is John Doe and I love coding in C!";
    char* metadata = malloc(sizeof(char) * 50);

    tellAJoke();

    printf("Extracting metadata...\n");

    // Simulating metadata extraction (just a bunch of random characters)
    for (int i = 0; i < 50; i++) {
        metadata[i] = rand() % 26 + 'a';
    }

    printf("Metadata extracted: %s\n", metadata);

    free(metadata);

    return 0;
}