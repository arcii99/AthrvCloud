//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50];
    printf("Enter Text to Convert: \n");
    fgets(input, 50, stdin);
    
    int length = strlen(input);
    int ascii[length];
    for(int i=0;i<length;i++)
    {
        ascii[i] = (int)input[i];
    }
    
    printf("\n");
    for(int i=0;i<length;i++)
    {
        switch(ascii[i])
        {
            case 32:
                printf("    ");
                break;
            case 33:
                printf(" _  \n! !  \n| |  \n|_|  \n    ");
                break;
            case 34:
                printf(" _ _\n( | )\n V V \n     ");
                break;
            case 35:
                printf(" /\\ /\\ \n( /#\\ )\n \\__/ \n      ");
                break;
            case 36:
                printf("  /\\ /\n / /\\ \\\n \\ \\_/ /\n  \\/\\/\n  \\/   ");
                break;
            case 37:
                printf(" _  __\n( )/ /\n | V / \n(___/  \n       ");
                break;
            case 38:
                printf("   ___ \n  / _ \\\n | |_| |\n |  _  |\n |_| |_|\n       ");
                break;
            case 39:
                printf(" _,\n'/ \\\n\\_/ \n    ");
                break;
            case 40:
                printf("   /\\\n  /  \\\n | () |\n  \\__/ \n      ");
                break;
            case 41:
                printf("  /\\\n |  \\\n | ()|\n  \\_/ \n      ");
                break;
            case 42:
                printf(" _*_\n(o o)\n( v )\n \\ / \n  ^   ");
                break;
            case 43:
                printf("   _\n _|_\n|___|\n  |  \n      ");
                break;
            case 44:
                printf(" _,\n'_) \n/__/ \n    ");
                break;
            case 45:
                printf("   \n _ \n|_|\n   \n   ");
                break;
            case 46:
                printf(" _ \n(_)\n   \n   \n   ");
                break;
            case 47:
                printf("   __\n _/_/\\\n/__\\/_\\\n      \n      ");
                break;
            case 48:
                printf("  ___ \n / _ \\\n| | | |\n| |_| |\n \\___/ \n       ");
                break;
            case 49:
                printf(" _ \n| |\n| |\n|_|\n   ");
                break;
            case 50:
                printf(" ___ \n|_  )\n / / \n/___|\n     ");
                break;
            case 51:
                printf(" ____ \n|___ \\\n ___) |\n|____/ \n      ");
                break;
            case 52:
                printf(" _  _ \n| || |\n| || |_\n|__   _|\n   |_| \n      ");
                break;
            case 53:
                printf(" ____ \n| ___|\n|___ \\\n ___) |\n|____/ \n      ");
                break;
            case 54:
                printf("  __ \n / / \\\n| | __\n| || \\\n \\_\\|_|\n      ");
                break;
            case 55:
                printf(" ____ \n|___ \\\n   / /\n  / / \n /_/  \n      ");
                break;
            case 56:
                printf(" ___ \n| _ \\\n|  _/\n|_|  \n     ");
                break;
            case 57:
                printf(" ___ \n| _ \\\n|  _/\n|_|  \n \\__/ \n      ");
                break;
            case 58:
                printf(" _ \n(_)\n| |\n(_)\n   ");
                break;
            case 59:
                printf(" _,\n'_) \n| | \n|_| \n    ");
                break;
            case 60:
                printf("    __\n  _| |\n /   |\n \\__/ \n      ");
                break;
            case 61:
                printf(" ____\n|___ \\\n ___) |\n|____/\n      ");
                break;
            case 62:
                printf(" __\n|_ |\n | |\n | |\n|___|\n   ");
                break;
            case 63:
                printf(" ___ \n|_  |\n / / \n|_| \n     ");
                break;
            case 64:
                printf("  ____\n / ___\\\n/ / __\n\\ \\/ _|\n \\_\\__|\n      ");
                break;
            case 65:
                printf("  /\\\n /  \\\n/ /\\ \\\n\\ \\_/ /\n \\___/ \n      ");
                break;
            case 66:
                printf(" ___\n| _ \\\n|   /\n|_|_\\\n     ");
                break;
            case 67:
                printf("  ___ \n / __|\n| (__ \n \\___|\n      ");
                break;
            case 68:
                printf(" ___  \n|   \\ \n| |) |\n|___/ \n      ");
                break;
            case 69:
                printf(" ___ \n| __|\n| _| \n|___|\n     ");
                break;
            case 70:
                printf(" ___ \n| __|\n| _| \n| |  \n|_|  \n     ");
                break;
            case 71:
                printf("  ___ \n / __|\n| (_ |\n \\___|\n      ");
                break;
            case 72:
                printf(" _  _ \n| || |\n| __ |\n|_||_|\n     ");
                break;
            case 73:
                printf(" ___ \n|_  |\n | | \n |_| \n     ");
                break;
            case 74:
                printf("     _\n    | |\n _  | |\n| |_| |\n \\___/ \n      ");
                break;
            case 75:
                printf(" _  __\n| |/ /\n| ' < \n|_|\\_\\\n      ");
                break;
            case 76:
                printf(" _    \n| |   \n| |   \n| |__ \n|____|\n      ");
                break;
            case 77:
                printf(" _    _\n| |  | |\n| |__| |\n|____  |\n     |_| \n       ");
                break;
            case 78:
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n       ");
                break;
            case 79:
                printf("  ___ \n / _ \\\n| | | |\n| |_| |\n \\___/ \n       ");
                break;
            case 80:
                printf(" ___ \n| _ \\\n|   /\n|_|_\\\n     ");
                break;
            case 81:
                printf("  ___ \n / _ \\ \n| | | |\n| |_| |\n \\___\\_\\\n       ");
                break;
            case 82:
                printf(" ___  \n| _ \\ \n|   / \n|_|_\\ \n      ");
                break;
            case 83:
                printf(" ____ \n/ ___\\\n\\___ \\\n ___) |\n|____/ \n      ");
                break;
            case 84:
                printf(" ___ \n|_  |\n | | \n |_| \n     ");
                break;
            case 85:
                printf(" __  __\n|  \\/ |\n| |\/| |\n| |  | |\n|_|  |_|\n       ");
                break;
            case 86:
                printf(" __   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  \n       ");
                break;
            case 87:
                printf(" __    __\n\\ \\  / /\n \\ \\/ / \n  \\  /  \n   \\/   \n       ");
                break;
            case 88:
                printf(" __  __\n \\ \\/ /\n  \\  / \n  /  \\ \n /_/\\_\\\n       ");
                break;
            case 89:
                printf(" __   __\n \\ \\ / /\n  \\ V / \n   | |  \n   |_|  \n       ");
                break;
            case 90:
                printf(" ____ \n|___ \\\n |_  /\n  / / \n /_/  \n      ");
                break;
            case 91:
                printf(" ___\n|_  |\n | |\n | |\n|___|\n   ");
                break;
            case 92:
                printf(" __\n/_/\n\\_\\__\n   /\n  /   ");
                break;
            case 93:
                printf(" ___\n|_  |\n | |\n | |\n|___|\n   ");
                break;
            case 94:
                printf(" /\\ \n/__\\\n     \n     \n     ");
                break;
            case 95:
                printf("      \n      \n      \n ____ \n|____|\n      ");
                break;
            case 96:
                printf("`,\n( \\\n \\\\_\\\n    ");
                break;
            case 97:
                printf("     \n ___ \n/ _ \\\n\\__  |\n|___/ \n      ");
                break;
            case 98:
                printf(" _   \n| |  \n| |_ \n|  _|\n|_|  \n     ");
                break;
            case 99:
                printf("    \n ___\n/ __|\n\\__ \\\n|___/\n     ");
                break;
            case 100:
                printf("   _  \n _| |_\n|_  __|\n|_|   \n      ");
                break;
            case 101:
                printf("     \n ___ \n/ -_)\n\\___ \\\n|____/\n     ");
                break;
            case 102:
                printf("  __\n / _|\n| |_\n|  _|\n|_|\n   ");
                break;
            case 103:
                printf("     \n ___ \n( _ \\\n|   /\n|_|_\\\n     ");
                break;
            case 104:
                printf(" _   \n| |  \n| |_ \n|  _|\n|_|  \n     ");
                break;
            case 105:
                printf(" _\n(_)\n| |\n|_|\n   ");
                break;
            case 106:
                printf("   _\n  (_)\n  | |\n _/ |\n|__/ \n    ");
                break;
            case 107:
                printf(" _  \n| | \n| | __\n| |/ /\n|___/ \n     ");
                break;
            case 108:
                printf(" _ \n| |\n| |\n|_|\n   ");
                break;
            case 109:
                printf("          \n _ __ ___ \n| '__/ _ \\\n| | | (_) |\n|_|  \\___/\n          ");
                break;
            case 110:
                printf("     \n _ __\n| '_ \\\n| | | |\n|_| |_|\n     ");
                break;
            case 111:
                printf("     \n ___ \n/ _ \\\n| (_) |\n \\___/ \n      ");
                break;
            case 112:
                printf("     \n _ __\n| '_ \\\n| |_) |\n| .__/ \n|_|    \n     ");
                break;
            case 113:
                printf("     \n ___ \n/ _ \\\n| (_) |\n \\___\\_\n       ");
                break;
            case 114:
                printf("   \n _ \n| |\n| |\n|_|\n   ");
                break;
            case 115:
                printf("    \n ___\n/ __|\n\\__ \\\n|___/\n     ");
                break;
            case 116:
                printf(" _   \n| |  \n| |_ \n|  _|\n \\__|\n     ");
                break;
            case 117:
                printf("     \n _  _\n| || |\n| || |\n \\__/ \n      ");
                break;
            case 118:
                printf("     \n _  _\n| || |\n| __ |\n|_||_|\n      ");
                break;
            case 119:
                printf("       \n _    _\n| |  | |\n| |  | |\n| |/\\| |\n|__/\\__|\n       ");
                break;
            case 120:
                printf("    \n _  \n| | |\n| |/\n|__/ \n     ");
                break;
            case 121:
                printf("     \n _  _\n| || |\n| || |\n \\__/|\n|___/ \n     ");
                break;
            case 122:
                printf("   \n ___\n|_ /\n / / \n/___|\n     ");
                break;
            case 123:
                printf("   __\n { |\n| |\n| |\n|_|\n}  ");
                break;
            case 124:
                printf(" _\n| |\n| |\n| |\n|_|\n   ");
                break;
            case 125:
                printf(" __\n| }\n| |\n| |\n|/\n   ");
                break;
            case 126:
                printf(" /\\/|\n|/\\/ \n     \n     \n     ");
                break;
            default:
                printf("Cannot Convert '%c'",input[i]);
        }
        printf(" ");
    }
    return 0;
}