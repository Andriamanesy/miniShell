/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:50 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:27:11 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_operator_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}
