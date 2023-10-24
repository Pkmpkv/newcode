#include "inc.h"

struct msgbuf
{
    long mtype;
    char mtext[BUFFER];
}Mesage;

void sys_err(const char* err)
{
    perror(err);
    _exit(1);
}

int main(int argc, char const *argv[])
{
    key_t key=ftok(".",63);
    int msgid;
    int cnt = 100;

    Mesage.mtype=100;
    strcpy(Mesage.mtext,"hello word!");
 
    msgid = msgget(key,0664|IPC_CREAT);
    if(msgid==-1)
    {
        sys_err("msggst");
    }
    while (cnt--)  
    {
        msgsnd(msgid,(void*)&Mesage,strlen(Mesage.mtext)+10,0);
        sleep(1);
    }

    return 0;
}
