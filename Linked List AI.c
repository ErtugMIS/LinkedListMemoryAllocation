#include <stdio.h>
#include <string.h>

#define TOTAL_BLOCKS 100
#define BLOCK_SIZE 16 // Small size for demonstration

// 1. Define the structure of a Disk Block
typedef struct {
    char data[BLOCK_SIZE];
    int nextBlockIndex; // Points to the next block (-1 if end of file)
} DiskBlock;

// The Disk is just an array of blocks
DiskBlock disk[TOTAL_BLOCKS];

// 2. Function to Initialize the Disk
void initDisk() {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        disk[i].nextBlockIndex = -1; // -1 indicates NULL/Empty
        strcpy(disk[i].data, "");
    }
}

// 3. Function to Create a File (Simulating non-contiguous allocation)
// Returns the index of the starting block
int createFile(int startBlock, int length, int step) {
    int current = startBlock;
    
    for (int i = 0; i < length; i++) {
        // Simple data generation
        sprintf(disk[current].data, "Data_%d", i+1);
        
        // If it's the last block, set next to -1
        if (i == length - 1) {
            disk[current].nextBlockIndex = -1;
        } else {
            // Link to a non-consecutive block (simulating scattered storage)
            int next = (current + step) % TOTAL_BLOCKS;
            disk[current].nextBlockIndex = next;
            current = next;
        }
    }
    return startBlock; // Return the file's head pointer
}

// 4. Function to Read the File (Traversing the chain)
void readFile(int startBlock) {
    printf("Reading File starting at Block %d:\n", startBlock);
    
    int current = startBlock;
    int count = 1;

    while (current != -1) {
        printf(" -> Step %d: Reading Block %d | Data: %s\n", 
               count++, current, disk[current].data);
        
        // Move to the next block using the stored index
        current = disk[current].nextBlockIndex;
    }
    printf(" -> End of File.\n\n");
}

int main() {
    initDisk();

    // Create a file starting at block 10, length 3, jumping 20 blocks each time
    printf("--- Linked List Allocation Demo ---\n");
    int fileHead = createFile(10, 3, 20);

    // The chain will be: 10 -> 30 -> 50 -> -1
    readFile(fileHead);

    return 0;
}