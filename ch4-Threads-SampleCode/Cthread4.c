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

int sum, sum2; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */

void *runner2(void *param); /* the thread2 */


int main(int argc, char *argv[])
{
pthread_t tid, tid2; /* the thread identifier */
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

/* now wait for the thread to exit */
//pthread_join(tid,NULL);
pthread_join(tid2,NULL);

printf("sum = %d\n",sum);
printf("sum2 = %d\n",sum2);
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
			printf("In runner: sum=%d\n", sum);
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
                        sum2 += (i*5);

			printf("In runner2: sum2=%d\n", sum2);
			//sleep(1);
		}
        }

        pthread_exit(0);
}

