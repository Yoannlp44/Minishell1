/*
** EPITECH PROJECT, 2019
** print env
** File description:
** print env
*/

#include "my.h"

void print_env(char **env)
{
    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
}