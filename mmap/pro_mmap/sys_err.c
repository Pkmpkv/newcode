#include "inc.h"

void sys_err(const char* err)
{
    perror(err);
    exit(1);
}