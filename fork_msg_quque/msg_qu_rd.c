#include "inc.h"

struct msgbuf
{
    long mtype;
    char mtext[1024];
}Mesage;

void sys_err(const char* err)
{
    perror(err);
    _exit(1);
}

int main(int argc, char const *argv[])
{
    key_t key=ftok("./",63);
    int msgid;
    int cnt=0;
    msgid = msgget(key,0664|IPC_CREAT);
    if(msgid==-1)
    {
        sys_err("msggst");
    }
    while (1)
    {
        cnt++;
        memset(Mesage.mtext,0,BUFFER);
        if(msgrcv(msgid,(void*)&Mesage.mtext,strlen(Mesage.mtext),100,0)==-1)
        {
            sys_err("msgrcv err");
        }
        printf("mtype=%d\tmtext=%s\n",cnt,Mesage.mtext);
        sleep(1);
    }
    if(msgctl(msgid,IPC_RMID,0)==-1)
    {
        sys_err("msgctl err");
    }
    return 0;
}
