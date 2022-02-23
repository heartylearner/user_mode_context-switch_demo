#include "threadtools.h"

// Please complete this three functions. You may refer to the macro function defined in "threadtools.h"

// Mountain Climbing
// You are required to solve this function via iterative method, instead of recursion.
void ReduceInteger(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);
	Current->i=0;Current->w=0;
	while(1){
		sleep(1);
		if(Current->N==1){
			printf("Reduce Integer: %d\n", 0);
			break;
		}
		if(Current->N==2){
			printf("Reduce Integer: %d\n", 1);
			break;
		}
		if(Current->N==3){
			printf("Reduce Integer: %d\n", 2);
			break;
		}
		if(Current->i+1==Current->N){
			printf("Reduce Integer: %d\n", Current->w);
			break;
		}
		if(Current->i+3==Current->N){
			printf("Reduce Integer: %d\n", Current->w+2);
			break;
		}
		printf("Reduce Integer: %d\n", Current->w);
		Current->w+=1;
		if((Current->N-Current->i)%4==1){
			Current->i+=1;
		}
		else if((Current->N-Current->i)%4==3){
			Current->i-=1;
		}
		else{
			Current->i=Current->N-(Current->N-Current->i)/2;
		}
		ThreadYield();
	}
	ThreadYield();
	ThreadExit();
}

// Reduce Integer
// You are required to solve this function via iterative method, instead of recursion.
void MountainClimbing(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);

	Current->i=0;Current->w=0;
	while(1){
		sleep(1);
		if(Current->N==0||Current->N==1){
			printf("Mountain Climbing: %d\n", 1);
			break;
		}
		if(Current->i==Current->N){
			printf("Mountain Climbing: %d\n", Current->w);
			break;
		}
		if(Current->i==0){
			printf("Mountain Climbing: %d\n",1);
			Current->i=1;
			Current->w=1;
			Current->x=1;
		}
		else{
			printf("Mountain Climbing: %d\n",Current->w);
			Current->i+=1;
			Current->y=Current->w;
			Current->w=Current->w+Current->x;
			Current->x=Current->y;
		}
		ThreadYield();
	}
	ThreadYield();
	ThreadExit();
}

// Operation Count
// You are required to solve this function via iterative method, instead of recursion.
void OperationCount(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);
	//printf("N=%d number=%d\n",Current->N,number);
	Current->i=0;Current->w=0;
	sleep(1);
	if(Current->N%2==1){
		printf("Operation Count: %d\n",(2+2*(Current->N-1)/2)*((Current->N-1)/2)/2);
	}
	else{
		printf("Operation Count: %d\n",(Current->N/2)*(Current->N/2));
	}
	ThreadYield();
	ThreadExit();//直接呼叫exit?不用yeild?
}
