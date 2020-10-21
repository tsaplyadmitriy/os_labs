#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


void chackAmp(int len, char*buff){
		if(buff[len-1]=='&'){
			
			buff[len-1]='\0';
			
			int i = fork();
			if(i!=0){
				return 0;
			}
			
			
		}
		system(buffer);
	
}

int main(){
	
	char buff[3000];
	
	while(strcmp( "out\n",buff)){
		fgets(buff,sizeof(buff),stdin));
		
		int len = strlen(buff);
		
		checkAmp(len,buff);//checks if we need to run process in background
		
		
		
	}
	
	
	return 0;
}
