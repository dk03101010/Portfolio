#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define TIMES 5
#define ITEMSIZE 30

struct Buffer
{
    int item[ITEMSIZE];
    int size;
};



pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void print(char* a, char* b) {
 //   pthread_mutex_lock(&mutex1);

    printf("1: %s\n", a);
    printf("1: %s\n\n", b);
    sleep(1);
    printf("2: %s\n", a);
    printf("2: %s\n", b);
 //   pthread_mutex_unlock(&mutex1);

}
// These two functions will run concurrently.
void* print_i(void *ptr) {
    for (int i = 0; i < TIMES; i++)
        print("AAAAAAAAA", "AAAAAAAAA");
        print("AAAAAAAAA", "AAAAAAAAA");
        print("AAAAAAAAA", "AAAAAAAAA");
}

void* print_j(void *ptr) {
    for (int j = 0; j < TIMES; j++)
        print("BBBBBBBBB", "BBBBBBBBB");
        print("BBBBBBBBB", "BBBBBBBBB");
        print("BBBBBBBBB", "BBBBBBBBB");

}

int main() {

    struct Buffer buffer;

    int i;
    pthread_t t1, t2;

    for (i = 0; i < TIMES; ++i) {
        buffer.item[i] = -1;
        buffer.size = 0;

        pthread_setconcurrency(2);

        int iRet1 = pthread_create(&t1, NULL, print_i, NULL);
        int iRet2 = pthread_create(&t2, NULL, print_j, NULL);

        pthread_exit(0);
    }
}

