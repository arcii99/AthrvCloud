//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an element struct
typedef struct element_t {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
} element;

// Prototype functions
int count_lines(FILE *file);
void read_file(element *elements, FILE *file, int count);
void print_element(element *e);
void quiz_game(element *elements, int count);
int calculate_score(int num_correct, int num_questions);

int main(void) {
    // Open the periodic table file and count the number of lines
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    int count = count_lines(file) - 1;
    rewind(file); // Reset the file pointer

    // Allocate memory for an array of elements
    element *elements = malloc(count * sizeof(element));
    if (elements == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    // Read the elements from the file into the array
    read_file(elements, file, count);

    // Close the file
    fclose(file);

    // Start the periodic table quiz game
    quiz_game(elements, count);

    // Free the memory allocated for the elements array
    free(elements);

    return 0;
}

// Count the number of lines in a file
int count_lines(FILE *file) {
    int count = 0;
    char line[50];
    while (fgets(line, 50, file) != NULL) {
        count++;
    }
    return count;
}

// Read the elements from the file into the array
void read_file(element *elements, FILE *file, int count) {
    char line[50];
    fgets(line, 50, file); // Skip the header line
    for (int i = 0; i < count; i++) {
        fgets(line, 50, file);
        sscanf(line, "%s %s %d %f", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].atomic_mass);
    }
}

// Print the details of an element
void print_element(element *e) {
    printf("%s (%s), Atomic Number: %d, Atomic Mass: %.2f\n", e->symbol, e->name, e->atomic_number, e->atomic_mass);
}

// Run the periodic table quiz game
void quiz_game(element *elements, int count) {
    printf("Welcome to the Periodic Table Quiz Game!\n");
    printf("You will be asked 10 questions about the elements of the periodic table.\n");
    printf("Enter the symbol of the element in response to each question.\n\n");

    int num_correct = 0;
    for (int i = 0; i < 10; i++) {
        // Generate a random element to ask about
        int index = rand() % count;
        element e = elements[index];

        // Ask the question and get the user's answer
        printf("Question %d: What is the symbol of %s?\n", i+1, e.name);
        char answer[3];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, e.symbol) == 0) {
            printf("Correct! The symbol of %s is %s.\n", e.name, e.symbol);
            num_correct++;
        } else {
            printf("Incorrect. The symbol of %s is %s.\n", e.name, e.symbol);
        }
    }

    // Calculate the user's score and give them feedback
    int score = calculate_score(num_correct, 10);
    printf("\nYou scored %d out of 10.\n", num_correct);
    if (score >= 90) {
        printf("Great job, you have excellent knowledge of the periodic table!\n");
    } else if (score >= 70) {
        printf("Not bad, you have a good understanding of the periodic table.\n");
    } else if (score >= 50) {
        printf("Hmm, you might want to study the periodic table some more.\n");
    } else {
        printf("Yikes, you might want to start studying the periodic table from scratch!\n");
    }
}

// Calculate the user's score
int calculate_score(int num_correct, int num_questions) {
    return (int)(((float)num_correct / num_questions) * 100);
}