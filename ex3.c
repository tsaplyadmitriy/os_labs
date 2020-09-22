#include <stdio.h>
#include <stdbool.h>


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




void printArray(struct process arr[], int size)
{
    int i;
    for (i=0; i < size; i++){

        printf("Process number: %d, Arrival: %d, Burst: %d, CT: %d, TAT: %d, WT: %d \n",
               arr[i].number,arr[i].arrival,arr[i].burst,
               arr[i].compl_time,arr[i].ta_time,arr[i].w_time);



    }
}


bool isDone(int arr[], int size){

    for(int i = 0;i<size;i++){
        if(arr!=0){return false;}
    }
    return true;


}


int main(int argc, char *argv[]) {

    int proc_number = 0;
    int quantum = 0;
    printf("Enter quantum for Round-Robin algorithm:\n");
    scanf("%d",&quantum);
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


    int time= 0;
    int w_time[proc_number];
    int b_rem[proc_number];
    for(int i = 0;i<proc_number;i++){
        b_rem[i] = processes[i].burst;
        w_time[i] = 0;
    }

    while(1){

        int flag  = 0;
        for(int i = 0;i<proc_number;i++){

            if(b_rem[i]>0 && time>=processes[i].arrival){

                if(b_rem[i]>quantum){
                    time+=quantum;
                    b_rem[i]-=quantum;
                }else{
                    time += b_rem[i];
                    w_time[i] = time - processes[i].burst -processes[i].arrival;
                    b_rem[i] = 0;
                }

                flag = 1;
            }
        }
        if(flag==0){
            break;
        }
    }

    double avg_tat = 0;
    double avg_wait = 0;
    for(int i = 0;i<proc_number;i++){
        processes[i].number = i;


        processes[i].w_time =w_time[i];
        processes[i].ta_time = w_time[i]+processes[i].burst;
        processes[i].compl_time = processes[i].ta_time+processes[i].arrival;

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
