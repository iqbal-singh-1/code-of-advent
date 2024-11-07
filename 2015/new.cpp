#include <stdio.h>
#include <iostream>
#include <pthread.h>
using namespace std;
pthread_mutex_t mutex;

int main() {

        if (pthread_mutex_init(&mutex, NULL) != 0) {
         cout<<"Mutex initialization failed.\n";
         return 1;
        }

        if (pthread_mutex_lock(&mutex) != 0) {
         cout<<"Mutex locking failed.\n";
         return 1;
        }

        cout<<"Inside critical section.\n";

        if (pthread_mutex_unlock(&mutex) != 0) {
         cout<<"Mutex unlocking failed.\n";
         return 1;
        }

        if (pthread_mutex_destroy(&mutex) != 0) {
        cout<<"Mutex destruction failed.\n";
         return 1;
        }

        return 0;
}
