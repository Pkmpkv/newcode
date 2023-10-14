#include "inc.h"

int main(int argc, char const *argv[])
{
    int fd,umap,cnt=10;
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
    sleep(5);
    while (cnt--)
    {
        sprintf(buf,"我是你的%d号爸爸\n",cnt);
        strcpy(p,buf);
        sleep(1);
    }
    umap = munmap(p,MMAP_SIZE);
    if(umap==-1) sys_err("munmap err");
    close(fd);
    execlp("rm","rm","text.txt",NULL);
    return 0;
}