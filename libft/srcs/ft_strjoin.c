/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:44:32 by briandri          #+#    #+#             */
/*   Updated: 2025/03/09 12:26:14 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cst_1;
	char	*cst_2;
	char	*new_str;
	int		i;
	int		j;

	cst_1 = (char *)s1;
	cst_2 = (char *)s2;
	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(cst_1) + ft_strlen(cst_2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (cst_1[i])
		new_str[j++] = cst_1[i++];
	i = 0;
	while (cst_2[i])
		new_str[j++] = cst_2[i++];
	new_str[j] = '\0';
	return (new_str);
}
