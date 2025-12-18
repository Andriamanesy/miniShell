/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:02 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 13:09:40 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"
#include "../../include/minishell.h"
#include <stdlib.h>
#include "../../libft/includes/libft.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}


// Convertit la liste t_env en tableau char ** utilisable pour tokenize
char **env_to_array(t_env *env)
{
    int count = 0;
    t_env *tmp = env;
    char **arr;
    int i = 0;

    while (tmp)
        count++, tmp = tmp->next;

    arr = malloc(sizeof(char *) * (count + 1));
    if (!arr)
        return NULL;

    tmp = env;
    while (tmp)
    {
        arr[i] = ft_strjoin(tmp->key, "=");
        char *tmp2 = arr[i];
        arr[i] = ft_strjoin(arr[i], tmp->value);
        free(tmp2);
        i++;
        tmp = tmp->next;
    }
    arr[i] = NULL;
    return arr;
}
