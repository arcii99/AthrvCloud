//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the input file for reading
    FILE *infile = fopen("input.dat", "r");
    if (infile == NULL) {
        perror("Error opening input.dat");
        exit(1);
    }

    // Open the output file for writing
    FILE *outfile = fopen("output.dat", "w");
    if (outfile == NULL) {
        perror("Error opening output.dat");
        exit(1);
    }

    // Read the data from the input file, compute the median, and write the result to the output file
    int data[100]; // Assume at most 100 data points
    int count = 0; // Keep track of how many data points we have read so far
    while (fscanf(infile, "%d", &data[count]) == 1) { // fscanf returns the number of items scanned
        count++;
    }

    // Compute the median
    int median;
    if (count % 2 == 0) { // If there are an even number of data points
        int x = count / 2;
        int y = x - 1;
        median = (data[x] + data[y]) / 2;
    } else { // If there are an odd number of data points
        int x = count / 2;
        median = data[x];
    }

    // Write the result to the output file
    fprintf(outfile, "The median is %d", median);

    // Close the input and output files
    fclose(infile);
    fclose(outfile);

    return 0;
}