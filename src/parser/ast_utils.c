/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:13 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:49:23 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdio.h>

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->value)
		free(ast->value);
	if (ast->argv)
		free_argv(ast->argv);
	free(ast);
}

void	print_ast(t_ast *ast, int level)
{
	int	i;

	if (!ast)
		return ;
	for (i = 0; i < level; ++i)
		printf("  ");
	switch (ast->type)
	{
		case NODE_COMMAND:
			printf("COMMAND");
			if (ast->value)
				printf(": %s", ast->value);
			if (ast->argv)
			{
				printf(" [");
				for (i = 0; ast->argv[i]; ++i)
				{
					if (i)
						printf(", ");
					printf("%s", ast->argv[i]);
				}
				printf("]");
			}
			printf("\n");
			break ;
		case NODE_PIPE:
			printf("PIPE\n");
			break ;
		case NODE_REDIR_OUT:
			printf("REDIR_OUT: %s\n", ast->value ? ast->value : "(null)");
			break ;
		case NODE_REDIR_OUT_APPEND:
			printf("REDIR_OUT_APPEND: %s\n", ast->value ? ast->value : "(null)");
			break ;
		case NODE_REDIR_IN:
			printf("REDIR_IN: %s\n", ast->value ? ast->value : "(null)");
			break ;
		case NODE_HEREDOC:
			printf("HEREDOC: %s\n", ast->value ? ast->value : "(null)");
			break ;
	}
	print_ast(ast->left, level + 1);
	print_ast(ast->right, level + 1);
}

