//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

char asciiArt[128][MAX_LINE_LENGTH] = {
// ASCII ART FOR 0:
"  #####  \n"
" #     # \n"
"#       #\n"
"#       #\n"
"#       #\n"
" #     # \n"
"  #####  \n",
// ASCII ART FOR 1:
"    #    \n"
"   ##    \n"
"  # #    \n"
"    #    \n"
"    #    \n"
"    #    \n"
"  #####  \n",
// ASCII ART FOR 2:
"  #####  \n"
"       # \n"
"       # \n"
"  #####  \n"
" #       \n"
"#        \n"
"########\n",
// ASCII ART FOR 3:
"  #####  \n"
"       # \n"
"       # \n"
"  #####  \n"
"       # \n"
"       # \n"
"  #####  \n",
// ASCII ART FOR 4:
"#       #\n"
"#       #\n"
"#       #\n"
"########\n"
"      # \n"
"      # \n"
"      # \n",
// ASCII ART FOR 5:
"########\n"
"#        \n"
"#        \n"
"########\n"
"       # \n"
"       # \n"
"########\n",
// ASCII ART FOR 6:
"  #####  \n"
" #       \n"
"#        \n"
"########\n"
"#       #\n"
"#       #\n"
"########\n",
// ASCII ART FOR 7:
"########\n"
"       # \n"
"      #  \n"
"     #   \n"
"    #    \n"
"   #     \n"
"  #      \n",
// ASCII ART FOR 8:
"  #####  \n"
"#       #\n"
"#       #\n"
"########\n"
"#       #\n"
"#       #\n"
"  #####  \n",
// ASCII ART FOR 9:
"  #####  \n"
"#       #\n"
"#       #\n"
"  ######\n"
"       # \n"
"       # \n"
"  #####  \n",
// ASCII ART FOR A:
"    #    \n"
"   # #   \n"
"  #   #  \n"
" ####### \n"
"#       #\n"
"#       #\n"
"#       #\n",
// ASCII ART FOR B:
"########\n"
"#       #\n"
"#       #\n"
"########\n"
"#       #\n"
"#       #\n"
"########\n",

// ASCII ART FOR C:
"  #####  \n"
" #       \n"
"#        \n"
"#        \n"
"#        \n"
" #       \n"
"  #####  \n",

// ASCII ART FOR D:
"########\n"
"#       #\n"
"#       #\n"
"#       #\n"
"#       #\n"
"#       #\n"
"########\n",

// ASCII ART FOR E:
"########\n"
"#        \n"
"#        \n"
"########\n"
"#        \n"
"#        \n"
"########\n",

// ASCII ART FOR F:
"########\n"
"#        \n"
"#        \n"
"########\n"
"#        \n"
"#        \n"
"#        \n",

// ASCII ART FOR G:
"  #####  \n"
" #       \n"
"#        \n"
"#    ####\n"
"#       #\n"
" #      #\n"
"  ##### #\n",

// ASCII ART FOR H:
"#       #\n"
"#       #\n"
"#       #\n"
"########\n"
"#       #\n"
"#       #\n"
"#       #\n",

// ASCII ART FOR I:
"########\n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"########\n",

// ASCII ART FOR J:
"     ###\n"
"       #\n"
"       #\n"
"       #\n"
"       #\n"
"#      #\n"
" ###### \n",

// ASCII ART FOR K:
"#     # \n"
"#    #  \n"
"#   #   \n"
"####    \n"
"#   #   \n"
"#    #  \n"
"#     # \n",

// ASCII ART FOR L:
"#        \n"
"#        \n"
"#        \n"
"#        \n"
"#        \n"
"#        \n"
"########\n",

// ASCII ART FOR M:
"#       #\n"
"##     ##\n"
"# #   # #\n"
"#  # #  #\n"
"#   #   #\n"
"#       #\n"
"#       #\n",

// ASCII ART FOR N:
"#       #\n"
"##      #\n"
"# #     #\n"
"#  #    #\n"
"#   #   #\n"
"#    #  #\n"
"#     # #\n",

// ASCII ART FOR O:
"  #####  \n"
" #     # \n"
"#       #\n"
"#       #\n"
"#       #\n"
" #     # \n"
"  #####  \n",

// ASCII ART FOR P:
"########\n"
"#       #\n"
"#       #\n"
"########\n"
"#        \n"
"#        \n"
"#        \n",

// ASCII ART FOR Q:
"  #####  \n"
" #     # \n"
"#       #\n"
"#  #    #\n"
"#   #   #\n"
" #     # \n"
"  ##### #\n",

// ASCII ART FOR R:
"########\n"
"#       #\n"
"#       #\n"
"########\n"
"#    #   \n"
"#     #  \n"
"#      # \n",

// ASCII ART FOR S:
"  #####  \n"
" #       \n"
" #       \n"
"  #####  \n"
"       # \n"
"       # \n"
"  #####  \n",

// ASCII ART FOR T:
"########\n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"   ##   \n"
"   ##   \n",

// ASCII ART FOR U:
"#       #\n"
"#       #\n"
"#       #\n"
"#       #\n"
"#       #\n"
" #     # \n"
"  #####  \n",

// ASCII ART FOR V:
"#       #\n"
"#       #\n"
" #     # \n"
"  #   #  \n"
"   # #   \n"
"    #    \n"
"    #    \n",

// ASCII ART FOR W:
"#       #\n"
"#       #\n"
"#  # #  #\n"
"#  # #  #\n"
"#  # #  #\n"
" # # # # \n"
"  #   #  \n",

// ASCII ART FOR X:
"#       #\n"
" #     # \n"
"  #   #  \n"
"   # #   \n"
"  #   #  \n"
" #     # \n"
"#       #\n",

// ASCII ART FOR Y:
"#       #\n"
" #     # \n"
"  #   #  \n"
"   # #   \n"
"    #    \n"
"    #    \n"
"    #    \n",

// ASCII ART FOR Z:
"########\n"
"      # \n"
"     #  \n"
"    #   \n"
"   #    \n"
"  #     \n"
"########\n"
};

int main() {
    char inputMsg[MAX_LINE_LENGTH];
    printf("Enter your message: ");
    fgets(inputMsg, MAX_LINE_LENGTH, stdin);

    int inputLength = strlen(inputMsg);

    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        for (int j = 0; j < inputLength; j++) {
            if (inputMsg[j] == '\n') {
                continue;
            }
            if ((int) inputMsg[j] >= 48 && (int) inputMsg[j] <= 90) {
                printf("%s", asciiArt[(int) inputMsg[j]]);
            } else {
                printf("          ");
            }
        }
        printf("\n");
    }

    return 0;
}