/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <fcntl.h>

int check_builtins(char **tab, char ***env)
{
    if (my_strcmp(tab[0], "exit") == 0){
        free_my_tab(tab);
        exit(0);
    }
    if (my_strcmp(tab[0], "cd") == 0){
        my_cd(tab, env);
        return (0);
    }
    if (my_strcmp(tab[0], "unsetenv") == 0){
        (*env) = my_unsetenv(tab, *env);
        return (0);
    }
    if (check_builtins2(tab, env) == 0)
        return (0);
    return (1);
}

int my_getenv(char *name, char **env)
{
    int size = my_strlen(name) + 1;
    char *to_find = malloc(sizeof(char) * size);

    if (to_find == NULL)
        return (-1);
    to_find = my_strcpy(to_find, name);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], to_find, my_strlen(name)) == 0) {
            free(to_find);
            return (i);
        }
    }
    free(to_find);
    return (-1);
}

int check_path(char *str, char **env)
{
    int i = 0;
    char *test_path = NULL;

    if ((i = my_getenv("PWD=", env)) < 0)
        return (-1);
    test_path = malloc(sizeof(char) * \
(my_strlen(env[i] + 4) + my_strlen(str) + 2));
    if (test_path == NULL)
        return (-1);
    test_path = my_strcpy(test_path, (env[i] + 4));
    test_path = my_strcat(test_path, "/");
    test_path = my_strcat(test_path, str);
    if (open(test_path, O_RDONLY) != -1 || open(str, O_RDONLY) != -1)
        return (0);
    return (-1);
}

char *find_good_path(char *str, char *path, char **env)
{
    char *good_path = malloc(sizeof(char)\
* (my_strlen(str) + my_strlen(path) + 2));

    if (good_path == NULL)
        return (NULL);
    if (check_path(str, env) == 0)
        return (my_strdup(str));
    good_path = my_strcpy(good_path, path);
    good_path = my_strcat(good_path, "/");
    good_path = my_strcat(good_path, str);
    if (access(good_path, X_OK) == 0)
        return (good_path);
    free(good_path);
    return (NULL);
}

char *get_path(char *str, char **env)
{
    int i = 0;
    char **path = NULL;
    char *good_path = NULL;

    if ((i = my_getenv("PATH=", env)) >= 0)
        path = my_str_to_word_array(env[i] + 5);
    else
        return (my_strdup(str));
    for (i = 0; path[i]; i++){
        if ((good_path = find_good_path(str, path[i], env)) != NULL){
            free_my_tab(path);
            return (good_path);
        }
        free(good_path);
    }
    return (my_strdup("NOT FOUND"));
}
