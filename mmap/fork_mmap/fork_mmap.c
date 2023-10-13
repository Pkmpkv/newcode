#include "inc.h"

int main(int argc, char const *argv[])
{
    int fd,umap,cnt=10;
    pid_t pid;
    char* p;
    char buf[30];

    fd = open("text.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd==-1)
    {
        sys_err("open");
    }
    ftruncate(fd,MMAP_SIZE);
    lseek(fd,0,SEEK_END);
    p = mmap(NULL,MMAP_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p==MAP_FAILED)
    {
        sys_err("mmap");
    }
    pid = fork();
    if(pid==-1)
    {
        sys_err("fork");
    }
    while (cnt--)
    {
        if(pid>0)
        {
            strcpy(p,"哈哈，我是你爸爸！");
        }
        else if (pid==0)
        {
            printf("我收到的消息是：%s\n",p);
        }
        sleep(1);
    }
    umap = munmap(p,MMAP_SIZE);
    if(umap==-1) sys_err("munmap err");
    close(fd);
    execlp("rm","rm","text.txt",NULL);
    return 0;
}
