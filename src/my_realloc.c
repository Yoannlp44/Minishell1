/*
** EPITECH PROJECT, 2019
** realloc
** File description:
** realloc
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_realloc(char *str, int size)
{
    char *tmp = NULL;
    int i = 0;

    i = my_strlen(str);
    tmp = malloc(sizeof(char) * i + 1);
    for (i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    str = malloc(sizeof(char) * (size + i + 1));
    for (i = 0; tmp[i]; i++)
        str[i] = tmp[i];
    str[i] = '\0';
    return (str);
}