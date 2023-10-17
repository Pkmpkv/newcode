#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void fun()
{
    printf("haha\n");
    return;
}

void fun2()
{
    printf("meme\n");
}

void funp(void(*p)(),int a)
{
    p();
    printf("-->%d\n",a);
    return;
}


int main(int argc, char const *argv[])
{
    funp(fun,10);
    return 0;
}
