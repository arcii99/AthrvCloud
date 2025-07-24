//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MAX_FILES 100
#define PORT_NUM 9000
#define IP_ADDRESS "127.0.0.1"

typedef struct {
    char filename[BUFFER_SIZE];
    int filesize;
} file_info;

int get_file_size(char *filename);
int count_files(char *dir_path);
int is_file(char *path);
void send_file_info(int client_socket, file_info *file_list, int num_files);
int receive_file_info(int server_socket, file_info *file_list);
void send_file(int client_socket, char *filename);
void receive_file(int server_socket, char *filename);

int main() {
    int client_socket, server_socket, num_files;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    file_info server_files[MAX_FILES], client_files[MAX_FILES];
    char server_dir[BUFFER_SIZE], client_dir[BUFFER_SIZE], buffer[BUFFER_SIZE];

    // Set up client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stderr, "Error creating socket\n");
        return -1;
    }

    // Set up server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Error creating socket\n");
        return -1;
    }

    // Set up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUM);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        return -1;
    }

    // Listen for client connections
    if (listen(server_socket, 1) < 0) {
        fprintf(stderr, "Error listening for connections\n");
        return -1;
    }

    // Accept client connection
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);
    if (client_socket < 0) {
        fprintf(stderr, "Error accepting connection\n");
        return -1;
    }

    // Receive client directory
    memset(&buffer, 0, sizeof(buffer));
    if (read(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error receiving client directory\n");
        return -1;
    }
    strncpy(client_dir, buffer, BUFFER_SIZE);

    // Send server directory
    memset(&buffer, 0, sizeof(buffer));
    if (getcwd(server_dir, BUFFER_SIZE) == NULL) {
        fprintf(stderr, "Error getting server directory\n");
        return -1;
    }
    strncpy(buffer, server_dir, BUFFER_SIZE);
    if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error sending server directory\n");
        return -1;
    }

    // Get list of files in server directory
    num_files = count_files(server_dir);
    if (num_files < 0) {
        fprintf(stderr, "Error counting files in server directory\n");
        return -1;
    }
    if (num_files > MAX_FILES) {
        fprintf(stderr, "Too many files in server directory\n");
        return -1;
    }
    DIR *dir = opendir(server_dir);
    if (dir == NULL) {
        fprintf(stderr, "Error opening server directory\n");
        return -1;
    }
    struct dirent *file;
    int i = 0;
    while ((file = readdir(dir)) != NULL) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", server_dir, file->d_name);
        if (is_file(filepath)) {
            strncpy(server_files[i].filename, file->d_name, BUFFER_SIZE);
            server_files[i].filesize = get_file_size(filepath);
            i++;
        }
    }
    closedir(dir);

    // Send file info to client
    send_file_info(client_socket, server_files, num_files);

    // Receive file info from client
    num_files = receive_file_info(client_socket, client_files);

    // Remove local files that are not on the client
    for (i = 0; i < num_files; i++) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", server_dir, client_files[i].filename);
        if (access(filepath, F_OK) == 0) {
            continue;
        }
        if (remove(filepath) < 0) {
            fprintf(stderr, "Error deleting file: %s\n", client_files[i].filename);
        }
    }

    // Send files that are not on the client
    for (i = 0; i < num_files; i++) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", server_dir, server_files[i].filename);
        if (access(filepath, F_OK) == -1) {
            send_file(client_socket, server_files[i].filename);
        }
    }

    // Receive files that are not on the server
    for (i = 0; i < num_files; i++) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", server_dir, client_files[i].filename);
        if (access(filepath, F_OK) == -1) {
            receive_file(client_socket, client_files[i].filename);
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

int get_file_size(char *filename) {
    struct stat file_info;
    if (stat(filename, &file_info) < 0) {
        return -1;
    }
    return file_info.st_size;
}

int count_files(char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        return -1;
    }
    struct dirent *file;
    int count = 0;
    while ((file = readdir(dir)) != NULL) {
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, file->d_name);
        if (is_file(filepath)) {
            count++;
        }
    }
    closedir(dir);
    return count;
}

int is_file(char *path) {
    struct stat file_info;
    if (stat(path, &file_info) < 0) {
        return 0;
    }
    return S_ISREG(file_info.st_mode);
}

void send_file_info(int client_socket, file_info *file_list, int num_files) {
    int i, size;
    char buffer[BUFFER_SIZE];

    // Send number of files
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "%d", num_files);
    if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error sending number of files\n");
        exit(-1);
    }

    // Send file info
    for (i = 0; i < num_files; i++) {
        memset(&buffer, 0, sizeof(buffer));
        snprintf(buffer, sizeof(buffer), "%s,%d", file_list[i].filename, file_list[i].filesize);
        if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
            fprintf(stderr, "Error sending file info\n");
            exit(-1);
        }
    }
}

int receive_file_info(int server_socket, file_info *file_list) {
    int i, size, num_files;
    char buffer[BUFFER_SIZE];

    // Receive number of files
    memset(&buffer, 0, sizeof(buffer));
    if (read(server_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error receiving number of files\n");
        exit(-1);
    }
    num_files = atoi(buffer);

    // Receive file info
    for (i = 0; i < num_files; i++) {
        memset(&buffer, 0, sizeof(buffer));
        if (read(server_socket, buffer, BUFFER_SIZE) < 0) {
            fprintf(stderr, "Error receiving file info\n");
            exit(-1);
        }
        char *filename = strtok(buffer, ",");
        char *filesize_str = strtok(NULL, ",");
        int filesize = atoi(filesize_str);
        strncpy(file_list[i].filename, filename, BUFFER_SIZE);
        file_list[i].filesize = filesize;
    }

    return num_files;
}

void send_file(int client_socket, char *filename) {
    int filesize, bytes_sent, bytes_read, fd;
    char buffer[BUFFER_SIZE];

    // Send start signal
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "start,%s", filename);
    if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error sending start signal\n");
        exit(-1);
    }

    // Open file and get size
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }
    filesize = get_file_size(filename);

    // Send file size
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "%d", filesize);
    if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error sending file size\n");
        exit(-1);
    }

    // Send file data
    bytes_sent = 0;
    while (bytes_sent < filesize) {
        memset(&buffer, 0, sizeof(buffer));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading file: %s\n", filename);
            exit(-1);
        }
        if (write(client_socket, buffer, bytes_read) < 0) {
            fprintf(stderr, "Error sending file data\n");
            exit(-1);
        }
        bytes_sent += bytes_read;
    }

    // Send end signal
    memset(&buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "end,%s", filename);
    if (write(client_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error sending end signal\n");
        exit(-1);
    }

    // Close file
    close(fd);
}

void receive_file(int server_socket, char *filename) {
    int filesize, bytes_received, fd;
    char buffer[BUFFER_SIZE], filepath[BUFFER_SIZE];

    // Receive start signal
    memset(&buffer, 0, sizeof(buffer));
    if (read(server_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error receiving start signal\n");
        exit(-1);
    }
    char *start_str = strtok(buffer, ",");
    char *start_filename = strtok(NULL, ",");
    if (strcmp(start_str, "start") != 0 || strcmp(start_filename, filename) != 0) {
        fprintf(stderr, "Error receiving start signal: %s\n", buffer);
        exit(-1);
    }

    // Receive file size
    memset(&buffer, 0, sizeof(buffer));
    if (read(server_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error receiving file size\n");
        exit(-1);
    }
    filesize = atoi(buffer);

    // Open file for writing
    snprintf(filepath, sizeof(filepath), "./%s", filename);
    fd = open(filepath, O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        fprintf(stderr, "Error opening file for writing: %s\n", filepath);
        return;
    }

    // Receive file data
    bytes_received = 0;
    while (bytes_received < filesize) {
        memset(&buffer, 0, sizeof(buffer));
        int bytes_left = filesize - bytes_received;
        int bytes_to_read = bytes_left > BUFFER_SIZE ? BUFFER_SIZE : bytes_left;
        if (read(server_socket, buffer, bytes_to_read) < 0) {
            fprintf(stderr, "Error receiving file data\n");
            exit(-1);
        }
        if (write(fd, buffer, bytes_to_read) < 0) {
            fprintf(stderr, "Error writing file\n");
            exit(-1);
        }
        bytes_received += bytes_to_read;
    }

    // Receive end signal
    memset(&buffer, 0, sizeof(buffer));
    if (read(server_socket, buffer, BUFFER_SIZE) < 0) {
        fprintf(stderr, "Error receiving end signal\n");
        exit(-1);
    }
    char *end_str = strtok(buffer, ",");
    char *end_filename = strtok(NULL, ",");
    if (strcmp(end_str, "end") != 0 || strcmp(end_filename, filename) != 0) {
        fprintf(stderr, "Error receiving end signal\n");
        exit(-1);
    }

    // Close file
    close(fd);
}