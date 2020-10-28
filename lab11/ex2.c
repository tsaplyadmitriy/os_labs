
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	
    setvbuf(stdout, NULL, _IOLBF, 5);
    
	char hello[] = {'H','e','l','l','o'};
   
    for(int i = 0;i<5;i++){
        printf("%c", hello[i]);
	sleep(1);
    }

	return 0;
}
