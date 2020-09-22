#include <stdio.h>





struct process{
    int number;
    int arrival;
    int burst;
    int compl_time;
    int ta_time;
    int w_time;

};

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(struct process arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j].arrival > arr[j+1].arrival)
                swap(&arr[j], &arr[j+1]);
}


void printArray(struct process arr[], int size)
{
    int i;
    for (i=0; i < size; i++){

        printf("Process number: %d, Arrival: %d, Burst: %d, CT: %d, TAT: %d, WT: %d \n",
                arr[i].number,arr[i].arrival,arr[i].burst,
                arr[i].compl_time,arr[i].ta_time,arr[i].w_time);



    }
}


int main(int argc, char *argv[]) {

    int proc_number = 0;
    printf("Enter the number of processes:\n");
    scanf("%d",&proc_number);
    printf("Enter arrival times for each process:\n");

    struct process processes[proc_number];
    for(int i = 0;i<proc_number;i++){
        struct process pr = {0,0,0,0,0,0};
        processes[proc_number] = pr;
    }

    for(int i = 0;i<proc_number;i++){
        printf("Process %d arrival time:\n",i);
        scanf("%d",&processes[i].arrival);


    }

    printf("Enter burst times for each process:\n");
    for(int i = 0;i<proc_number;i++){
        printf("Process %d burst time:\n",i);
        scanf("%d",&processes[i].burst);


    }

    bubbleSort(processes,proc_number);

    int compl_sum = 0;
    double avg_tat = 0;
    double avg_wait = 0;
    for(int i = 0;i<proc_number;i++){
        processes[i].number = i;
        compl_sum = compl_sum+processes[i].burst;
        processes[i].compl_time = compl_sum;
        processes[i].ta_time = processes[i].compl_time-processes[i].arrival;

        processes[i].w_time = processes[i].ta_time-processes[i].burst;
        if(processes[i].w_time<0){
            processes[i].w_time = 0;
        }
        avg_tat+=(double)processes[i].ta_time;
        avg_wait+=(double)processes[i].w_time;
    }
    avg_wait = avg_wait/(double)proc_number;
    avg_tat = avg_tat/(double)proc_number;

    printArray(processes,proc_number);
    printf("\nAverage WT: %f\n",avg_wait);
    printf("Average TAT: %f",avg_tat);

}