/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:42:41 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 11:48:34 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdlib.h>

t_ast	*build_ast(t_token *tokens)
{
	t_ast	*root;
	t_ast	*cmd_node;
	t_token	*current;
	t_ast	*new_cmd;
	t_ast	*pipe_node;
	t_ast	*redir_node;

	root = NULL;
	cmd_node = NULL;
	current = tokens;
	while (current)
	{
		if (current->type == WORD)
		{
			new_cmd = build_command_node(&current);
			if (!root)
				root = new_cmd;
			else
				cmd_node->right = new_cmd;
			cmd_node = new_cmd;
		}
		else if (current->type == PIPE)
		{
			pipe_node = new_ast_node(NODE_PIPE, NULL);
			if (!root)
				root = pipe_node;
			else
			{
				pipe_node->left = root;
				root = pipe_node;
			}
			current = current->next;
		}
		else if (current->type == REDIR_IN || current->type == REDIR_OUT
			|| current->type == REDIR_OUT_APPEND || current->type == HEREDOC)
		{
			redir_node = parse_redirection(&current);
			if (cmd_node)
				cmd_node->right = redir_node;
		}
		else
			current = current->next;
	}
	return (root);
}
