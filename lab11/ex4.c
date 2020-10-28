#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

#include <fcntl.h>

#include <stdlib.h>

#include <string.h>
#include <sys/stat.h>
#include <stdio.h>


int main(){

    int source;
    int destination;
    
    size_t size;
    char *src, *dest;

    source = open("ex1.txt", O_RDONLY); //open source file
     size = lseek(source, 0, SEEK_END); 
     
     //sets shift of r/w position and returns difference between initial r/w position and shidted.
     //We shift 0 bits from end, so it is equal to file lenght
    
    src = (char*)mmap(NULL, size, PROT_READ, MAP_PRIVATE, source, 0);//memory map to source file
  
    destination = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666); //66  - giving rw permissions
   
    ftruncate(destination, size); //change size of file to the size of source
   
    dest =(char*) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, destination, 0);  //memory map the destination file
   
    memcpy(dest, src, size);  //copy data from source to destination

    return 0;
}
