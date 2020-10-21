#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){


//Frames = 10, hit/miss rate = 0.007056
//Frames = 50, hit/miss rate =  0.051579
//Frames   = 100, hit/miss rate = 0.101433

    int miss_rate = 0;
    int hit_rate = 0;
    int size = 0;

    printf("Enter number of page frames: \n");
    scanf("%d",&size);
    

    FILE *file;
    file = fopen("lab09.txt", "r");


    int *frames = (int*)calloc(size, sizeof(int));
    memset(frames, 0, size);

    int *ages = (int*)calloc(size, sizeof(int));
    memset(ages, 0, size);

    int cur;
    printf("%d",fscanf(file, "%d", &cur));
    while (fscanf(file, "%d", &cur) != EOF) {
       
        int num_of_frame = -1;

        for (int i = 0; i < size; i++) {
            if (cur == frames[i]) {
                num_of_frame = i;
                break;
            }
        }

        if(num_of_frame != -1){

            hit_rate++;
            ages[num_of_frame] >>= 1; //shift age counter bits to the right
            ages[num_of_frame] |= 1<<7;//add 1 to the left of the counter

        }else{
            miss_rate++;

            int min = 0;

            for (int i = 0; i < size; i++){
                if (ages[i] < ages[min]){
                    min = i;
                 }
            }

            frames[min] = cur;
            ages[min] = 0;
            ages[min]  |= 1<<7;//add 1 to the left of the counter

        }



    }
    printf("Hit rate: %d\nMiss rate :%d\n", hit_rate, miss_rate);
    if(miss_rate!=0){
    
    printf("Hits/Misses ratio: %lf\n", (double)hit_rate/(double)miss_rate);
	}

    fclose(file);
    return 0;


    }
