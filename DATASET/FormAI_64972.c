//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

// Function to convert distance from miles to kilometers
float miles_to_kilometers(float miles){
    return miles * 1.60934;
}

// Function to convert distance from kilometers to miles
float kilometers_to_miles(float kilometers){
    return kilometers * 0.621371;
}

// Function to convert temperature from celsius to fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 1.8) + 32;
}

// Function to convert temperature from fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) / 1.8;
}

int main(){
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    
    // Creating socket file descriptor
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Binding the server to the address
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening to incoming client connections
    if(listen(server_socket, 3) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    float input, output;
    char from_unit[10], to_unit[10], buffer[1024];
    int choice;
    
    while(1){
        // Accepting incoming client connections
        int client_length = sizeof(client_address);
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_length)) < 0){
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Receiving user choice from client
        read(client_socket, &choice, sizeof(choice));
        
        // Sending choice acknowledgement to client
        int ack = 1;
        write(client_socket, &ack, sizeof(ack));
        
        // Receiving input value and units from client
        read(client_socket, &input, sizeof(input));
        read(client_socket, from_unit, sizeof(from_unit));
        read(client_socket, to_unit, sizeof(to_unit));
        
        // Performing conversion based on user choice
        switch(choice){
            // Miles to kilometers conversion
            case 1:
                output = miles_to_kilometers(input);
                break;
            // Kilometers to miles conversion
            case 2:
                output = kilometers_to_miles(input);
                break;
            // Celsius to fahrenheit conversion
            case 3:
                output = celsius_to_fahrenheit(input);
                break;
            // Fahrenheit to celsius conversion
            case 4:
                output = fahrenheit_to_celsius(input);
                break;
            // Invalid choice
            default:
                output = 0;
                break;
        }
        
        // Preparing output message to send to client
        sprintf(buffer, "%.2f %s is %.2f %s", input, from_unit, output, to_unit);
        
        // Sending output message to client
        write(client_socket, buffer, sizeof(buffer));
        
        // Closing client connection
        close(client_socket);
    }
    
    return 0;
}