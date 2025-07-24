//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    char buffer[BUFFER_SIZE]; // buffer for reading/writing files
    int input_fd, output_fd; // file descriptors for input and output files
    ssize_t ret_in, ret_out; // return values for read/write functions
    int opt; // option for command-line arguments
    mode_t file_permissions; // file permissions for output file
    char *input_file = NULL, *output_file = NULL; // input and output file names
    
    // parse command-line arguments
    while ((opt = getopt(argc, argv, "i:o:p:")) != -1)
    {
        switch(opt)
        {
            case 'i':
                input_file = optarg;
                break;
            case 'o':
                output_file = optarg;
                break;
            case 'p':
                file_permissions = strtol(optarg, NULL, 8);
                break;
            default:
                fprintf(stderr, "Usage: %s -i input_file -o output_file -p file_permissions\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    
    // check if input_file and output_file exist
    if (access(input_file, F_OK) == -1)
    {
        fprintf(stderr, "Error: input file %s does not exist.\n", input_file);
        exit(EXIT_FAILURE);
    }
    
    if (access(output_file, F_OK) != -1)
    {
        fprintf(stderr, "Error: output file %s already exists.\n", output_file);
        exit(EXIT_FAILURE);
    }
    
    // open input file for reading
    input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1)
    {
        fprintf(stderr, "Error: failed to open input file %s (%s)\n", input_file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // open output file for writing
    output_fd = open(output_file, O_WRONLY | O_CREAT, file_permissions);
    if (output_fd == -1)
    {
        fprintf(stderr, "Error: failed to open output file %s (%s)\n", output_file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // read from input file and write to output file
    while ((ret_in = read(input_fd, &buffer, BUFFER_SIZE)) > 0)
    {
        ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
        if (ret_out != ret_in)
        {
            fprintf(stderr, "Error: failed to write to output file %s (%s)\n", output_file, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // handle errors that may have occurred during read/write
    if (ret_in == -1)
    {
        fprintf(stderr, "Error: failed to read from input file %s (%s)\n", input_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // close input and output files
    if (close(input_fd) == -1)
    {
        fprintf(stderr, "Error: failed to close input file %s (%s)\n", input_file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (close(output_fd) == -1)
    {
        fprintf(stderr, "Error: failed to close output file %s (%s)\n", output_file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("File copy successful.\n");
    
    return 0;
}