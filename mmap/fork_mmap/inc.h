#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MMAP_SIZE 1024

void sys_err(const char*);

#endif