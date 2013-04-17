#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *f(void *msg) {
     printf("%s\n", (char *) msg);
     return 0;
}
int main(int argc, char *argv[]) {
    pthread_t thread1;
    pthread_t thread2;
    int result1 = pthread_create(&thread1, 0, f, (void *) "Thread1");
    int result2 = pthread_create(&thread2, 0, f, (void *) "Thread2");
    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    printf("Thread 1 returns: %d\n", result1);
    printf("Thread 2 returns: %d\n", result2);   
    return 0;  
}
