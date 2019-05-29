/*
** EPITECH PROJECT, 2019
** cd home
** File description:
** cd home
*/

#include "minishell.h"
#include <unistd.h>
#include "my.h"

void my_cd_home(char ***env, char *pwd)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *tmp = NULL;

    if ((i = my_getenv("PWD=", *env) < 0))
        return;
    pwd = my_strdup((*env)[i]);
    j = my_getenv("OLDPWD=", *env);
    k = my_getenv("HOME=", *env);
    tmp = my_strdup((*env)[k]);
    if (chdir(tmp + 5) == -1)
        return;
    change_old_pwd(env, pwd, j);
    change_new_pwd(env, tmp, i, 5);
}
