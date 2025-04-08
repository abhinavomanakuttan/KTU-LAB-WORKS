#include <stdio.h>
#define MAX_FRAMES 20
#define MAX_REFERENCES 50

int main() {
    int page_references[MAX_REFERENCES], frames[MAX_FRAMES], frequency[MAX_FRAMES];
    int num_references, num_frames, page_faults = 0;

    // Input: Number of page references
    printf("Enter number of page references: ");
    scanf("%d", &num_references);

    // Input: Page reference sequence
    printf("Enter the page references: ");
    for (int i = 0; i < num_references; i++) {
        scanf("%d", &page_references[i]);
    }

    // Input: Number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Initialize frames and frequency counters
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;       // -1 indicates empty frame
        frequency[i] = 0;     // Initialize usage frequency
    }

    printf("\nLFU Page Replacement Algorithm\n");
    printf("Page\tFrames\t\tPage Fault\n");

    for (int i = 0; i < num_references; i++) {
        int current_page = page_references[i];
        int page_found = 0;

        // Check if page is already in a frame
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == current_page) {
                page_found = 1;
                frequency[j]++;  // Increment usage count
                break;
            }
        }

        // Page fault handling
        if (!page_found) {
            // Check for empty frame first
            int empty_frame = -1;
            for (int j = 0; j < num_frames; j++) {
                if (frames[j] == -1) {
                    empty_frame = j;
                    break;
                }
            }

            if (empty_frame != -1) {
                // Use empty frame
                frames[empty_frame] = current_page;
                frequency[empty_frame] = 1;
            } else {
                // Find LFU page
                int lfu_index = 0;
                for (int j = 1; j < num_frames; j++) {
                    if (frequency[j] < frequency[lfu_index]) {
                        lfu_index = j;
                    }
                }

                // Replace LFU page
                frames[lfu_index] = current_page;
                frequency[lfu_index] = 1;
            }
            page_faults++;
        }

        // Display current state
        printf("%d\t", current_page);
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            } else {
                printf("%d(%d)\t", frames[j], frequency[j]);
            }
        }

        if (!page_found) {
            printf("PF %d", page_faults);
        }
        printf("\n");
    }

    printf("\nTotal number of page faults: %d\n", page_faults);
    return 0;
}
