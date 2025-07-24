//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {
    // define the ASCII art character map
    char ASCII_chars[95][8] = {
        "        ", "    !   ", "    \"   ", "    #   ", "    $   ",
        "    %   ", "    &   ", "    '   ", "    (   ", "    )   ",
        "    *   ", "    +   ", "    ,   ", "    -   ", "    .   ",
        "    /   ", "    0   ", "    1   ", "    2   ", "    3   ",
        "    4   ", "    5   ", "    6   ", "    7   ", "    8   ",
        "    9   ", "    :   ", "    ;   ", "    <   ", "    =   ",
        "    >   ", "    ?   ", "    @   ", "    A   ", "    B   ",
        "    C   ", "    D   ", "    E   ", "    F   ", "    G   ",
        "    H   ", "    I   ", "    J   ", "    K   ", "    L   ",
        "    M   ", "    N   ", "    O   ", "    P   ", "    Q   ",
        "    R   ", "    S   ", "    T   ", "    U   ", "    V   ",
        "    W   ", "    X   ", "    Y   ", "    Z   ", "    [   ",
        "    \\   ", "    ]   ", "    ^   ", "    _   ", "    `   ",
        "    a   ", "    b   ", "    c   ", "    d   ", "    e   ",
        "    f   ", "    g   ", "    h   ", "    i   ", "    j   ",
        "    k   ", "    l   ", "    m   ", "    n   ", "    o   ",
        "    p   ", "    q   ", "    r   ", "    s   ", "    t   ",
        "    u   ", "    v   ", "    w   ", "    x   ", "    y   ",
        "    z   ", "    {   ", "    |   ", "    }   ", "    ~   "
    };
    
    char input_text[100]; // variable to store user input
    printf("Enter text to convert to ASCII art:\n");
    fgets(input_text, sizeof(input_text), stdin); // get user input
    
    int length = strlen(input_text); // get length of text
    
    // loop through each character in text
    for (int i = 0; i < length; i++) {
        if (input_text[i] == '\n') { // if end of line character, skip
            continue;
        }
        else { // else, get ASCII art character equivalent
            int index = (int) input_text[i] - 32;
            if (index < 0 || index >= 95) { // if out of range, print space
                printf("        ");
            }
            else { // else, print ASCII art character
                printf("%s", ASCII_chars[index]);
            }
        }
        printf(" "); // add space between characters
    }
    
    printf("\n"); // end of line
    
    return 0;
}