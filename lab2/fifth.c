#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>


void print_ladder(int height) {
    int width = 2 * height - 1;


    for (int i = 1; i <= height; i++) {
        int cur_width = 2 * i - 1;
        for (int j = 0; j < cur_width; j++) {

            printf("*");


        }
        printf("\n");


    }
}



void print_mountain(int height) {
    int width = 2 * height - 1;
    int len = 1;
    int mid  = width/2;

    for (int i = 1; i <= height; i++) {

        for (int j = 0; j < len; j++) {

            printf("*");


        }
        if(i<=mid){
           len++;
        }else{
            len--;
        }

        printf("\n");


    }
}


void print_square(int height) {
    int width = 2 * height - 1;


    for (int i = 1; i <= height; i++) {

        for (int j = 0; j < width; j++) {

            printf("*");


        }
        printf("\n");


    }
}

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
    printf("\n");
    print_ladder(size);
    printf("\n");
    print_square(size);
    printf("\n");
    print_mountain(size);
}