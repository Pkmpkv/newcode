#include "inc.h"

int main(int argc, char const *argv[])
{
    char* p=NULL;
    char buf[30];
    int fd;
    int umap=0;
    int cnt=100;
    fd = open("text.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd==-1)
    {
        perror("open err");
        _exit(1);
    }
    ftruncate(fd,MMAN_SIZE);
    lseek(fd,0,SEEK_END);
    p=mmap(NULL,MMAN_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p==MAP_FAILED)
    {
        perror("mmap err:");
        _exit(1);
    }
    while (cnt--)
    {
        sprintf(buf,"我是小花菜%d号-->",cnt);
        strcpy(p,buf);
        printf("哈哈哈，%s",p);
        if(cnt%10==0)
        {
            printf("\n");
        }
        sleep(1);
    }
    umap = munmap(p,MMAN_SIZE);
    if(umap==-1)
    {
        perror("munmap err!");
        _exit(1);
    }
    close(fd);
    execlp("rm","rm","text.txt",NULL);
    return 0;
}
