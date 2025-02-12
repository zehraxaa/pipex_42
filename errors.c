/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:54 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/02/12 16:51:28 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_126(void)
{
	ft_putstr_fd("\e[35mpermission denied\n\e[0m", 2);
	exit(126);
}

void	error_1(void)
{
	ft_putstr_fd("\e[35mNo such file or directory\n\e[0m", 2);
	exit(1);
}

void	error_argc(void)
{
	ft_putstr_fd("\e[35mWrong number of argumnets\n\e[0m", 2);
	exit(2);
}

void	error_fork(void)
{
	ft_putstr_fd("\e[35mError while creating fork\n\e[0m", 2);
	exit(2);
}
