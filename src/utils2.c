/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "my.h"
#include "minishell.h"

int check_builtins2(char **tab, char ***env)
{
    if (my_strcmp(tab[0], "setenv") == 0){
        (*env) = my_setenv(tab, *env);
        return (0);
    }
    if (my_strcmp(tab[0], "env") == 0){
        print_env(*env);
        return (0);
    }
    return (1);
}
