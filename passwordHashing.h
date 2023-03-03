#ifndef __PASSWORDHASHING_H__
#define __PASSWORDHASHING_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hashPassword(char *password);

#endif