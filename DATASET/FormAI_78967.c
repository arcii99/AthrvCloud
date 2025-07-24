//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000
#define CHARACTER_HEIGHT 5
#define CHARACTER_WIDTH 4

// Function to generate futuristic ASCII art
void generateASCII(char text[MAX_LENGTH])
{
    char characters[27][CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
        {
            "  ___  ",
            " / _ \\ ",
            "| | | |",
            "| |_| |",
            " \\___/ "
        },
        {
            " ____  ",
            "|___ \\ ",
            "  __) |",
            " / __/ ",
            "|_____|"
        },
        {
            " _____ ",
            "| ____|",
            "| |__  ",
            "|___ \\ ",
            " ___) |",
            "|____/ "
        },
        {
            " _____ ",
            "|  ___|",
            "| |_   ",
            "|  _|  ",
            "|_|    "
        },
        {
            " ___   ",
            "|_ _|  ",
            " | |   ",
            " | |   ",
            "|___|  "
        },
        {
            " ____  ",
            "| ___| ",
            "|___ \\ ",
            " ___) |",
            "|____/ "
        },
        {
            "   __  ",
            "  / /  ",
            " | |   ",
            "< <    ",
            " | |   ",
            "  \\_\\  "
        },
        {
            " _____ ",
            "|___  |",
            "   / / ",
            "  / /  ",
            " /_/   "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| (_) |",
            " \\__, |",
            "   /_/ "
        },
        {
            "    _  ",
            "   / | ",
            "   | | ",
            "   | | ",
            "   |_| "
        },
        {
            " __   ",
            "/  |  ",
            "`| |  ",
            " | |  ",
            "_| |_ ",
            "\\___/ "
        },
        {
            " __  __ ",
            "|  \\/  |",
            "| |\\/| |",
            "| |  | |",
            "|_|  |_|"
        },
        {
            " _   __",
            "| | / /",
            "| |/ / ",
            "|   <  ",
            "|_|\\_\\ "
        },
        {
            " __      ",
            "/ /_     ",
            "| '_ \\   ",
            "| (_) |  ",
            " \\___/ "
        },
        {
            " _____ ",
            "|___  |",
            "   / / ",
            "  / /  ",
            " /_/   "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| (_) |",
            " \\__, |",
            "    /_/ "
        },
        {
            " _____     ",
            "|___ /     ",
            "  |_ \\    ",
            " ___) |   ",
            "|____/  "
        },
        {
            "  ____  ",
            " / ___| ",
            "| |     ",
            "| |___  ",
            " \\____| "
        },
        {
            " ___   ",
            "|_ _|  ",
            " | |   ",
            " | |   ",
            "|___|  "
        },
        {
            " ____  ",
            "|  _ \\ ",
            "| |_) |",
            "|  __/ ",
            "|_|    "
        },
        {
            " _   _ ",
            "| \\ | |",
            "|  \\| |",
            "| |\\  |",
            "|_| \\_|"
        },
        {
            " _    _ ",
            "| |  | |",
            "| |  | |",
            "| |__| |",
            " \\____/ "
        },
        {
            " __    __",
            "/ /_  / /",
            "\\ \\/ / / ",
            " \\  / /  ",
            " /_/ /_  "
        },
        {
            "__  __",
            "\\ \\/ /",
            " \\  / ",
            " /  \\ ",
            "/_/\\_\\"
        },
        {
            " _     _ ",
            "| |   | |",
            "| |   | |",
            "| |___| |",
            "|_____|_|"
        }
    };

    for (int row = 0; row < CHARACTER_HEIGHT; row++) {
        for (int i = 0; i < strlen(text); i++) {
            if (text[i] == ' ') {
                printf("     ");
            }
            else {
                int character_index = text[i] - 65; // character 'A' in ASCII is 65
                printf("%s", characters[character_index][row]);
            }
        }
        printf("\n");
    }
}

int main()
{
    char input[MAX_LENGTH];
    printf("Enter text to generate futuristic ASCII art:\n");
    fgets(input, MAX_LENGTH, stdin);
    generateASCII(input);
    return 0;
}