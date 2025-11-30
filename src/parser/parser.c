/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:25 by briandri          #+#    #+#             */
/*   Updated: 2025/11/30 11:48:03 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include "stdlib.h"

t_ast	*parse(t_token *tokens)
{
	t_token	*current;
	t_ast	*root;

	if (!tokens)
		return (NULL);
	current = tokens;
	root = build_ast(current);
	return (root);
}
