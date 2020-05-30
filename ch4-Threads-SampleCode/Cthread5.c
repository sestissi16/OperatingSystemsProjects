/**
 * A pthread program illustrating how to
 * create a simple thread and some of the pthread API
 * This program implements the summation function where
 * the summation operation is run as a separate thread.
 *
 * Most Unix/Linux/OS X users
 * gcc thrd.c -lpthread
 *
 * Solaris users must enter
 * gcc thrd.c -lpthreads
 *
 * Figure 4.9
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <pthread.h>
#include <stdio.h>

int sum, sum2, sum3, sum4, sum5; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */
void *runner2(void *param); /* the thread2 */
void *runner3(void *param); /* the thread3 */
void *runner4(void *param); /* the thread4 */
void *runner5(void *param); /* the thread5 */

int main(int argc, char *argv[])
{
pthread_t tid, tid2, tid3, tid4, tid5; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != 2) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	/*exit(1);*/
	return -1;
}

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	/*exit(1);*/
	return -1;
}

/* get the default attributes */
pthread_attr_init(&attr);

/* create the thread */
pthread_create(&tid,&attr,runner,argv[1]);
pthread_create(&tid2,&attr,runner2,argv[1]);
pthread_create(&tid3,&attr,runner3,argv[1]);
pthread_create(&tid4,&attr,runner4,argv[1]);
pthread_create(&tid5,&attr,runner5,argv[1]);


/* now wait for the thread to exit */
pthread_join(tid,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
pthread_join(tid4,NULL);
pthread_join(tid5,NULL);

printf("[main] sum = %d\n",sum);
printf("[main] sum2 = %d\n",sum2);
printf("[main] sum3 = %d\n",sum3);
printf("[main] sum4 = %d\n",sum4);
printf("[main] sum5 = %d\n",sum5);

return 0;
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param) 
{
int i, upper = atoi(param);
sum = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
		{		
			sum += i;
			printf("[runner] sum=%d\n", sum);
			sleep(1);
		}
	}

	pthread_exit(0);
}

void *runner2(void *param)
{
int i, upper = atoi(param);
sum2 = 0;

        if (upper > 0) {
                for (i = 1; i <= upper; i++)
		{
                        sum2 += (i*2);

			printf("[runner2] sum2=%d\n", sum2);
			sleep(1);
		}
        }

        pthread_exit(0);
}
void *runner3(void *param)
{
int i, upper = atoi(param);
sum3 = 0;

        if (upper > 0) {
                for (i = 1; i <= upper; i++)
                {
                        sum3 += (i*3);

                        printf("[runner3] sum3=%d\n", sum3);
                        sleep(1);
                }
        }

        pthread_exit(0);
}
void *runner4(void *param)
{
int i, upper = atoi(param);
sum4 = 0;

        if (upper > 0) {
                for (i = 1; i <= upper; i++)
                {
                        sum4 += (i*4);

                        printf("[runner4] sum4=%d\n", sum4);
                        sleep(1);
                }
        }

        pthread_exit(0);
}
void *runner5(void *param)
{
int i, upper = atoi(param);
sum5 = 0;

        if (upper > 0) {
                for (i = 1; i <= upper; i++)
                {
                        sum5 += (i*5);

                        printf("[runner5] sum5=%d\n", sum5);
                        sleep(1);
                }
        }

        pthread_exit(0);
}

