#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *f(void *msg) {
     printf("%s \n", (char *) msg);
     return 0;
}


int main(int argc, char *argv[]) {

    pthread_t thread1;
    pthread_t thread2;
    
    int threadId1;
    int threadId2;

    threadId1 = pthread_create(&thread1, NULL, f, (void*) "Thread1");
    threadId2 = pthread_create(&thread2, NULL, f, (void*) "Thread2");
    
    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL); 
    
    printf("Thread 1 returns: %d\n", threadId1);
    printf("Thread 2 returns: %d\n", threadId2);
    
    return 0;  
}   

