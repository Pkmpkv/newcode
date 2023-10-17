#include "inc.h"

pthread_mutex_t lork;

void sys_err(const char* err)
{
    perror(err);
    exit(1);
}

void* ftn(void* me)
{
    while (1)
    {
        pthread_mutex_lock(&lork);
        printf("HELLO");
        sleep(rand()%1);
        printf("WORD\n");
        pthread_mutex_unlock(&lork);
        sleep(rand()%1);
    }
    return NULL;   
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int ret;
    ret = pthread_mutex_init(&lork,NULL);
    if(ret==-1)
    {
        sys_err("mutex");
    }
    ret = pthread_create(&tid,NULL,ftn,NULL);
    if(ret==-1)
    {
        sys_err("ptheard");
    }
    while (1)
    {
        pthread_mutex_lock(&lork);
        printf("hello");
        sleep(rand()%1);
        printf("word\n");
        pthread_mutex_unlock(&lork);
        sleep(rand()%1);
    }
    pthread_mutex_unlock(&lork);
    pthread_join(tid,NULL);
    return 0;
}
