#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int tea=1;

void sys_err(char* sys)
{
    perror(sys);
    exit(1);
}

void func(int sig)
{
    tea = 0;
    return;
}
int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    int fd;
    if(pid==-1)    
    {
        sys_err("fork");
    }
    if(pid>0)
    {
        return 0;
    }
    printf("my pid:%d\n",getpid());
    setsid();
    chdir("/");
    umask(0);
    for(int i=0;i<3;i++)
    {
        close(i);
    }
    fd = open("/home/val/code/newcode/sigint/temp.txt",O_RDWR|O_CREAT|O_APPEND,0664);
    if(fd==-1)
    {
        sys_err("open");
    }
    signal(SIGINT,func);
    char buf[]="我是一个守护进程！\n";
    while (tea)
    {
        write(fd,buf,strlen(buf));
        sleep(3);
    }
 
    return 0;
}
