#include "inc.h"

int main(int argc, char const *argv[])
{
    int fd;
    char buf[30];
    int bufsize=1;
    fd = open(argv[1],O_RDONLY,664);
    if(fd==-1)
    {
        perror("open err:");
        exit(1);
    }
    while(bufsize>0)
    {
        bufsize = read(fd,buf,strlen(buf));
        write(STDOUT_FILENO,buf,bufsize);
    }
    close(fd);
    return 0;
}
