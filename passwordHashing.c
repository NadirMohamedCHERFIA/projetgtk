#include "passwordHashing.h"

char *hashPassword(char *password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256((const unsigned char *)password, strlen(password), hash);

    char *hash_str = (char *)malloc((SHA256_DIGEST_LENGTH * 2) + 1);
    if (hash_str == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    hash_str[SHA256_DIGEST_LENGTH * 2] = '\0';

    return hash_str;
}