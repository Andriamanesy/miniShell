/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:44:43 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:49:01 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_ast	*new_ast_node(t_node_type type, const char *value)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	if (value)
	{
		node->value = ft_strdup(value);
		if (!node->value)
			return (free(node), NULL);
	}
	else
		node->value = NULL;
	node->argv = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	is_redir_token(t_toktype type)
{
	return (type == REDIR_OUT || type == REDIR_OUT_APPEND
		|| type == REDIR_IN || type == HEREDOC);
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
