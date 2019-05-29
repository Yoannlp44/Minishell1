/*
** EPITECH PROJECT, 2019
** cd
** File description:
** cd
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void change_new_pwd(char ***env, char *pwd, int i, int size)
{
    (*env)[i] = malloc(sizeof(char) * (my_strlen(pwd) + size));
    (*env)[i] = my_strcpy((*env)[i], "PWD=");
    (*env)[i] = my_strcat((*env)[i], pwd + size);
    free(pwd);
}

void change_old_pwd(char ***env, char *old_pwd, int j)
{
    (*env)[j] = malloc(sizeof(char) * (my_strlen(old_pwd) + 4));
    (*env)[j] = my_strcpy((*env)[j], "OLDPWD=");
    (*env)[j] = my_strcat((*env)[j], old_pwd + 4);
    free(old_pwd);
}

void my_cd_old_pwd(char ***env, char *old_pwd, char *pwd)
{
    int i = 0;
    int j = 0;

    if ((i = my_getenv("PWD=", *env)) >= 0\
&& (j = my_getenv("OLDPWD=", *env)) >= 0) {
        old_pwd = my_strdup((*env)[j]);
        pwd = my_strdup((*env)[i]);
    }
    else
        return;
    my_printf("%s\n", old_pwd + 7);
    if (chdir(old_pwd + 7) == -1)
        return;
    change_old_pwd(env, pwd, j);
    change_new_pwd(env, old_pwd, i, 7);
}

void my_simple_cd(char **tab, char ***env, char *old_pwd, char *pwd)
{
    int i = 0;
    int j = 0;

    if ((i = my_getenv("PWD=", *env)) >= 0\
&& (j = my_getenv("OLDPWD=", *env)) >= 0)
        old_pwd = my_strdup((*env)[i]);
    else
        return;
    if (chdir(tab[1]) == -1) {
        my_printf("%s: Not a directory.\n", tab[1]);
        return;
    }
    change_old_pwd(env, old_pwd, j);
    change_pwd(env, i, tab, pwd);
}

void my_cd(char **tab, char ***env)
{
    char *pwd = NULL;
    char *old_pwd = NULL;

    *env = check_env(*env);
    if (tab[1] != NULL){
        if (my_strcmp(tab[1], "-") == 0)
            my_cd_old_pwd(env, old_pwd, pwd);
        else
            my_simple_cd(tab, env, old_pwd, pwd);
    } else
        my_cd_home(env, pwd);
}
