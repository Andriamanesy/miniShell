/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:13 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 11:57:44 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdlib.h>
#include <stdio.h>

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->value)
		free(ast->value);
	free(ast);
}

void	print_ast(t_ast *ast, int level)
{
	int	i;

	i = 0;
	if (!ast)
		return ;
	while (i < level)
	{
		printf("  ");
		i++;
	}
	switch (ast->type)
	{
		case NODE_COMMAND:
			printf("COMMAND: %s\n", ast->value);
			break ;
		case NODE_PIPE:
			printf("PIPE\n");
			break ;
		case NODE_REDIR_OUT:
			printf("REDIR_OUT: %s\n", ast->value);
			break ;
		case NODE_REDIR_OUT_APPEND:
			printf("REDIR_OUT_APPEND: %s\n", ast->value);
			break ;
		case NODE_REDIR_IN:
			printf("REDIR_IN: %s\n", ast->value);
			break ;
		case NODE_HEREDOC:
			printf("HEREDOC: %s\n", ast->value);
			break ;
	}
	print_ast(ast->left, level + 1);
	print_ast(ast->right, level + 1);
}
