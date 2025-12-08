/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:54 by briandri          #+#    #+#             */
/*   Updated: 2025/12/02 09:50:37 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"
#include <stdlib.h>

t_token	*lexer(char *input)
{
	if (!input || !*input)
		return (NULL);
	return (tokenize(input));
}

