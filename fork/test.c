#include "inc.h"

int main(int argc,char* argv[])
{
    printf("haha-->\n");
    __pid_t pid = fork();
    if(pid==-1)
    {
        perror("fork err");
        _exit(1);
    }
    else if(pid>0)
    {
        //sleep(1);
        printf("I'm father! my pid=%d\n",getpid());
    }
    else if(pid==0)
    {
        printf("I'm child! my pid = %d,my father pid=%d\n",getpid(),getppid());
    }
    return 0;
}