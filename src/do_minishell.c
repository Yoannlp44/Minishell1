/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>
#include "minishell.h"

char *get_player_input(void)
{
    char * line = NULL;
    size_t len = 0;
    int result;

    result = getline(&line, &len, stdin);
    if (result == -1)
        return (NULL);
    return (line);
}

void free_my_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

char **check_env(char **env)
{
    int i = 0;
    char **tab = NULL;
    char *str = NULL;
    char *str2 = NULL;
    int j = 0;

    if ((i = my_getenv("OLDPWD=", env)) < 0){
        if ((j = my_getenv("PWD=", env)) < 0)
            return (env);
        str = malloc(sizeof(char) * (my_strlen(env[j] + 4) + 15));
        str = my_strcpy(str, "setenv OLDPWD ");
        str2 = my_strdup(env[j] + 4);
        str = my_strcat(str, str2);
        tab = my_str_to_word_array(str);
        env = my_setenv(tab, env);
    }
    return (env);
}

void do_minishell(char **env)
{
    char **tab = NULL;
    char *str = NULL;
    char *path = NULL;

    while (42){
        my_putstr("$> ");
        if ((str = get_player_input()) == NULL)
            exit(0);
        tab = my_str_to_word_array(str);
        if (tab[0] != NULL) {
            path = get_path(tab[0], env);
            check_builtins(tab, &env) != 0 ? exec_cmd(tab, env, path) : 0;
            free(path);
        }
        free_my_tab(tab);
        free(str);
    }
}