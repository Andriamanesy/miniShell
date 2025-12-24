/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:54 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "./minishell.h"

int		make_env(t_data *data, char **env);
bool	make_env2(t_data *data);

char	*get_elem_env(t_mlist *env, char *key);
int		exist_in_env(char *line, int *i, t_data *data);

int		ft_env(t_mlist *env);
int		ft_export(char **str, t_mlist **env);
bool	export(char *str, t_mlist **env);
int		ft_unset(char **str, t_mlist **env);

char	**lst_to_arr(t_mlist *env);
void	sort_array(char **arr, int len);

#endif

