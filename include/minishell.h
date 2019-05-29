/*
** EPITECH PROJECT, 2019
** proto
** File description:
** proto
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

void do_minishell(char **env);
char *get_path(char *, char **env);
void exec_cmd(char **tab, char **env, char *path);
int check_builtins(char **tab, char ***env);
void free_my_tab(char **tab);
void my_cd(char **tab, char ***env);
int my_getenv(char *name, char **env);
char *my_realloc(char *str, int size);
void change_pwd(char ***env, int i, char **tab, char *pwd);
char *change_pwd_add(char **tab, char *pwd);
void change_old_pwd(char ***env, char *old_pwd, int j);
void change_new_pwd(char ***env, char *pwd, int i, int size);
void my_cd_home(char ***env, char *pwd);
char **my_unsetenv(char **tab, char **env);
char **my_setenv(char **tab, char **env);
char **check_env(char **env);
void print_env(char **env);
int check_builtins2(char **tab, char ***env);

#endif /* !MINISHELL_H_ */