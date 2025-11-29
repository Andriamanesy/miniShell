/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:54 by briandri          #+#    #+#             */
/*   Updated: 2025/11/29 10:40:49 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

t_env   *env_to_list(char **envp);
char    **list_to_envp(t_env *env);

void    set_env(t_env **env, char *key, char *value);
void    unset_env(t_env **env, char *key);
t_env   *get_env_node(t_env *env, char *key);
char    *get_env_value(t_env *env, char *key);

void    free_env(t_env *env);

#endif
