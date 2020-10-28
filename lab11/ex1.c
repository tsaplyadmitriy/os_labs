#include <stdio.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <stdlib.h>

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


int main(){

	char nice_day[] = "This is a nice day";  //creating char array to write to file through mmap

	int FILE = open("ex1.txt", O_RDWR); //open the file
     
	ftruncate(FILE, strlen(nice_day)); //set the length of the file to size of nice_day[]
	
    
    struct stat s; //struct in which size of the file will be set via stat()
	stat("ex1.txt", &s); //setting stat structure with data corresponding to "ex1.txt"
    
	char *adress = (char*)mmap(NULL, s.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, FILE, 0);  //create memory mapping 
	
    memcpy(adress, nice_day, strlen(nice_day)); //write string to the file
	
    munmap(adress, s.st_size); //romove memory mapping
	
    close(FILE); //close the file

	return 0;	
}
