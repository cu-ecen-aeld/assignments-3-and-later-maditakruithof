#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{
    DEBUG_LOG("Starting routine");
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    usleep(thread_func_args->wait_to_obtain_ms);
    DEBUG_LOG("Locking mutex");
    if(pthread_mutex_lock(thread_func_args->mutex) != 0)
    {
        ERROR_LOG("Failed to lock mutex");
        thread_func_args->thread_complete_success = false;
        return thread_param;
    }
    usleep(thread_func_args->wait_to_release_ms);
    DEBUG_LOG("Unlocking mutex");
    if(pthread_mutex_unlock(thread_func_args->mutex) != 0)
    {
        ERROR_LOG("Failed to unlock mutex");
        thread_func_args->thread_complete_success = false;
        return thread_param;
    }
    return thread_param;
}

bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    struct thread_data *data = malloc(sizeof(struct thread_data));

    data->thread_complete_success = true;
    data->mutex = mutex;
    data->wait_to_obtain_ms = wait_to_obtain_ms;
    data->wait_to_release_ms = wait_to_release_ms;

    pthread_create(thread, NULL, threadfunc, data);

    return data->thread_complete_success;
}
