//written by Sari Stissi
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MIN_PID 300
#define MAX_PID 5000

int possibleNums = 5000 - 300;

pid_t pid;
/*create an array where index 0 = 300, 1 =301, etc.
if the value at the index is 0 it is available
if the value at the index is 1 it is unavailable*/
int pidArray[5000-300];

int allocate_map(void){
// in this function I will set all the values to zero in the array to say that all pids are available
    for(int i=0; i < (possibleNums - 1); i++){
        pidArray[i] = 0;
    }
    if(pidArray[possibleNums-1] == 0){
        return 0;
    } else
    {
        return -1;
    }
}

int allocate_pid(void){
// this function will run through the array and find the first index with the value 0 to assign the pid to that
    int found = -1;
    for(int j=0; j<(possibleNums); j++){
        if(pidArray[j] == 0){
            pid = j + 300;
            pidArray[j] =1;
            found = 0;
            break;
        }
    }
    return found;
}

void release_pid(int pid){
    if(pid < 300 || pid > 5000){
        fprintf(stderr, "Invalid pid number. Must be between 300 and 5000.\n");
    } else
    {
        pidArray[pid - 300] = 0;
        pid = -1;
    }
}

void printTakenPid(){
    int noPidsTaken = 1;
    fprintf(stdout, "\nPrinting pids that are taken...\n");
    for(int k=0; k<possibleNums; k++){
        if(pidArray[k]!=0){
            fprintf(stdout, "Pid %d is taken\n", k+300);
            noPidsTaken = 0;
        }
    }
    if(noPidsTaken == 1){
        fprintf(stdout, "There are no pids taken\n");
    }
}

int main(){
    int pidMap = allocate_map();
    int allocatePid1, allocatePid2, allocatePid3, allocatePid4, allocatePid5, pid1, pid2, pid3, pid4, pid5;

    fprintf(stdout, "Initializing pid data structure....\n\n");
    if(pidMap == 0){
        fprintf(stdout, "Pid data structure initialized successfully!\n\n");
    } else{
        fprintf(stdout, "Pid data structure initialization failed.\n\n");
    }

    printTakenPid();

    fprintf(stdout, "\nCreating processes and allocating pids...\n");
    for(int i=1; i<4; i++){
        if(i==1){
            allocatePid1 = allocate_pid();
            pid1 = pid;
            fprintf(stdout, "Creating process 1.\nPid allocation successful?: %d\nProcess 1's pid is %d\n", allocatePid1, pid1);
        } 
        else if(i==2){
            allocatePid2 = allocate_pid();
            pid2 = pid;
            fprintf(stdout, "Creating process 2.\nPid allocation successful?: %d\nProcess 2's pid is %d\n", allocatePid2, pid2);
        }
        else if (i==3)
        {
            allocatePid3 = allocate_pid();
            pid3 = pid;
            fprintf(stdout, "Creating process 3.\nPid allocation successful?: %d\nProcess 3's pid is %d\n", allocatePid3, pid3);
        }

    }

    printTakenPid();

    fprintf(stdout, "\nRemoving one process before adding more ...\n");

    release_pid(pid2);
    allocatePid2 = -1;

    printTakenPid();

    fprintf(stdout, "\nAdding more processes ...\n");
    for(int i=4; i<6; i++){
        if(i==4){
            allocatePid4 = allocate_pid();
            pid4 = pid;
            fprintf(stdout, "Creating process 4.\nPid allocation successful?: %d\nProcess 4's pid is %d\n\n", allocatePid4, pid4);
        } 
        else if(i==5){
            allocatePid5 = allocate_pid();
            pid5 = pid;
            fprintf(stdout, "Creating process 5.\nPid allocation successful?: %d\nProcess 5's pid is %d\n\n", allocatePid5, pid5);
        }

    }
    printTakenPid();

    fprintf(stdout, "\nRemoving all process...\n");

    release_pid(pid1);
    release_pid(pid3);
    release_pid(pid4);
    release_pid(pid5);
    allocatePid1 = -1;
    allocatePid3 = -1;
    allocatePid4 = -1;
    allocatePid5 = -1;

    printTakenPid();

    fprintf(stdout, "\nDone showing examples!\n");   
}
    