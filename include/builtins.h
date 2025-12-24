/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:46 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../libft/includes/libft.h"
# include "minishell.h"

int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_cd(t_data *data, char **params);
void	ft_exit(t_data *data, char **args);
int	ft_unset(char **str, t_mlist **env);

#endif
