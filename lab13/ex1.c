
#include <stdio.h>
#include <sys/mman.h>
#include <cstdlib>
#include <fcntl.h>
#include <stdlib.h>

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>







int main(){
    
    
     
    
    int res  = 3;
    int proc = 5;
    
//     printf("Enter number of resource types:\n");
//     scanf("%d",&res);
//     
//     printf("Enter number of processes:\n");
//     scanf("%d",&proc);
    
   
    int avail[res];
    int total[res];
    int finish[proc];
    int alloc[proc][res];
    int request[proc][res];;
    
   
    
    FILE *fptr;
    if ((fptr = fopen("input_ok.txt", "r")) == NULL) {
        printf("Error! opening file");
        
        exit(1);
    }
    
    
    for(int i = 0;i<res;i++){
        
        int c = fgetc(fptr);
        
        if((c != ' ') && (c!= '\n')){
            total[i] = c - '0';
        
        
        }else{
            i--;
        }
        
    }
    
   
   
    for(int i = 0;i<res;i++){
       
        
        int c = fgetc(fptr);
        
        if(c != ' ' && c!= '\n'){
            avail[i] = c - '0';
        
            
        }else{
            i--;
        }
        
    }
    
   
     for(int j = 0;j<proc;j++){
   
        for(int i = 0;i<res;i++){
        
        int c = fgetc(fptr);
       
        if(c != ' ' && c!='\n'){
           alloc[j][i] = c - '0';
        
            
        }else{
            i--;
        }
        
    }
    
 }
    
     for(int j = 0;j<proc;j++){
   
        for(int i = 0;i<res;i++){
        
        int c = fgetc(fptr);
       
        if(c != ' ' && c!='\n'){
           request[j][i] = c - '0';
        
            
        }else{
            i--;
        }
        
    }
     
    
 }
 
 
 for(int i = 0;i<proc;i++){
     finish[i] = 0;
 }
 
 for(int i = 0;i<proc;i++){
     
     int count = 0;
     for(int j = 0;j<res;j++){
         if(request[i][j]!=0){
             count ++;
        }
         
    }
    if(count == 0){
        finish[i] = 1;
    } 
          
 }
 
  int count = 0;
    int process ;
    for(int i = 0;i<proc;i++){
        
        int c = 0;
        for(int j = 0;j<res;j++){
            
            if(request[i][j] > avail[j]){
                c++;
            }
            if(c==0 && finish[i] == 0){
                count ++;
                process =  i;
            }
            
        }
        
        
        
        
    }
   if(count ==0){
      
       process = -1;
   } 

 
 while(process != -1){
     
     
     finish[process] = 1;
     for(int i = 0;i< res;i++){
         avail[i] = avail[i]+alloc[process][i];
         
     }
     
     
        count = 0;
    
    for(int i = 0;i<proc;i++){
        
        int c = 0;
        for(int j = 0;j<res;j++){
            
            if(request[i][j] > avail[j]){
                c++;
            }
            if(c==0 && finish[i] == 0){
                count ++;
                process =  i;
            }
            
        }
        
        
        
        
    }
   if(count ==0){
      
       process = -1;
   } 
   
    
     
    
 }
    
    
        int dcount = 0;
    for(int i = 0;i<proc;i++){
        if(finish[i]==0){
            dcount++;
            printf("Deadlock on %d process\n",i);
        }
        
    }
    if(dcount==0){
        printf("No deadlocks\n");
    }
    
    
     fclose(fptr);
     
     
     
    return 0;
}
