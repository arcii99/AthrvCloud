//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *occupation;
    int age;
    char *address;
} person;

void print_person(person p) {
    printf("=========================\n");
    printf("Name: %s\n", p.name);
    printf("Occupation: %s\n", p.occupation);
    printf("Age: %d\n", p.age);
    printf("Address: %s\n", p.address);
    printf("=========================\n");
}

int main() {
    person p;
    p.name = "Sherlock Holmes";
    p.occupation = "Detective";
    p.age = 34;
    p.address = "221B Baker Street, London";

    print_person(p);

    char *text = "It was a dark and stormy night. Sherlock Holmes sat by the fire, deep in thought. Suddenly, the door burst open and in rushed a man, soaking wet and breathless.";

    int num_sentences = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?') {
            num_sentences++;
        }
    }

    printf("Number of sentences in the text: %d\n", num_sentences);

    return 0;
}