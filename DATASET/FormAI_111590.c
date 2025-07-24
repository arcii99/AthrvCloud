//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 1000
#define MAX_LINES 100

int main()
{
    char text[MAX_CHARS];
    char lines[MAX_LINES][MAX_CHARS];
    int num_lines = 0;

    printf("Enter text:\n");
    fgets(text, MAX_CHARS, stdin);

    // Split input text into lines
    char *line = strtok(text, "\n");
    while (line != NULL && num_lines < MAX_LINES) {
        strcpy(lines[num_lines], line);
        num_lines++;
        line = strtok(NULL, "\n");
    }

    // Summarize text by choosing a line from each player randomly
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    printf("Summary:\n");
    int i;
    for (i = 0; i < num_lines; i++) {
        int player_index = i % num_players;
        printf("%s\n", lines[player_index]);
    }

    return 0;
}