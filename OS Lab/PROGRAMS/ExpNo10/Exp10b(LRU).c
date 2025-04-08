#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_REFERENCES 25

int main() {
    int page_references[MAX_REFERENCES], frames[MAX_FRAMES], last_used[MAX_FRAMES];
    int n, f, page_faults = 0, time_counter = 1;

    // Input: Number of page references
    printf("Enter the number of page references: ");
    scanf("%d", &n);

    // Input: Page reference sequence
    printf("Enter the page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page_references[i]);
    }

    // Input: Number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames and last_used counters
    for (int i = 0; i < f; i++) {
        frames[i] = -1;       // -1 indicates empty frame
        last_used[i] = 0;     // Initialize usage timestamps
    }

    printf("\nLRU Page Replacement Algorithm\n");
    printf("Page\tFrames\t\tPage Fault\n");

    for (int i = 0; i < n; i++) {
        int current_page = page_references[i];
        int page_found = 0;

        // Check if page is already in a frame
        for (int j = 0; j < f; j++) {
            if (frames[j] == current_page) {
                page_found = 1;
                last_used[j] = time_counter++;
                break;
            }
        }

        // Page fault handling
        if (!page_found) {
            int lru_index = 0;
            
            // Find the least recently used frame
            for (int j = 1; j < f; j++) {
                if (last_used[j] < last_used[lru_index]) {
                    lru_index = j;
                }
            }

            // Replace the LRU page
            frames[lru_index] = current_page;
            last_used[lru_index] = time_counter++;
            page_faults++;
        }

        // Display current state
        printf("%d\t", current_page);
        for (int j = 0; j < f; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[j]);
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
