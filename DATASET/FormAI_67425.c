//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void convert_character(char c)
{
    switch(c)
    {
        case 'a': printf("  __  \n / _` |\n| (_| |\n \\__,_|\n"); break;
        case 'b': printf("____   \n| __ ) \n|  _ \\ \n| |_) |\n|____/ \n"); break;
        case 'c': printf(" _____ \n| ____|\n| |__  \n|___ \\ \n ___) |\n|____/ \n"); break;
        case 'd': printf("____   \n|  _ \\ \n| |_) |\n|  _ < \n|____/ \n"); break;
        case 'e': printf(" _____ \n| ____|\n|  _|  \n| |___ \n|_____|"); break;
        case 'f': printf(" _____ \n|  ___|\n| |_   \n|  _|  \n|_|    \n"); break;
        case 'g': printf(" _____ \n| ____|\n| |__  \n|___ \\ \n ___) |\n|____/ \n"); break;
        case 'h': printf("_   _  \n| | | |\n| |_| |\n|  _  |\n|_| |_|\n"); break;
        case 'i': printf(" ___ \n|_ _|\n | | \n | | \n|___|\n"); break;
        case 'j': printf("     _ \n    | |\n  __| |\n / _` |\n|____/ \n"); break;
        case 'k': printf("_  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\"); break;
        case 'l': printf("_    \n| |   \n| |   \n| |___\n|_____|"); break;
        case 'm': printf("___ ___\n|_ _/ _ \\ \n | | | | |\n | | |_| |\n|___\\___/\n"); break;
        case 'n': printf("_   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n"); break;
        case 'o': printf(" _____ \n| ____|\n| |__  \n|___ \\ \n ___) |\n|____/ \n"); break;
        case 'p': printf("______ \n| ___ \\ \n| |_/ / \n| ___ \\ \n| |_/ / \n\\____/  \n"); break;
        case 'q': printf(" _____ \n| ____|\n| |__  \n|___ \\ \n ___) |\n|____/ \n    |_| \n"); break;
        case 'r': printf("______ \n| ___ \\ \n| |_/ / \n|    / \n| |\\ \\ \n\\_| \\_|\n"); break;
        case 's': printf(" _____ \n|  ___| \n| |__ \n|  __| \n| |___ \n|_____| \n"); break;
        case 't': printf(" _____ \n|_   _| \n  | |   \n  | |   \n  |_|   \n"); break;
        case 'u': printf("_   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n"); break;
        case 'v': printf("__     __\n\\ \\   / /\n \\ \\ / / \n  \\ V / \n   \\_/ \n"); break;
        case 'w': printf("__        __ \n\\ \\      / / \n \\ \\ /\\ / / \n  \\ V  V / \n   \\_/\\_/  \n"); break;
        case 'x': printf("__  __\n\\ \\/ /\n \\  / \n /  \\ \n/_/\\_\\\n"); break;
        case 'y': printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  "); break;
        case 'z': printf(" _____\n|__  / \n  / / \n / /_ \n/____|\n"); break;
        case ' ': printf("     \n     \n     \n     \n     \n"); break;
        case '0': printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n"); break;
        case '1': printf("  __ \n /_ |\n  | |\n  | |\n  |_|"); break;
        case '2': printf(" ____  \n|___ \\ \n  __) |\n |__ < \n ___) |\n|____/ \n"); break;
        case '3': printf(" ____  \n|___ \\ \n  __) |\n |__ < \n ___) |\n|____/ \n"); break;
        case '4': printf(" _  _   \n| || |  \n| || |_ \n|__   _|\n   |_|  \n"); break;
        case '5': printf(" ____ \n| ___|\n|___ \\ \n ___) |\n|____/ \n"); break;
        case '6': printf("  __   \n / /_  \n| '_ \\ \n| (_) |\n \\___/ \n"); break;
        case '7': printf(" _____ \n|___  |\n   / / \n  / /  \n /_/   \n"); break;
        case '8': printf("  ___  \n ( _ ) \n / _ \\ \n| (_) |\n \\___/ \n"); break;
        case '9': printf("  ___  \n / _ \\ \n| (_) |\n \\__, |\n   /_/ \n"); break;
        case '!': printf(" _ \n| |\n| |\n|_|\n(_)"); break;
        case '@': printf("  _____        \n / ____|      \n| |     ___   _\n| |    / _ \\ / /\n| |___| (_) / / \n \\_____\\___/_/  \n"); break;
        case '#': printf("  _   _    \n | | | |   \n | |_| | __\n |  _  |/ _|\n | | | |  _| \n |_| |_|\\__| \n"); break;
        case '$': printf("  ___  \n / __| \n| (__  \n \\___| \n|_|    \n"); break;
        case '%': printf(" _  __\n(_)/ /_\n  / / _ \\\n / / (_) |\n/_/ \\___/ "); break;
        case '^': printf(" /\\ \n/  \\ \n"); break;
        case '&': printf("   ___  \n  / _ \\ \n | | | | \n | |_| | \n  \\___/ \n"); break;
        case '*': printf(" /\\/\\ \n/    \\\n"); break;
        case '(': printf("  __\n / /\n| | \n| | \n| | \n \\_\\\n"); break;
        case ')': printf(" __ \n \\ \\\n  | |\n  | |\n  | |\n/_/ \n"); break;
        case '-': printf("     \n     \n  ___\n |___|\n     \n"); break;
        case '_': printf("        \n        \n        \n        \n _______\n|_______|\n"); break;
        case '=': printf("     \n ____\n|____|\n ____\n|____|\n"); break;
        case '+': printf("    \n  _ \n | |\n-| |\n | |\n    \n"); break;
        case '[': printf(" ___ \n|  _|\n| |  \n| |  \n| |_ \n|___|\n"); break;
        case ']': printf(" ___ \n|_  |\n  | |\n  | |\n _| |\n|___|\n"); break;
        case '{': printf("    __\n   / /\n  | | \n< <  \n  | |\n   \\_\\\n"); break;
        case '}': printf("__    \n\\ \\   \n | |  \n > > \n| |  \n\\_\\ \n"); break;
        case '|': printf(" _ \n| |\n| |\n| |\n|_|\n"); break;
        case '\\': printf("\\\n \\\n  \\\n   \\\n"); break;
        case ';': printf("   \n _ \n| |\n| |\n| |\n|_|\n"); break;
        case ':': printf("   \n _ \n| |\n| |\n|_|\n"); break;
        case '\'': printf(" _ \n| |\n| |\n|_|\n  \n"); break;
        case '\"': printf(" _   _ \n| | | |\n| |_| |\n \\__, |\n    |_|"); break;
        case ',': printf("   \n   \n _ \n| |\n| |\n|_\n"); break;
        case '<': printf("  __\n / /\n/ / \n\\ \\ \n \\_\\\n"); break;
        case '>': printf("__  \n\\ \\\n \\ \\\n / /\n/_/ \n"); break;
        case '.': printf("   \n   \n _ \n| |\n|_|\n"); break;
        case '/': printf("/\n \\\n  \\\n   \\\n"); break;
        case '?': printf(" ____ \n|___ \\ \n  __) |\n |__ < \n ___) |\n|____/ \n"); break;
        default: printf("Not defined.\n"); break;
    }
}

void convert_text(char* text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        convert_character(text[i]);
        i++;
    }
}

int main()
{
    char text[256];
    printf("Enter text to convert: ");
    fgets(text, 256, stdin);
    convert_text(text);
    
    return 0;
}