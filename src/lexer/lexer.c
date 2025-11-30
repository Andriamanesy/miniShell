/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:54 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 14:23:11 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include "../../libft/includes/libft.h"

t_token	*lexer(char *input)
{
	if (!input)
		return (NULL);
	return (tokenize(input));
}
