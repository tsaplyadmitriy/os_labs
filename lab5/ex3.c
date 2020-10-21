#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define TRUE 1

pthread_mutex_t lock;
pthread_cond_t c_consumer;
pthread_cond_t c_producer;
int shared_data = 0;

void * producer(void* arg){
    int iteration = 0;
    
    while(TRUE){
        
        pthread_mutex_lock(&lock);

  		while(shared_data != 0) {
  			pthread_cond_wait(&c_producer, &lock);
            
            
        }

  		shared_data = iteration;
        
        
  		pthread_cond_signal(&c_consumer);
        
  		pthread_mutex_unlock(&lock);
  		
        
        iteration++;
        
        
        
        
    }
    pthread_exit(0);
    
    
    
    
}


void * consumer(void* arg){
     int iteration = 0;
    
    while(TRUE){
        
        pthread_mutex_lock(&lock);

  		while(shared_data == 0) {
  			pthread_cond_wait(&c_producer, &lock);
            
            
        }

  		shared_data = 0;
        
        
  		pthread_cond_signal(&c_consumer);
        
  		pthread_mutex_unlock(&lock);
  		
        
        iteration++;
        
        
        
        
    }
    pthread_exit(0);
    
    
    
    
    
    
}





int main(){
    pthread_t producer;
    pthread_t consumer;
    
    pthread_mutex_init(&lock, 0); 
	pthread_cond_init(&c_consumer, 0); 
	pthread_cond_init(&c_producer, 0); 
	
	pthread_create(&consumer, 0, consumer, 0);
	pthread_create(&producer, 0, producer, 0); 

	pthread_join(producer, 0);
	pthread_join(consumer, 0); 

	pthread_cond_destroy(&c_consumer);
	pthread_cond_destroy(&c_producer);
	
	pthread_mutex_destroy(&lock);
    
    
    
}
