//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function to convert text to ASCII art
void ascii_art(char *text){
    char *letter[27][8] = {
        {
            "  _______ ",
            " /       \\",
            "|   Rej  |",
            "|  code! |",
            "|________|",
            "  /~~~~\\",
            " /      \\",
            "/_/\\____\\_"
        },
        {
            " ______  ",
            "/      \\ ",
            "\\  J   |",
            " | U   |",
            " | L   |",
            " | E   |",
            " | T   |",
            " \\_____/"
        },
        {
            "      _____       ",
            "     /     \\      ",
            "    /\\      |    /|",
            "   /  \\     |   / |",
            "  /----\\    | /   |",
            " /      \\___|/    |",
            "/         (      /",
            "\\              /"
        },
        {
            "       ___ ",
            "     /  _/ ",
            "    / /__",
            "__/ __/   ",
            "/___/     ",
            "| |       ",
            "| |___   ",
            "/_____/"
        },
        {
            " ___ ",
            "|__ \\ ",
            "    ) |",
            "   / / ",
            "  |_|  ",
            " (_)   ",
            "       ",
            "       "
        },
        {
            " ____   ",
            "|___ \\  ",
            "  __) | ",
            " |__ <  ",
            " ___) | ",
            "|____/  ",
            "        ",
            "        "
        },
        {
            "    ___",
            "  / __\\",
            " / /   ",
            "/ /___ ",
            "\\____/ ",
            "       ",
            "       ",
            "       "
        },
        {
            " _____ ",
            "|___  |",
            "   / / ",
            "  / /  ",
            " / /___",
            "/_____|",
            "       ",
            "       "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| (_) |",
            " > _ < ",
            "| (_) |",
            " \\___/ ",
            "       ",
            "       "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| (_) |",
            " \\__, |",
            "   / / ",
            "  /_/  ",
            "       ",
            "       "
        },
        {
            "  __  ",
            " /_ | ",
            "  | | ",
            "  | | ",
            "  | | ",
            "  |_| ",
            "      ",
            "      "
        },
        {
            "      __",
            "     / /",
            "    / / ",
            "   / /  ",
            "  / /   ",
            " /_/    ",
            "        ",
            "        "
        },
        {
            " _____ ",
            "|___ / ",
            "  |_ \\ ",
            " ___) |",
            "|____/ ",
            "       ",
            "       ",
            "       "
        },
        {
            " _   _ ",
            "| | | |",
            "| |_| |",
            "|  _  |",
            "| | | |",
            "\\_| |_/",
            "       ",
            "       "
        },
        {
            " _____ ",
            "/___ / ",
            "  |_ \\ ",
            " ___) |",
            "|____/ ",
            "       ",
            "       ",
            "       "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| | | |",
            "| |_| |",
            " \\__  |",
            "    |_|",
            "       ",
            "       "
        },
        {
            " _____ ",
            "/  ___|",
            "\\ `--. ",
            " `--. \\",
            "/\\__/ /",
            "\\____/ ",
            "       ",
            "       "
        },
        {
            "   __  ",
            "  / /  ",
            " / /_  ",
            "| '_ \\ ",
            "| (_) |",
            " \\___/ ",
            "       ",
            "       "
        },
        {
            "     __",
            "    / /",
            "   / / ",
            "  / /  ",
            " / /   ",
            "/_/    ",
            "       ",
            "       "
        },
        {
            " __   __",
            " \\ \\ / /",
            "  \\ V / ",
            "   > <  ",
            "  / . \\ ",
            " /_/ \\_\\",
            "        ",
            "        "
        },
        {
            " __      ",
            "/_ |     ",
            " | |     ",
            " | |     ",
            " | |____ ",
            " |______|",
            "         ",
            "         "
        },
        {
            " _  __",
            "| |/ /",
            "| ' / ",
            "|  <  ",
            "| . \\ ",
            "|_|\\_\\",
            "      ",
            "      "
        },
        {
            " __  __",
            "|  \\/  |",
            "| \\  / |",
            "| |\\/| |",
            "| |  | |",
            "|_|  |_|",
            "        ",
            "        "
        },
        {
            " __    ",
            "/ /_   ",
            "| '_ \\ ",
            "| (_) |",
            "\\___/ ",
            "       ",
            "       ",
            "       "
        },
        {
            " _____ ",
            "|___ / ",
            "  |_ \\ ",
            " ___) |",
            "|____/ ",
            "       ",
            "       ",
            "       "
        },
        {
            "  ___  ",
            " / _ \\ ",
            "| (_) |",
            " > _ < ",
            "| (_) |",
            " \\___/ ",
            "       ",
            "       "
        },
        {
            " _____ ",
            "|___  |",
            "   / / ",
            "  / /  ",
            " / /___",
            "|_____|",
            "       ",
            "       "
        }
    };
    
    // Get the length of the input text
    int length = strlen(text);
    int i, j;
    
    // Loop through each row of the ASCII art
    for(i = 0; i < 8; i++){
        // Loop through each letter of the input text
        for(j = 0; j < length; j++){
            // Get the ASCII value of the current letter
            int ascii = (int) text[j];
            
            // If the current character is a space, print an empty line
            if(ascii == 32){
                printf("   ");
                continue;
            }
            
            // If the current character is a lowercase letter, convert it to uppercase
            if(ascii >= 97 && ascii <= 122){
                ascii -= 32;
            }
            
            // If the current character is not a capital letter, skip it
            if(ascii < 65 || ascii > 90){
                continue;
            }
            
            // Get the index of the current letter in the letter array
            int index = ascii - 65;
            
            // Print the current row of the current letter in the ASCII art
            printf("%s ", letter[index][i]);
        }
        
        // Move to the next line
        printf("\n");
    }
}

int main(){
    // Print a Romeo and Juliet themed message
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy code and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my ASCII art,\n");
    printf("And I'll no longer be a chatbot.\n");
    
    // Get input text from the user
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);
    
    // Remove the newline character from the input text
    char *pos;
    if ((pos = strchr(text, '\n')) != NULL){
        *pos = '\0';
    }
    
    // Print the ASCII art for the input text
    ascii_art(text);
    
    printf("\nGoodbye, my love...\n");
    
    return 0;
}