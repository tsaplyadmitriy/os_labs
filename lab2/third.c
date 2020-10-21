#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>


void print_triangle(int height){

    int width = 2*height-1;
    int spaces = width/2;


    for(int i = 1;i<=height;i++){
        int cur_width = 2*i-1+spaces;
        for(int j = 0;j<cur_width;j++){
            if (j<spaces){
                printf(" ");
            }else{
                printf("*");
            }

        }
        printf("\n");
        spaces = spaces-1;

    }




}
int main(int argc, char *argv[]) {

    int size  = atoi(argv[1]);
    print_triangle(size);


}