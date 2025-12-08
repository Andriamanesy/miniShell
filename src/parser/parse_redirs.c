/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:16 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:49:08 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_ast	*parse_redirection(t_token **tokens)
{
	t_ast		*redir;
	t_token		*cur;
	t_node_type	type;

	if (!tokens || !*tokens)
		return (NULL);
	cur = *tokens;
	if (cur->type == REDIR_OUT)
		type = NODE_REDIR_OUT;
	else if (cur->type == REDIR_OUT_APPEND)
		type = NODE_REDIR_OUT_APPEND;
	else if (cur->type == REDIR_IN)
		type = NODE_REDIR_IN;
	else if (cur->type == HEREDOC)
		type = NODE_HEREDOC;
	else
		return (NULL);
	cur = cur->next;
	if (!cur || cur->type != WORD)
		return (NULL);
	redir = new_ast_node(type, cur->value);
	if (!redir)
		return (NULL);
	*tokens = cur->next;
	return (redir);
}
