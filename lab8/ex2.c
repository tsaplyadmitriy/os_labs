#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

int main() {
    
    //Task 2: I can derive from vmstat only that free memory amount is decreasing, si and so is 0 always
    
    //Task 3 VIRT and RES memory usage increases, %MEM increases also, which seems logical
    
    
	int n = 120;
	int mult = 10 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int * ptr = (int*)malloc(mult);
        memset(ptr, 0, mult);
        sleep(1);
    }

    return 0;
}
