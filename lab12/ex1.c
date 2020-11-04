
#include <stdio.h>
#include <sys/mman.h>
#include <cstdlib>
#include <fcntl.h>
#include <stdlib.h>

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>




int main(){


int randomData = open("/dev/random", O_RDONLY);


    char myRandomData[20];
    size_t randomDataLen = 0;
    while (randomDataLen < sizeof myRandomData)
    {
        ssize_t result = read(randomData, myRandomData + randomDataLen, (sizeof myRandomData) - randomDataLen);
        
        randomDataLen += result;
    }
    close(randomData);
    
    for(int i = 0;i<20;i++){
        
        int ch = myRandomData[i];
        if(ch<0){
            ch = ch*-1;
        }
        printf("%c",ch);
    }



return 0;

}
