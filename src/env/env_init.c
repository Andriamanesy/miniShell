/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:48 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 13:09:42 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"

t_env   *env_to_list(char **envp)
{
	t_env	*head;
	t_env	*tmp;
	char	*eq;
	int		i;

	head = NULL;
	tmp = NULL;
	i = 0;

	while (envp[i])
	{
		eq = ft_strchr(envp[i], '=');
		if (!eq)
			continue;
		tmp = malloc(sizeof(t_env));
		tmp->key = ft_substr(envp[i], 0, eq - envp[i]);
		tmp->value = ft_strdup(eq + 1);
		tmp->next = head;
		head = tmp;
		i++;
	}
	return head;
}

char    **list_to_envp(t_env *env)
{
   int		count;
   t_env	*tmp;
   int		i;
   char		**envp;
   char		*tmp2;

   count = 0;
   tmp = env;
   i = 0;
   while (tmp)
   {
		count++;
		tmp = tmp->next;
   }
   envp = malloc(sizeof(char *) * (count + 1));
   while (tmp)
   {
	   envp[i] = ft_strjoin(tmp->key, "=");
	   tmp2 = envp[i];
	   envp[i] = ft_strjoin(envp[i], tmp->value);
	   free(tmp2);
	   i++;
	   tmp = tmp->next;
   }
   envp[i] = NULL;
   return envp;
}
