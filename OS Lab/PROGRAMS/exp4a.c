#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // This header provides the declaration for close()

int main() {

    const char *filename = "new_file.txt";

    int fd = open(filename, O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    printf("File '%s' created successfully.\n", filename);

    close(fd);

    return 0;
}
