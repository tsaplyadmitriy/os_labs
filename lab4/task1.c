#include <iostream>

int main(){

int pid = fork();
if(pid!=0){

printf("hello from parent %d",pid);
}


return 0;
}