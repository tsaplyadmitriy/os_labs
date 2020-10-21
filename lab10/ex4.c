#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>



int main() {
   
   //open directory tmp
    DIR *dirp = opendir("tmp");
   
    if(dirp == NULL){
        return 1;
        
    }

    char directory[512];
   
    struct dirent *dp; //dirend  - struct of readdir 
    struct stat fstat; 
    
    strcpy(directory, "tmp/");

    while((dp = readdir(dirp)) != NULL) {
       
        stat(directory, &fstat);
        strcat(directory, dp -> d_name);

        if((fstat.st_nlink >= 2) & (strcmp(dp->d_name,".")!=0)&(strcmp(dp->d_name,"..")!=0)) {
          
            printf("Link is: %s Files are:\n", dp -> d_name);
            
            struct dirent *link;
            
            DIR *dirp2 = opendir("tmp");

            while((link = readdir(dirp2)) != NULL){
               
                if((dp -> d_ino == link -> d_ino ) & 
                    (strcmp(link -> d_name, dp -> d_name) != 0)){ //check if current file points to the file with two or more hard links
                    
                    
                    printf("%s ", link -> d_name);
                      printf("\n");
                    
                }
              
                
            }
              printf("\n");
        } else 
            
            if((strcmp(dp->d_name,".")!=0)&(strcmp(dp->d_name,"..")!=0))
                printf("File %s doesn't have any links\n", dp -> d_name);

        strcpy(directory, "tmp/");
    }

    return 0;
}
