/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:38:49 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:36:01 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/lexer.h"
#include "../../include/parser.h"
#include "../../include/executor.h"

void    process_input(char *line, t_env *env);
void    handle_exit(t_env *env);

int    minishell(char **envp)
{
    t_env *my_env  = env_to_list(envp);
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

void process_input(char *line, t_env *env)
{
    t_token *tokens = lexer(line);
    t_ast   *ast    = parse(tokens);

    execute(ast, env);

    free_tokens(tokens);
    free_ast(ast);
}

void    handle_exit(t_env *env)
{
    free_env(env);
    exit(0);
}
