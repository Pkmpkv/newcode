#include "inc.h"

int main(int argc, char const *argv[])
{
    int fd, cnt = 0;
    char buf[30];
    fd = open(argv[1], O_WRONLY, 664);
    if (fd == -1)
    {
        perror("open err");
        exit(1);
    }
    while (1)
    {
        sprintf(buf, "reciver %d\n", cnt);
        write(fd, buf, strlen(buf));
        printf("%s\n", buf);
        cnt++;
        sleep(1);
        /* code */
    }
    close(fd);
    return 0;
}