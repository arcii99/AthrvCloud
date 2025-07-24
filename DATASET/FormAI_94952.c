//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>

// Function to calculate the frequency of a character in a given string
int frequency(char str[], char c)
{
    int freq = 0;
    int length = strlen(str);
    
    // Loop through the string
    for (int i = 0; i < length; i++)
    {
        // If the character is found, increment the frequency count
        if (str[i] == c)
        {
            freq++;
        }
    }
    
    // Return the frequency count
    return freq;
}

int main()
{
    char str[100];
    
    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input string
    str[strcspn(str, "\n")] = '\0';
    
    // Calculate the length of the string
    int length = strlen(str);
    
    // Calculate the frequency of each letter in the string
    int freq_a = frequency(str, 'a');
    int freq_b = frequency(str, 'b');
    int freq_c = frequency(str, 'c');
    int freq_d = frequency(str, 'd');
    int freq_e = frequency(str, 'e');
    int freq_f = frequency(str, 'f');
    int freq_g = frequency(str, 'g');
    int freq_h = frequency(str, 'h');
    int freq_i = frequency(str, 'i');
    int freq_j = frequency(str, 'j');
    int freq_k = frequency(str, 'k');
    int freq_l = frequency(str, 'l');
    int freq_m = frequency(str, 'm');
    int freq_n = frequency(str, 'n');
    int freq_o = frequency(str, 'o');
    int freq_p = frequency(str, 'p');
    int freq_q = frequency(str, 'q');
    int freq_r = frequency(str, 'r');
    int freq_s = frequency(str, 's');
    int freq_t = frequency(str, 't');
    int freq_u = frequency(str, 'u');
    int freq_v = frequency(str, 'v');
    int freq_w = frequency(str, 'w');
    int freq_x = frequency(str, 'x');
    int freq_y = frequency(str, 'y');
    int freq_z = frequency(str, 'z');
    
    // Calculate the total number of letters in the string
    int total_letters = freq_a + freq_b + freq_c + freq_d + freq_e + freq_f + 
                         freq_g + freq_h + freq_i + freq_j + freq_k + freq_l +
                         freq_m + freq_n + freq_o + freq_p + freq_q + freq_r +
                         freq_s + freq_t + freq_u + freq_v + freq_w + freq_x +
                         freq_y + freq_z;
    
    // Print out the letter frequency statistics
    printf("\nStatistics for your string:\n\n");
    printf("Length: %d\n\n", length);
    printf("a: %d (%.2f%%)\n", freq_a, ((float)freq_a / total_letters) * 100);
    printf("b: %d (%.2f%%)\n", freq_b, ((float)freq_b / total_letters) * 100);
    printf("c: %d (%.2f%%)\n", freq_c, ((float)freq_c / total_letters) * 100);
    printf("d: %d (%.2f%%)\n", freq_d, ((float)freq_d / total_letters) * 100);
    printf("e: %d (%.2f%%)\n", freq_e, ((float)freq_e / total_letters) * 100);
    printf("f: %d (%.2f%%)\n", freq_f, ((float)freq_f / total_letters) * 100);
    printf("g: %d (%.2f%%)\n", freq_g, ((float)freq_g / total_letters) * 100);
    printf("h: %d (%.2f%%)\n", freq_h, ((float)freq_h / total_letters) * 100);
    printf("i: %d (%.2f%%)\n", freq_i, ((float)freq_i / total_letters) * 100);
    printf("j: %d (%.2f%%)\n", freq_j, ((float)freq_j / total_letters) * 100);
    printf("k: %d (%.2f%%)\n", freq_k, ((float)freq_k / total_letters) * 100);
    printf("l: %d (%.2f%%)\n", freq_l, ((float)freq_l / total_letters) * 100);
    printf("m: %d (%.2f%%)\n", freq_m, ((float)freq_m / total_letters) * 100);
    printf("n: %d (%.2f%%)\n", freq_n, ((float)freq_n / total_letters) * 100);
    printf("o: %d (%.2f%%)\n", freq_o, ((float)freq_o / total_letters) * 100);
    printf("p: %d (%.2f%%)\n", freq_p, ((float)freq_p / total_letters) * 100);
    printf("q: %d (%.2f%%)\n", freq_q, ((float)freq_q / total_letters) * 100);
    printf("r: %d (%.2f%%)\n", freq_r, ((float)freq_r / total_letters) * 100);
    printf("s: %d (%.2f%%)\n", freq_s, ((float)freq_s / total_letters) * 100);
    printf("t: %d (%.2f%%)\n", freq_t, ((float)freq_t / total_letters) * 100);
    printf("u: %d (%.2f%%)\n", freq_u, ((float)freq_u / total_letters) * 100);
    printf("v: %d (%.2f%%)\n", freq_v, ((float)freq_v / total_letters) * 100);
    printf("w: %d (%.2f%%)\n", freq_w, ((float)freq_w / total_letters) * 100);
    printf("x: %d (%.2f%%)\n", freq_x, ((float)freq_x / total_letters) * 100);
    printf("y: %d (%.2f%%)\n", freq_y, ((float)freq_y / total_letters) * 100);
    printf("z: %d (%.2f%%)\n", freq_z, ((float)freq_z / total_letters) * 100);
    
    return 0;
}