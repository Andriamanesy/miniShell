/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:20 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 11:48:51 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdlib.h>

t_ast	*build_command_node(t_token **tokens)
{
	t_token	*current;
	t_ast	*cmd_node;

	if (!tokens || !*tokens)
		return (NULL);
	current = *tokens;
	cmd_node = new_ast_node(NODE_COMMAND, ft_strdup(current->value));
	*tokens = current->next;
	return (cmd_node);
}
