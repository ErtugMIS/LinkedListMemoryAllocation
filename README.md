I tried to implement a very simple memory management system.


start stands for starting address of the block.

size is for size of the block.

next points to next free block.


Best Fit selects the smallest free block that can satisfy the request. It aims to reduce internal fragmentation.

Worst Fit Selects the largest free block available. This helps reduce the number of very small leftover fragments.

Last but not least Next Fit starts searching from the last allocated position instead of the beginning of the list. This improves performance by reducing search time.


This file was developed as part of the Operating Systems course to demonstrate memory allocation techniques.
