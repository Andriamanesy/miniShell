/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:38:49 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 12:40:35 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/lexer.h"
#include "../../include/parser.h"
#include "../../include/executor.h"
#include "../../include/expander.h"
#include <stdio.h>

void	process_input(char *line, t_env *env);
void	handle_exit(t_env *env);

int g_last_exit_code = 0;

int	minishell(char **envp)
{
	t_env	*my_env;
	char	*line;

	my_env = env_to_list(envp);
	if (!my_env)
	{
		ft_putstr_fd("Failed to copy environment\n", 2);
		return (1);
	}
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		process_input(line, my_env);
		free(line);
	}
	return (0);
}

void free_char_array(char **arr)
{
    int i = 0;
    if (!arr) return;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void process_input(char *line, t_env *env)
{
    t_token *tokens;
    t_ast   *ast;

    if (!line || !*line)
        return;

    // Tokenisation (on passe directement t_env *)
    tokens = tokenize(line, env);
    if (!tokens)
    {
        ft_putstr_fd("Lexer error\n", 2);
        return;
    }

    // Expansion des variables ($VAR, $USER, $?) → utiliser t_env *
    expand_variables(tokens, env);

    // Parsing en AST
    ast = parse(tokens);
    if (!ast)
    {
        ft_putstr_fd("Parser error\n", 2);
        free_tokens(tokens);
        return;
    }

    // Debug : afficher l'AST
    print_ast(ast, 0);

    // Libération mémoire
    free_tokens(tokens);
    free_ast(ast);
}

void	handle_exit(t_env *env)
{
	free_env(env);
	exit(0);
}
