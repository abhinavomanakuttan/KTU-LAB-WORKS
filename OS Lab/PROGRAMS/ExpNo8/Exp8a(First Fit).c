#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], block[MAX], file[MAX], i, j, nb, nf, temp;
    static int block_flag[MAX], file_alloc[MAX];

    printf("\nMemory Management Scheme - First Fit");

    // Input number of memory blocks and files
    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input block sizes
    printf("\nEnter the size of each block:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &block[i]);
    }

    // Input file sizes
    printf("\nEnter the size of each file:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &file[i]);
    }

    // First Fit Allocation Logic
    for(i = 1; i <= nf; i++) {
        file_alloc[i] = -1; // Initialize as not allocated
        for(j = 1; j <= nb; j++) {
            if(block_flag[j] == 0 && block[j] >= file[i]) {
                file_alloc[i] = j; // Allocate block j to file i
                frag[i] = block[j] - file[i]; // Internal fragmentation
                block_flag[j] = 1; // Mark block as used
                break;
            }
        }
    }

    // Output allocation result
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if(file_alloc[i] != -1) {
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, file[i], file_alloc[i], block[file_alloc[i]], frag[i]);
        } else {
            printf("%d\t%d\t\tNot Allocated\n", i, file[i]);
        }
    }

    return 0;
}
