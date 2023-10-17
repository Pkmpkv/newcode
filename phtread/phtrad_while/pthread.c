#include "inc.h"

void sys_err(const char* err)
{
    perror(err);
    exit(1);
}

void* fnt(void* tem)
{
    int i = (int*)tem;
    printf("my tid: %ld,i= %d\n",pthread_self(),i);
    return NULL;
}

int main(int argc, char const *argv[])
{
    int i=0;
    pthread_t tid;
    int stu;
    for(;i<10;i++)    
    {
        stu = pthread_create(&tid,NULL,fnt,(void*)i);
        if(stu == -1)
        {
            sys_err("pthrad");
        }
    }
    //printf("my tid: %ld,i= %d\n",pthread_self(),i);
    //sleep(2);
    pthread_exit(NULL);
}
