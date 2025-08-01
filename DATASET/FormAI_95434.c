//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 30

// ASCII art generator function
void generate_ascii(char* text) {
    // Initialize the characters array
    char characters[37][6][5] = {
        {
            "  ###",
            " #   #",
            "#     #",
            "#     #",
            "#     #",
            " #   #",
            "  ###"
        },
        {
            "#####",
            "#    #",
            "#####",
            "#    #",
            "#    #",
            "#####"
        },
        {
            "######",
            "#     ",
            "#     ",
            "######",
            "#     ",
            "#     ",
            "######"
        },
        {
            "######",
            "#     ",
            "#     ",
            "######",
            "#     ",
            "#     ",
            "######"
        },
        {
            "#     #",
            "#     #",
            "#     #",
            "#######",
            "      #",
            "      #",
            "      #"
        },
        {
            "#######",
            "#      ",
            "#      ",
            "###### ",
            "      #",
            "      #",
            "#######"
        },
        {
            "###### ",
            "#      ",
            "#      ",
            "###### ",
            "#     #",
            "#     #",
            "###### "
        },
        {
            "#######",
            "#    #",
            "    #",
            "   #",
            "   #",
            "   #",
            "   #"
        },
        {
            " ######",
            "#     #",
            "#     #",
            " ######",
            "#     #",
            "#     #",
            " ######"
        },
        {
            "  ####",
            " #    #",
            "#",
            "#",
            "#",
            " #    #",
            "  ####"
        },
        {
            "#    #",
            "#   #",
            "#  #",
            "###",
            "#  #",
            "#   #",
            "#    #"
        },
        {
            "#     ",
            "#     ",
            "#     ",
            "#     #",
            "#     #",
            "#     #",
            "#######"
        },
        {
            "#     #",
            "##   ##",
            "# # # #",
            "#  #  #",
            "#     #",
            "#     #",
            "#     #"
        },
        {
            "#     #",
            "###   #",
            "# #   #",
            "#  #  #",
            "#   # #",
            "#    ##",
            "#     #"
        },
        {
            " ######",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            " ######"
        },
        {
            " #####",
            "#     #",
            "#",
            "#",
            "#",
            "#     #",
            " #####"
        },
        {
            "######",
            "    #",
            "    #",
            "    #",
            "    #",
            "    #",
            "######"
        },
        {
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            " ######"
        },
        {
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            " #   #",
            "  ###",
            "   #"
        },
        {
            "#######",
            "     #",
            "    #",
            "   #",
            "  #",
            " #",
            "#######"
        },
        {
            "#",
            "#",
            "#",
            "#",
            "#",
            "#",
            "#######"
        },
        {
            "#     #",
            "##   ##",
            "# # # #",
            "#  #  #",
            "#     #",
            "#     #",
            "#     #"
        },
        {
            "#     #",
            "##    #",
            "# #   #",
            "#  #  #",
            "#   # #",
            "#    ##",
            "#     #"
        },
        {
            " #####",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            "#     #",
            " #####"
        },
        {
            "######",
            "#     #",
            "#     #",
            "######",
            "#",
            "#",
            "#"
        },
        {
            " #####",
            "#     #",
            "#     #",
            "#  #  #",
            "#   # #",
            "#    #",
            " ####"
        },
        {
            "######",
            "#     #",
            "#     #",
            "######",
            "     #",
            "     #",
            "     #"
        },
        {
            " #####",
            "#     #",
            "#      ",
            " #####",
            "      #",
            "#     #",
            " #####"
        },
        {
            "######",
            "     #",
            "     #",
            "     #",
            "     #",
            "     #",
            "######"
        },
        {
            "#######",
            "   #   ",
            "  #    ",
            " #",
            "  #    ",
            "   #   ",
            "#######"
        },
        {
            "#     #",
            "#     #",
            " #   #",
            "  # #",
            "   #",
            "   #",
            "   #"
        },
        {
            "#",
            "#",
            "#",
            "#",
            "#",
            "#",
            "######"
        },
        {
            "#     #",
            "##   ##",
            "# # # #",
            "#  #  #",
            "#     #",
            "#     #",
            "#     #"
        },
        {
            "#     #",
            "#     #",
            "#     #",
            " #   #",
            "  # #",
            "   #",
            "   #"
        },
        {
            "#     #",
            "#     #",
            "#     #",
            "#  #  #",
            "# # # #",
            "##   ##",
            "#     #"
        },
        {
            "#     #",
            "#     #",
            " #   #",
            "  # #",
            "   #",
            "   #",
            "   #"
        },
        {
            "#",
            "#",
            "#",
            "#",
            "#",
            "#",
            "###"
        }
    };

    // Print the ASCII art
    for (int row = 0; row < 7; row++) {
        for (int i = 0; text[i] != '\0'; i++) {
            char c = toupper(text[i]);
            int index = 36;

            if (isdigit(c)) {
                index = c - '0';
            } else if (isalpha(c)) {
                index = c - 'A';
            }

            for (int col = 0; col < 5; col++) {
                putchar(characters[index][row][col]);
            }

            putchar(' ');
        }

        putchar('\n');
    }
}

int main() {
    // Get the text input from the user
    char text[MAX_WIDTH];
    printf("Enter a string up to %d characters: ", MAX_WIDTH - 1);
    fgets(text, MAX_WIDTH, stdin);

    // Print the ASCII art
    generate_ascii(text);

    return 0;
}