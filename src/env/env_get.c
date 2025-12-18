/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:44 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 12:59:39 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"
#include "../../include/env.h"
#include <string.h> // pour strcmp
#include <stdlib.h>


t_env	*get_env_node(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_env_value(t_env *env, char *key)
{
	t_env	*node;

	node = get_env_node(env, key);
	if (node)
		return (node->value);
	return (NULL);
}

char *env_get(t_env *env, const char *name)
{
    while (env)
    {
        if (strcmp(env->key, name) == 0)
            return env->value; // retourne la valeur trouvée
        env = env->next;
    }
    return NULL; // non trouvé
}


