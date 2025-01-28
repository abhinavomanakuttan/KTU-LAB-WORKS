 #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "my_file.txt";
    int fd;

    // Open file for writing
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating/opening file");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
    const char *data = "Hello, world!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Wrote %ld bytes to the file.\n", bytes_written);

    // Close the file
    close(fd);

    // Reopen the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the file
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1); // leave space for null terminator
    if (bytes_read == -1) {
        perror("Error reading from the file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer
    buffer[bytes_read] = '\0';

    printf("Read %ld bytes from the file: %s\n", bytes_read, buffer);

    // Close the file again
    close(fd);

    return 0;
}

