#include <unistd.h>
#include <stdio.h>
#include <lib.h>
#include <sys/syscall.h>

int response;

int printOptions(){
    printf("1. First Fit Algorithm\n2. Best Fit Algorithm\n3. Worst Fit Algorithm\n4. Random Fit Algorithm\n5. Next Fit Algorithm\n");
    return 0;
}

int errorHandler(){
    printf("To see options again type the number 6; To quit type the number 0\n");
    scanf("%d", &response);
    if (response == 0){
        printf("Quitting....");
        return -1;
    }
    return response;
}

int main(){
    printf("Get system info....");
    syscall(PM_PROC_NR, 47);



    printf("Memory allocation algorithm choices:\n");
    printOptions();
    printf("Enter the number by the algorithm you want to use: ");
    scanf("%d", &response);
    if (response < 0 || response > 4){
        fprintf(stderr, "Error: Just enter a number\n");
        response = errorHandler();
    }
    if (response == 6){
        printOptions();
        printf("Enter the number by the algorithm you want to use: ");
        scanf("%d", &response);
    } else if (response < 0 || response > 4){
        fprintf(stderr, "Second Error: Didn't enter a number, quitting....\n");
        return -1;
    } else {
        if(response == 1){
            printf("First Fit is the default and will be used now...");

        } else if (response == 2){
            printf("Calling PM_SETBESTFIT....");
            syscall(PM_PROC_NR, 48);
        } else if (response == 3){
            printf("Calling PM_SETWORSTFIT....");
            syscall(PM_PROC_NR, 49);
        } else if (response == 4){
            printf("Calling PM_SETRANDOMFIT....");
            syscall(PM_PROC_NR, 50);
        } else if (response == 5){
            printf("Calling PM_SETNEXTFIT....");
            syscall(PM_PROC_NR, 51);
        }
    }

    return 0;

}