#include "inc.h"

int main(int argc,char* argv[])
{
    int fd = open("test.txt",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd == -1)
    {
        perror("open err");
        exit(1);
    }
    dup2(fd,STDOUT_FILENO);
    execlp("ls","ls","-l","-a",NULL);
    close(fd);
    return 0;
}