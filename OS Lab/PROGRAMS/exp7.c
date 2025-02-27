#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for exit()
int mutex = 1, full = 0, empty = 3, x = 0; // Initialize semaphores and item counter

void producer(); // Function prototype for producer
void consumer(); // Function prototype for consumer
int wait(int); // Function prototype for wait operation
int signal(int); // Function prototype for signal operation

int main() {
    int n; // Variable for user choice

    printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n"); // Print menu

    while (1) // Infinite loop for menu
    {
        printf("\nENTER YOUR CHOICE\n"); // Prompt for choice
        scanf("%d", &n); // Read user choice
        switch (n) // Switch based on choice
        {
        case 1: // Producer case
            if ((mutex == 1) && (empty != 0)) // Check if mutex is available and buffer not full
                producer(); // Call producer function
            else
                printf("BUFFER IS FULL\n"); // Buffer full message
            break;
        case 2: // Consumer case
            if ((mutex == 1) && (full != 0)) // Check if mutex is available and buffer not empty
                consumer(); // Call consumer function
            else
                printf("BUFFER IS EMPTY\n"); // Buffer empty message
            break;
        case 3: // Exit case
            exit(0); // Exit program
            break;
        }
    }

    return 0;
}

int wait(int s) // Wait function (decrement semaphore)
{
    return (--s); // Decrement and return
}

int signal(int s) // Signal function (increment semaphore)
{
    return (++s); // Increment and return
}

void producer() // Producer function
{
    mutex = wait(mutex); // Acquire mutex lock
    full = signal(full); // Increment full count
    empty = wait(empty); // Decrement empty count
    x++; // Increment item counter
    printf("\nProducer produces the item %d\n", x); // Print production message
    mutex = signal(mutex); // Release mutex lock
}

void consumer() // Consumer function
{
    mutex = wait(mutex); // Acquire mutex lock
    full = wait(full); // Decrement full count
    empty = signal(empty); // Increment empty count
    printf("\nConsumer consumes item %d\n", x); // Print consumption message
    x--; // Decrement item counter
    mutex = signal(mutex); // Release mutex lock
}

