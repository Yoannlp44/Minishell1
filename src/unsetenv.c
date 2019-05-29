/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** unsetenv
*/

#include <unistd.h>
#include "minishell.h"
#include "my.h"
#include <stdlib.h>

char *fill_str(char **tab, char *str)
{
    if (tab[2] == NULL) {
        str = malloc(sizeof(char) * (my_strlen(tab[1]) + 2));
        str = my_strcpy(str, tab[1]);
        str = my_strcat(str, "=");
    } else {
        str = malloc(sizeof(char) *\
        (my_strlen(tab[1]) + my_strlen(tab[2]) + 2));
        str = my_strcpy(str, tab[1]);
        str = my_strcat(str, "=");
        str = my_strcat(str, tab[2]);
    }
    return (str);
}

int check_alphanum(char c)
{
    if ((c <= 9 && c >= 0) || (c <= 'z' && c >= 'a') \
|| (c <= 'Z' && c >= 'A') || c == '_')
        return (0);
    return (-1);
}

int check_setenv(char **tab)
{
    for (int i = 0; tab[1][i]; i++)
        if (check_alphanum(tab[1][i]) != 0) {
            my_printf("setenv: Variable name ");
            my_printf("must contain alphanumeric characters.\n");
            return (-1);
        }
    return (0);
}

char **my_setenv(char **tab, char **env)
{
    int i = 0;
    char **tmp = NULL;
    char *str = NULL;

    if (tab[1] == NULL){
        print_env(env);
        return (env);
    }
    if (check_setenv(tab) == -1)
        return (env);
    for (; env[i]; i++);
    tmp = malloc(sizeof(char *) * (i + 2));
    for (i = 0; env[i]; i++)
        tmp[i] = my_strdup(env[i]);
    str = fill_str(tab, str);
    tmp[i] = my_strdup(str);
    tmp[i + 1] = NULL;
    return (tmp);
}

char **my_unsetenv(char **tab, char **env)
{
    int i = 0;
    int j = 0;
    int z = 0;
    char **tmp = NULL;

    for (; env[i]; i++);
    tmp = malloc(sizeof(char *) * i);
    if (tab[1] == NULL || (j = my_getenv(tab[1], env)) < 0)
        return (env);
    for (i = 0; env[i]; i++){
        if (i != j){
            tmp[z] = my_strdup(env[i]);
            z++;
        }
    }
    tmp[z] = NULL;
    return (tmp);
}