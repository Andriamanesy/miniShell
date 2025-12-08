/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:42:41 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:48:28 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_ast	*build_ast(t_token *tokens)
{
	t_ast	*root = NULL;
	t_ast	*attach = NULL;
	t_ast	*node;
	t_ast	*redir_node;

	while (tokens)
	{
		if (tokens->type == WORD)
		{
			node = build_command_node(&tokens);
			if (!node)
				return (free_ast(root), NULL);
			if (!root)
			{
				root = node;
				attach = root;
			}
			else
			{
				attach->right = node;
				attach = node;
			}
		}
		else if (is_redir_token(tokens->type))
		{
			redir_node = parse_redirection(&tokens);
			if (!redir_node)
			{
				free_ast(root);
				return (NULL);
			}
			if (!attach)
			{
				free_ast(redir_node);
				free_ast(root);
				return (NULL);
			}
			if (attach->right)
			{
				redir_node->left = attach->right;
			}
			attach->right = redir_node;
		}
		else if (tokens->type == PIPE)
		{
			if (!root || !tokens->next)
			{
				free_ast(root);
				return (NULL);
			}
			node = new_ast_node(NODE_PIPE, NULL);
			if (!node)
			{
				free_ast(root);
				return (NULL);
			}
			node->left = root;
			root = node;
			attach = node;
			tokens = tokens->next;
		}
		else
			tokens = tokens->next;
	}
	return (root);
}