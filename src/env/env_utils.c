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

void    free_env(t_env *env)
{
    t_env *tmp;
    while (env)
    {
        tmp = env->next;
        free(env->key);
        free(env->value);
        free(env);
        env = tmp;
    }
}