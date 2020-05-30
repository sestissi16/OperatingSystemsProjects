//written by Sari Stissi
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argCount, char *argValues[]){
    int numberArg;
    pid_t pid;

    if(argCount!=2){
        fprintf(stderr, "Missing argument: please enter a positive number when running\n");
        return(-1);
    }else{
        numberArg = atoi(argValues[1]);
    }

    int answerArray[1000000];

    if(numberArg < 0){
        fprintf(stderr, "Number not positive: please enter a positive number when running\n");
        return(-1);
    }

    pid=fork();

    int calcResult = numberArg;
    int index = 0;

    if(pid<0){
        fprintf(stderr, "Fork failed!\n");
        return(-1);
    }else if(pid == 0){
        
        while(calcResult > 1){
            answerArray[index] = calcResult;
            index ++;
            if(calcResult%2 ==0){
                calcResult = calcResult/2;
            } else{
                calcResult = (3 * calcResult) + 1;
            }
        }
        if(calcResult==1){
            answerArray[index] = calcResult;
            index ++;
        } else {
            printf("Did not reach 1!!!\n");
            return(-1);
        }

        for(int i=0; i<index; i++){
            printf("%d,", answerArray[i]);
        }

    } else{
        wait();

        fprintf(stdout, "\nChild process is finished\n");
    }
    return(0);

}