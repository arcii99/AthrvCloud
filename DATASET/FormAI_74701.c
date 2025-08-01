//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>

char arts[26][10][10] = {
    {
        "   __    ",
        " /'__`\\  ",
        "/\\ \\_\\ \\ ",
        "\\ \\____ \\",
        " \\/\\ \\_\\ \\/",
        "  \\ \\____/\\",
        "   \\/___/\\/",
        "          ",
        "          "
    }, 
    {
        " _______ ",
        "/\\  ___ \\",
        "\\ \\ \\_\\ \\",
        " \\ \\  __/",
        "  \\ \\ \\/ ",
        "   \\ \\_\\ ",
        "    \\/_/ ",
        "         ",
        "         "
    }, 
    {
        " ______  ",
        "/\\__  _\\ ",
        "\\/_/\\ \\/ ",
        "   \\/_/\\_\\",
        "    /\\/_/",
        "   /\\_\\_\\",
        "   \\/_/ /",
        "         ",
        "         "
    },
    {
        " _______",
        "/\\ o o /\\",
        "\\_\\_v_/_/",
        "  /`/\\`\\ ",
        " ||   || ",
        " \\\\ _ // ",
        "  \\/`\\__/",
        "         ",
        "         "
    },
    {
        " ______",
        "/\\  == \\",
        "\\ \\__\\ \\",
        " \\/\\_____\\",
        "  \\/_____/",
        "          ",
        "          ",
        "         ",
        "         "
    },
    {
        "  ___  ",
        " /'___\\",
        "/\\ \\__/",
        "\\ \\___`\\",
        " \\/\\ \\_\\",
        "  \\ \\__/",
        "   \\/__/",
        "       ",
        "       "
    },
    {
        "  ______  ",
        "/\\__  _\\ ",
        "\\/_/\\ \\/ ",
        "   /\\_\\ \\",
        "   \\ \\ \\ \\",
        "    \\ \\_\\ \\",
        "     \\/_/\\/",
        "          ",
        "          "
    },
    {
        " _______",
        "/\\______\\",
        "\\/______/",
        " /\\   __/",
        " \\ \\ \\_\\ ",
        "  \\ \\____\\",
        "   \\/____/",
        "         ",
        "         "
    },
    {
        "  ______   ",
        "/\\  ___\\  ",
        "\\ \\___  \\ ",
        " \\/\\_____\\",
        "  \\/____ /",
        "          ",
        "          ",
        "          ",
        "          "
    },
    {
        "   __  __",
        " /\\ \\_\\ \\",
        "/\\ \\____ \\",
        "\\ \\_____\\/",
        " \\/_____/",
        "          ",
        "          ",
        "          ",
        "          "
    },
    {
        "  ___  ___",
        " /'___\\/\n",
        "/\\ \\___\\/",
        "\\ \\___  ",
        "\\/\\ \\_\\ ",
        "   \\ \\__\\",
        "    \\/__/",
        "         ",
        "         "
    },
    {
        " _____  ",
        "/\\___ \\ ",
        "\\/__/\\ \\",
        "   _\\ \\ \\",
        " /\\ \\ \\ \\",
        " \\ \\___,_\\",
        "  \\/__,_ /",
        "        ",
        "        "
    },
    {
        " _______ ",
        "/\\______\\",
        "\\/______/",
        "    /\\ \\",
        "   _\\ \\ \\",
        " /\\ \\_\\ \\",
        " \\ \\____/",
        "  \\/___/ ",
        "         "
    },
    {
        " _____   ",
        "/\\  __-. ",
        "\\ \\ \\/\\ \\",
        " \\ \\____-",
        "  \\/____/",
        "         ",
        "         ",
        "         ",
        "         "
    },
    {
        "  ______   ",
        "/\\  ___\\   ",
        "\\ \\___  \\  ",
        " \\/\\_____\\ ",
        "  \\/_____/\\",
        "          \\/",
        "           ",
        "           ",
        "           "
    },
    {
        " _______ ",
        "/\\__  _\\",
        "\\/_/\\ \\/   ",
        "   \\ \\ \\  ",
        "    \\ \\ \\   ",
        "     \\ \\_\\  ",
        "      \\/_/ ",
        "         ",
        "         "
    },
    {
        "   __    ",
        " /'__`\\  ",
        "/\\_\\L\\ \\ ",
        "\\/_/_\\_<_",
        "  /\\ \\L\\ \\",
        "  \\ \\____/",
        "   \\/___/ ",
        "          ",
        "          "
    },
    {
        " _______",
        "/\\______\\",
        "\\/___/  /",
        "    /\\ \\",
        " __ \\ \\ \\",
        "/\\ \\_\\ \\_\\",
        "\\ \\______/",
        " \\/_____/ ",
        "         "
    },
    {
        "  ___       ",
        " /\\_ \\      ",
        "/\\ \\L\\ \\  ",
        "\\ \\___,_\\",
        " \\/__,_ /",
        "           ",
        "           ",
        "           ",
        "           "
    },
    {
        " ______  ",
        "/\\__  _\\ ",
        "\\/_/\\ \\/   ", 
        "   \\ \\ \\   ",
        "    \\ \\ \\  ",
        "     \\ \\_\\ ",
        "      \\/_/ ",
        "         ",
        "         "
    },
    {
        " ______   ",
        "/\\  __ \\  ",
        "\\ \\ \\/\\ \\ ",
        " \\ \\____- ",
        "  \\/____/\\",
        "         \\/",
        "           ",
        "           ",
        "           "
    },
    {
        " _______ ",
        "/\\______\\",
        "\\/______/",
        "      /\\ \\",
        "     _\\_\\ \\  ",
        "    /\\_____\\",
        "    \\/____/",
        "         ",
        "         "
    },
    {
        " _______ ",
        "/\\______\\",
        "\\/______/",
        "    /\\ \\",
        "   /  \\ \\",
        "  /_/\\_\\_\\",
        "  \\ \\/\\/ /",
        "   \\/_/\\_\\",
        "         "
    },
    {
        "         ",
        "         ",
        "         ",
        "         ",
        "         ",
        "         ",
        "  ______ ",
        " /_____/\\",
        " \\______/"
    },
    {
        " _______",
        "/\\  ___\\",
        "\\ \\___  \\",
        "\\/\\_____\\",
        " \\/_____/",
        "         ",
        "         ",
        "         ",
        "         "
    },
    {
        " _______",
        "/\\  __ \\",
        "\\ \\ \\/\\_\\",
        " \\ \\___\\/",
        "  \\/\\___/",
        "   \\/__/ ",
        "         ",
        "         ",
        "         "
    }
};

int main()
{
    char c[50];
    printf("Enter a word: ");
    gets(c);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < strlen(c); j++)
        {
            int k = c[j] - 'a';
            if(k < 0 || k > 25)
                continue;
            printf("%s   ", arts[k][i]);
        }
        printf("\n");
    }
    return 0;
}