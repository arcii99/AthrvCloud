//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>

int main() {

    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    int i, j;
    for(i = 0; text[i] != '\0'; i++) {

        switch(text[i]) {
            case 'a':
                printf(" #####  \n");
                printf("#     # \n");
                printf("####### \n");
                printf("#     # \n");
                printf("#     # \n");
                break;

            case 'b':
                printf("######  \n");
                printf("#     # \n");
                printf("######  \n");
                printf("#     # \n");
                printf("######  \n");
                break;

            case 'c':
                printf(" ###### \n");
                printf("#       \n");
                printf("#       \n");
                printf("#       \n");
                printf(" ###### \n");
                break;

            case 'd':
                printf("#####   \n");
                printf("#    #  \n");
                printf("#     # \n");
                printf("#    #  \n");
                printf("#####   \n");
                break;

            case 'e':
                printf("####### \n");
                printf("#       \n");
                printf("######  \n");
                printf("#       \n");
                printf("####### \n");
                break;

            case 'f':
                printf("####### \n");
                printf("#       \n");
                printf("######  \n");
                printf("#       \n");
                printf("#       \n");
                break;

            case 'g':
                printf(" ###### \n");
                printf("#       \n");
                printf("#   ### \n");
                printf("#     # \n");
                printf(" ###### \n");
                break;

            case 'h':
                printf("#     # \n");
                printf("#     # \n");
                printf("####### \n");
                printf("#     # \n");
                printf("#     # \n");
                break;

            case 'i':
                printf("##### \n");
                printf("  #   \n");
                printf("  #   \n");
                printf("  #   \n");
                printf("##### \n");
                break;

            case 'j':
                printf("###### \n");
                printf("    #   \n");
                printf("    #   \n");
                printf("#   #   \n");
                printf("####    \n");
                break;

            case 'k':
                printf("#    # \n");
                printf("#   #  \n");
                printf("###    \n");
                printf("#   #  \n");
                printf("#    # \n");
                break;

            case 'l':
                printf("#       \n");
                printf("#       \n");
                printf("#       \n");
                printf("#       \n");
                printf("####### \n");
                break;

            case 'm':
                printf("#     # \n");
                printf("##   ## \n");
                printf("# # # # \n");
                printf("#  #  # \n");
                printf("#     # \n");
                break;

            case 'n':
                printf("#     # \n");
                printf("##    # \n");
                printf("# #   # \n");
                printf("#  #  # \n");
                printf("#   # # \n");
                break;

            case 'o':
                printf(" #####  \n");
                printf("#     # \n");
                printf("#     # \n");
                printf("#     # \n");
                printf(" #####  \n");
                break;

            case 'p':
                printf("######  \n");
                printf("#     # \n");
                printf("######  \n");
                printf("#       \n");
                printf("#       \n");
                break;

            case 'q':
                printf(" #####  \n");
                printf("#     # \n");
                printf("#  #  # \n");
                printf("#   # # \n");
                printf(" #### # \n");
                break;

            case 'r':
                printf("######  \n");
                printf("#     # \n");
                printf("######  \n");
                printf("#   #   \n");
                printf("#    #  \n");
                break;

            case 's':
                printf(" ###### \n");
                printf("#       \n");
                printf(" ###### \n");
                printf("       #\n");
                printf("######  \n");
                break;

            case 't':
                printf("####### \n");
                printf("   #    \n");
                printf("   #    \n");
                printf("   #    \n");
                printf("   #    \n");
                break;

            case 'u':
                printf("#     # \n");
                printf("#     # \n");
                printf("#     # \n");
                printf("#     # \n");
                printf(" ###### \n");
                break;

            case 'v':
                printf("#     # \n");
                printf("#     # \n");
                printf(" #   #  \n");
                printf("  # #   \n");
                printf("   #    \n");
                break;

            case 'w':
                printf("#     # \n");
                printf("#  #  # \n");
                printf("#  #  # \n");
                printf("#  #  # \n");
                printf(" ## ##  \n");
                break;

            case 'x':
                printf("#     # \n");
                printf(" #   #  \n");
                printf("  # #   \n");
                printf(" #   #  \n");
                printf("#     # \n");
                break;

            case 'y':
                printf("#     # \n");
                printf(" #   #  \n");
                printf("  # #   \n");
                printf("   #    \n");
                printf("   #    \n");
                break;

            case 'z':
                printf("####### \n");
                printf("     #  \n");
                printf("   #    \n");
                printf("  #     \n");
                printf("####### \n");
                break;

            case ' ':
                printf("  \n");
                printf("  \n");
                printf("  \n");
                printf("  \n");
                printf("  \n");
                break;

            default:
                printf("Invalid character found.\n");
                return 0;
        }
    }

    return 0;
}