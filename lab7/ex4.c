#include <stdlib.h>
#include <stdio.h>
#include <cstring>




void * reallocate(void *ptr, int size){
    
    
    if (ptr == NULL)
		return malloc(size);

	if (size == 0){
		free(ptr);
		return NULL;
	}

      
            
    void* ptr_temp = ptr;
    
	ptr = malloc(size * sizeof(void*));
	memcpy(ptr, ptr_temp, size);
    
    return ptr;
            
            
        
        
    }
        



int main(){
    int n = 4;
	int* ptr = (int*)calloc(n, sizeof(int));

	printf("Initial: ");
	for (int i = 0; i < n; i++)
	{
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}

	reallocate(ptr, 7);
	printf("Reallocation: ");
	for (int i = 0; i < 7; i++)
		printf("%d ", ptr[i]);
    
    
    
    
    return 0;
}
