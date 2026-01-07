#include <stdio.h>
#include <stdlib.h>

#define TOTAL_BLOCKS 32 // Keep it small for display purposes

// We need (TOTAL_BLOCKS / 8) bytes to store the bits
// 32 blocks = 4 bytes (chars)
unsigned char bitmap[TOTAL_BLOCKS / 8]; 

// Helper to print binary representation
void printBinary(unsigned char n) {
    for (int i = 0; i < 8; i++) {
        printf("%d", (n >> i) & 1); // Print bits from LSB to MSB
    }
}

// 1. Initialize Bitmap (All 0 = All Free)
void initBitmap() {
    for (int i = 0; i < TOTAL_BLOCKS / 8; i++) {
        bitmap[i] = 0; 
    }
}

// 2. Allocate a Block (Set bit to 1)
void allocateBlock(int blockIndex) {
    int byteIndex = blockIndex / 8;
    int bitIndex = blockIndex % 8;

    // Use OR (|) to set the specific bit to 1
    bitmap[byteIndex] |= (1 << bitIndex);
    printf("Allocated Block %d.\n", blockIndex);
}

// 3. Free a Block (Set bit to 0)
void freeBlock(int blockIndex) {
    int byteIndex = blockIndex / 8;
    int bitIndex = blockIndex % 8;

    // Use AND (&) with NOT (~) to clear the specific bit
    bitmap[byteIndex] &= ~(1 << bitIndex);
    printf("Freed Block %d.\n", blockIndex);
}

// 4. Check if Block is Free
int isBlockFree(int blockIndex) {
    int byteIndex = blockIndex / 8;
    int bitIndex = blockIndex % 8;

    // Check if the bit is 0
    if ((bitmap[byteIndex] & (1 << bitIndex)) == 0) {
        return 1; // True, it is free
    }
    return 0; // False, it is occupied
}

// 5. Display the Bitmap
void displayBitmap() {
    printf("Current Bitmap Status (0=Free, 1=Used):\n");
    for (int i = 0; i < TOTAL_BLOCKS / 8; i++) {
        printf("Byte %d: ", i);
        printBinary(bitmap[i]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("--- Bitmap Allocation Demo ---\n");
    initBitmap();
    
    // Allocate some arbitrary blocks
    allocateBlock(0);
    allocateBlock(2);
    allocateBlock(9); // This is in the second byte (index 1)

    displayBitmap();

    // Check status
    printf("Is Block 2 free? %s\n", isBlockFree(2) ? "Yes" : "No");
    printf("Is Block 3 free? %s\n", isBlockFree(3) ? "Yes" : "No");

    // Free a block
    freeBlock(2);
    displayBitmap();

    return 0;
}