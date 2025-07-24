//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define elements struct
struct element
{
    char symbol[3];
    char name[20];
    int atomic_number;
};

// Define prototypes for functions
void display_menu();
int get_selection();
void display_element(struct element);
int validate_answer(char[], char[]);
void display_result(int, int, int);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Populate elements array
    struct element elements[118];
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;
    // ... populate the rest of the elements array ...

    // Display menu and get user selection
    display_menu();
    int selection = get_selection();

    // Loop until user selects quit
    while (selection != 4)
    {
        // Generate random element index
        int index = rand() % 118;

        // Display element information
        display_element(elements[index]);

        // Get user input
        char answer[20];
        printf("What is the symbol for this element?\n");
        scanf("%s", answer);

        // Validate user input
        int result = validate_answer(answer, elements[index].symbol);

        // Display result and update score
        int score = 0;
        if (result == 1)
        {
            printf("Correct!\n");
            score = 1;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }

        display_result(score, index+1, 118);

        // Get user selection again
        display_menu();
        selection = get_selection();
    }

    printf("Thanks for playing!\n");

    return 0;
}

// Function to display the program menu
void display_menu()
{
    printf("\nC Periodic Table Quiz\n");
    printf("1. Start Quiz\n");
    printf("2. Scoreboard\n");
    printf("3. Instructions\n");
    printf("4. Quit\n");
    printf("Enter your selection: ");
}

// Function to get user's menu selection
int get_selection()
{
    int selection;
    scanf("%d", &selection);
    return selection;
}

// Function to display an element's information
void display_element(struct element element)
{
    printf("\n%s (%s)\n", element.symbol, element.name);
}

// Function to validate the user's answer
int validate_answer(char answer[], char actual[])
{
    if (strcmp(answer, actual) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to display quiz result and update scoreboard
void display_result(int score, int current, int total)
{
    static int total_score = 0;
    static int num_attempts = 0;
    static float success_rate = 0.0;

    // Update scoreboard
    total_score += score;
    num_attempts++;
    success_rate = ((float)total_score / (float)num_attempts) * 100.0;

    // Display result
    printf("\nQuiz Result:\n");
    printf("Score: %d/%d\n", score, 1);
    printf("Success Rate: %.2f%%\n", success_rate);
    printf("Current Element: %d/%d\n", current, total);
}