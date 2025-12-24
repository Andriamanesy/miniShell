/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:43:27 by briandri          #+#    #+#             */
/*   Updated: 2025/12/23 23:21:16 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signals.h"
#include "../../include/minishell.h"

static void	handle_sigint(int code)
{
	(void)code;
	printf("\n");
	clear_rl_line();
	if (g_signal_pid == 0)
		rl_redisplay();
}

static void	handle_sigsegv(int code)
{
	(void)code;
	write(2, "Segmentation fault\n", 19);
	exit(11);
}

static void	handle_sigabrt(int code)
{
	(void)code;
	write(1, "abort\n", 6);
}

void	signals(void)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGSEGV, &handle_sigsegv);
	signal(SIGABRT, &handle_sigabrt);
	signal(SIGQUIT, SIG_IGN);
}

void	signals2(void)
{
	signal(SIGQUIT, SIG_DFL);
}