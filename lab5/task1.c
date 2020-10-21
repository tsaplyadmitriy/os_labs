#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



//Program with strict order

static int count = 0;



void * show(void *param){

    
    
 printf("thread %d is created\n",count);  
    
    
    printf("%d thread is active\n",count);
   
    
    
   
 printf("thread %d is exited\n",count);   
    
   
     count++; 
pthread_exit(NULL);
 
  

}


int main(){

    pthread_t tid;
    int N = 0;

    printf("Input number of threads:");
    scanf("%d",&N);
for(int i = 0;i<N;++i){
    
    

pthread_create(&tid, NULL,&show,NULL);
pthread_join(tid,NULL);
 

}


pthread_exit(NULL);



}


