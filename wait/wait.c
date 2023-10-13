#include "inc.h"

int main(int argc,char* argv[])
{
    int i=0;
    pid_t pid,wpid;
    for(i=0;i<10;i++)
    {
        pid = fork(); 
        if(pid==-1)
        {
            perror("fork err！\n");
            exit(1); 
        }
        if(pid==0)
        {
            printf("I'm child i=%d pid=%d\n",i,getpid()); 
            break;
        }     
    }
    if(i==10)
    {
        int cnt = 0;
        while((wpid=waitpid(-1,NULL,WNOHANG))!=-1)
        {
            printf("waitpid chlid %d cnt=%d\n",wpid,cnt);
            /* code */
            cnt++;
        }
    }
    return 0;
}