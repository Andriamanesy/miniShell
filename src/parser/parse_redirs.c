/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:16 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 11:49:39 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdlib.h>

t_ast	*parse_redirection(t_token **tokens)
{
	t_ast		*redir_node;
	t_token		*current;
	t_node_type	type;

	if (!tokens || !*tokens)
		return (NULL);
	current = *tokens;
	if (current->type == REDIR_OUT)
		type = NODE_REDIR_OUT;
	else if (current->type == REDIR_OUT_APPEND)
		type = NODE_REDIR_OUT_APPEND;
	else if (current->type == REDIR_IN)
		type = NODE_REDIR_IN;
	else if (current->type == HEREDOC)
		type = NODE_HEREDOC;
	else
		return (NULL);
	*tokens = current->next;
	if (!*tokens || (*tokens)->type != WORD)
		return (NULL);
	redir_node = new_ast_node(type, ft_strdup((*tokens)->value));
	*tokens = (*tokens)->next;
	return (redir_node);
}
