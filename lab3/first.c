#include <stdio.h>

void swap(int *array, int a, int b){
    int temp = array[b];
    array[b] = array[a];
    array[a] = temp;


}

void bubble_sort(int *array,int size){
   

    for(int i = 0;  i < size-1; i++){
       
     for (int j = 0; j < size-i-1; j++) {
           if (array[j] > array[j+1]) 
              swap(array,j, j+1); 
              }

    }
    
    for(int i = 0;  i < size; i++){
        printf("%d ",array[i]);
    }

}

int main(){

    int array_size;
    printf("Enter an array ");
    scanf("%d",&array_size);
    int array[array_size];
    for(int i = 0;i<array_size;i++){
        scanf("%d",&array[i]);
    }
    bubble_sort(array,array_size);
    return 0;
}
