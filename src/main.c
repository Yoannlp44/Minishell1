/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    (void)av;
    do_minishell(env);
    return (0);
}