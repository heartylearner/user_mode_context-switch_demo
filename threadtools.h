//要跟助教sim配合?
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

extern int timeslice, switchmode;

typedef struct TCB_NODE *TCB_ptr;
typedef struct TCB_NODE{
    jmp_buf  Environment;
    int      Thread_id;
    TCB_ptr  Next;
    TCB_ptr  Prev;
    int i, N;
    int w, x, y, z;
} TCB;

extern jmp_buf MAIN, SCHEDULER;
extern TCB_ptr Head;
extern TCB_ptr Current;
extern TCB_ptr Work;
extern sigset_t base_mask, waiting_mask, tstp_mask, alrm_mask;//waiting_mask用處?

void sighandler(int signo);
void scheduler();

// Call function in the argument that is passed in
#define ThreadCreate(function, thread_id, number){\           
	/* Please fill this code section. */\
    if(setjmp(MAIN)==0){\
        function(thread_id,number);\
    }\
}

// Build up TCB_NODE for each function, insert it into circular linked-list
#define ThreadInit(thread_id, number)\
{\                                  
	/* Please fill this code section. */\	
    Work=(TCB_ptr)malloc(sizeof(TCB));\
    Work->Thread_id=thread_id;\
    Work->N=number;\
    Work->i=0;\
    /*Work->w=0;*/\
    if(Head==NULL){\
        Head=Current=Work->Next=Work->Prev=Work;\
    }\
    else{\
        Current->Next=Work;Work->Prev=Current;Work->Next=Head;Head->Prev=Work;Current=Current->Next;\
    }\
    if(setjmp(Work->Environment)==0)longjmp(MAIN,1);\
}

// Call this while a thread is terminated
#define ThreadExit()\
{\                                                
	/* Please fill this code section. */\
    longjmp(SCHEDULER,2);\				  
}

// Decided whether to "context switch" based on the switchmode argument passed in main.c
#define ThreadYield()\
{\ 
	/* Please fill this code section. */\
    if(switchmode==0){\
        if (setjmp(Current->Environment) == 0)longjmp(SCHEDULER, 1);\
    }\
    else{\
        sigpending(&waiting_mask);\
        if(sigismember(&waiting_mask,SIGTSTP)){\
            if(setjmp(Current->Environment)==0){\
            	sigprocmask(SIG_UNBLOCK,&tstp_mask,NULL);\
	    }\
        }\
        else if(sigismember(&waiting_mask,SIGALRM)){\
		if(setjmp(Current->Environment)==0){\
			sigprocmask(SIG_UNBLOCK,&alrm_mask,NULL);\
		}\
        }\
    }\
}
