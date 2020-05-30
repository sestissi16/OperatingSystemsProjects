#include <omp.h>
#include <stdio.h>
#include <syscall.h>

int main(int argc, char * argv[])
{
	int i=0;
	int A[]={1, 2, 3, 4, 5};
	int B[]={6, 7, 8, 9, 10};
	int C[]={0,0,0,0,0};
	printf("I am a sequential statement.\n");
	
	#pragma omp parallel
	{
		printf("[tid=%d] I am a parallel region.\n", syscall(SYS_gettid));
	}
#if 1
	#pragma omp parallel for
	for(i=0; i<5; i++){
		C[i]=A[i]+B[i];
		printf("[tid=%d] C[%d]=%d.\n", syscall(SYS_gettid), i, C[i]);
	}
#endif

#if 1
	#pragma omp parallel for
	for(i=0; i<10; i++)
	{
		printf("[tid=%d] %d \n", syscall(SYS_gettid), i);
	}
#endif
	return 0;
}
