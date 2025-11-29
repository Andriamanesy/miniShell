/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:38:49 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 10:29:28 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../include/minishell.h"

char    **copy_env(char **envp);
void    process_input(char *line, char **envp);
void    handle_exit(char **envp);

int    minishell(char **envp)
{
    char **my_env  = copy_env(envp);
    if (!my_env)
    {
        ft_putstr_fd("Failed to copy environment\n", 2);
        return (1);
    }
    while (1)
    {
        char    *line = readline("minishell$ ");
        if (!line)
            handle_exit(my_env);
        if (*line)
            add_history(line);
        process_input(line, my_env);
        free(line);
    }
    return (0);
}

char **copy_env(char **envp)
{
    int i = 0;
    while (envp[i])
        i++;

    char **new_env = malloc(sizeof(char *) * (i + 1));
    if (!new_env)
        return NULL;

    for (int j = 0; j < i; j++)
    {
        new_env[j] = ft_strdup(envp[j]);
        if (!new_env[j])
        {
            while (j-- > 0)
                free(new_env[j]);
            free(new_env);
            return NULL;
        }
    }
    new_env[i] = NULL;
    return new_env;
}

void   process_input(char *line, char **envp)
{
    (void) envp;
    printf("You entered %s\n", line);
}

void    handle_exit(char **envp)
{
    int i;

    i = 0;
    if (envp)
    {
        while (envp[i])
        {
            free(envp[i]);
            i++;
        }
        free(envp);
    }
    exit(0);
}
