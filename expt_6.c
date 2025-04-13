/* 
==================
Experiment 6: Paging Technique Simulation
Translates a logical address into a physical address using a simple page table.
Input: Number of pages, page size, page table entries, and a logical address.
Output: The physical address.
==================
*/

#include <stdio.h>

int main() {
    int numPages, pageSize;
    printf("Enter number of pages in logical memory: ");
    scanf("%d", &numPages);
    printf("Enter page size: ");
    scanf("%d", &pageSize);
    
    int pageTable[numPages];
    printf("Enter the frame number for each page (page table entries):\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }
    
    int logicalAddress;
    printf("Enter a logical address: ");
    scanf("%d", &logicalAddress);
    
    int pageNumber = logicalAddress / pageSize;
    int offset = logicalAddress % pageSize;
    
    if (pageNumber >= numPages) {
        printf("Invalid logical address.\n");
        return 1;
    }
    
    int physicalAddress = pageTable[pageNumber] * pageSize + offset;
    printf("Logical Address %d translates to Physical Address %d\n", logicalAddress, physicalAddress);
    
    return 0;
}
