/*
** EPITECH PROJECT, 2019
** simple cd
** File description:
** simple cd
*/

#include "my.h"
#include "minishell.h"

char *change_pwd_remove(char *pwd, int cmp_remove)
{
    int i = 0;

    for (i = my_strlen(pwd); cmp_remove > 0; i--){
        if (pwd[i] != '/')
            pwd[i] = '\0';
        if (pwd[i] == '/') {
            pwd[i] = '\0';
            cmp_remove--;
        }
    }
    return (pwd);
}

int check_tab(char **tab, int i, char **pwd, int j)
{
    if (tab[1][0] != '/' && tab[1][0] != '.'){
        (*pwd) = my_realloc(*pwd, 2);
        j = my_strlen(*pwd);
        (*pwd)[j] = '/';
        (*pwd)[j + 1] = '\0';
    }
    if (tab[1][0] == '.' && tab[1][1] != '.')
        i++;
    return (i);
}

char *change_pwd_add(char **tab, char *pwd)
{
    int j = 0;
    int i = 0;

    i = check_tab(tab, i, &pwd, j);
    for (; tab[1][i]; i++){
        if (tab[1][i] == '/' && tab[1][i + 1] == '.' && tab[1][i + 2] == '.'){
            i += 2;
            pwd = change_pwd_remove(pwd, 1);
        } else if (tab[1][i] == '.' && tab[1][i + 1] == '.'){
            pwd = change_pwd_remove(pwd, 1);
            i++;
        } else {
            pwd = my_realloc(pwd, 2);
            j = my_strlen(pwd);
            pwd[j] = tab[1][i];
            pwd[j + 1] = '\0';
        }
    }
    if (pwd[j] == '/')
        pwd[j] = '\0';
    return (pwd);
}

void change_pwd(char ***env, int i, char **tab, char *pwd)
{
    int cmp_remove = 0;

    pwd = my_strdup((*env)[i]);
    for (int i = 0; tab[1][i]; i++)
        if (tab[1][i] == '.')
            cmp_remove++;
    if (cmp_remove != 0){
        cmp_remove /= 2;
        pwd = change_pwd_add(tab, pwd);
        (*env)[i] = my_strdup(pwd);
        return;
    }
    if (tab[1][0] != '/'){
        pwd = my_realloc(pwd, 2);
        pwd = my_strcat(pwd, "/");
    }
    pwd = my_realloc(pwd, my_strlen(tab[1]) + 1);
    pwd = my_strcat(pwd, tab[1]);
    if (pwd[my_strlen(pwd) - 1] == '/')
        pwd[my_strlen(pwd) - 1] = '\0';
    (*env)[i] = my_strdup(pwd);
}