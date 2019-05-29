/*
** EPITECH PROJECT, 2019
** exec cmd
** File description:
** exec cmd
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include <unistd.h>
#include <sys/stat.h>

void check_signal(void)
{
    int status;

    wait(&status);
    if (WIFSIGNALED(status)){
        if (WTERMSIG(status) == 11)
            my_putstr("Segmentation fault\n");
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception\n");
    }
}

int check_exec(char **tab, char *path)
{
    struct stat s;

    if (my_strcmp(path, "NOT FOUND") == 0){
        my_printf("%s: Command not found.\n", tab[0]);
        return (-1);
    }
    s.st_mode = 0;
    stat(tab[0], &s);
    if (S_ISDIR(s.st_mode)){
        my_printf("%s: Permission denied.\n", tab[0]);
        return (-1);
    }
    return (0);
}

void exec_cmd(char **tab, char **env, char *path)
{
    pid_t pid;

    if (check_exec(tab, path) != 0)
        return;
    if ((pid = fork()) == -1){
        perror("fork");
        exit(84);
    }
    if (pid == 0){
        if (execve(path, tab, env) == -1){
            my_printf("%s: Exec format error. Wrong Architecture.\n", path);
            exit(84);
        }
    } else
        check_signal();
}
