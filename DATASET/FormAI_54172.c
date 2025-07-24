//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define PRECISION 1000000000

typedef struct {
    char symbol;
    int frequency;
} symbol_t;

symbol_t symbols[MAX_LEN];
int num_symbols = 0;

// Build a frequency table from the input string
void build_frequency_table(char* input) {
    char c;
    int i, j;

    for (i = 0; i < MAX_LEN; i++) {
        symbols[i].symbol = '\0';
        symbols[i].frequency = 0;
    }

    while ((c = *input++)) {
        for (i = 0; i < num_symbols; i++) {
            if (symbols[i].symbol == c) {
                symbols[i].frequency++;
                break;
            }
        }
        if (i == num_symbols) {
            symbols[i].symbol = c;
            symbols[i].frequency = 1;
            num_symbols++;
        }
    }

    // Sort symbols in descending order of frequency
    for (i = 0; i < num_symbols - 1; i++) {
        int max_index = i;
        for (j = i + 1; j < num_symbols; j++) {
            if (symbols[j].frequency > symbols[max_index].frequency) {
                max_index = j;
            }
        }
        symbol_t temp = symbols[i];
        symbols[i] = symbols[max_index];
        symbols[max_index] = temp;
    }
}

// Calculate the cumulative probabilities of each symbol
void calculate_probabilities(int* probabilities) {
    int sum = 0;
    int i;
    for (i = 0; i < num_symbols; i++) {
        sum += symbols[i].frequency;
        probabilities[i] = sum;
    }
}

// Encode the input string and return the resulting floating-point value
double arithmetic_encode(char* input) {
    int probabilities[MAX_LEN];
    int range_low = 0;
    int range_high = PRECISION - 1;
    int i;
    double result = 0;

    build_frequency_table(input);
    calculate_probabilities(probabilities);

    while (*input) {
        char c = *input++;
        int symbol_index;

        // Find the index of the symbol in the table
        for (i = 0; i < num_symbols; i++) {
            if (symbols[i].symbol == c) {
                symbol_index = i;
                break;
            }
        }

        // Update the range to correspond to the selected symbol's frequency
        int range_size = range_high - range_low + 1;
        range_high = range_low + range_size * probabilities[symbol_index] / symbols[num_symbols - 1].frequency - 1;
        range_low = range_low + range_size * probabilities[symbol_index - 1] / symbols[num_symbols - 1].frequency;

        // Re-scale the range to avoid precision loss
        while (range_low / (PRECISION / 10) == range_high / (PRECISION / 10)) {
            result = result * 10 + range_low / (PRECISION / 10);
            range_low = (range_low % (PRECISION / 10)) * 10;
            range_high = (range_high % (PRECISION / 10)) * 10 + 9;
        }
    }

    // Calculate the final result as the average of the range endpoints
    result = result * (range_high + range_low) / (2.0 * PRECISION);

    return result;
}

// Decode the input string from a floating-point value
void arithmetic_decode(double encoded_value, char* output) {
    int probabilities[MAX_LEN];
    int range_low = 0;
    int range_high = PRECISION - 1;
    int i;

    build_frequency_table(output);
    calculate_probabilities(probabilities);

    while (*output) {
        int symbol_index = -1;

        // Update the range to correspond to the encoded value
        for (i = 0; i < num_symbols; i++) {
            int range_size = range_high - range_low + 1;
            int symbol_range_low = range_low + range_size * probabilities[i - 1] / symbols[num_symbols - 1].frequency;
            int symbol_range_high = range_low + range_size * probabilities[i] / symbols[num_symbols - 1].frequency - 1;
            if (encoded_value < (symbol_range_high + 1.0) / PRECISION) {
                range_high = symbol_range_high;
                range_low = symbol_range_low;
                symbol_index = i;
                break;
            }
        }

        // Output the selected symbol and update the encoded value
        *output++ = symbols[symbol_index].symbol;
        encoded_value = (encoded_value - range_low / (double)PRECISION) /
                        (range_high - range_low + 1) * symbols[num_symbols - 1].frequency;
    }
}

int main() {
    char input[MAX_LEN] = "ABBBCCC";
    char output[MAX_LEN];
    double encoded_value;

    printf("Input: %s\n", input);

    encoded_value = arithmetic_encode(input);
    printf("Encoded value: %f\n", encoded_value);

    arithmetic_decode(encoded_value, output);
    printf("Decoded value: %s\n", output);

    return 0;
}