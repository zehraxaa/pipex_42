/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:42:34 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/02/12 15:00:48 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_open();
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	execute(av[2], env);
}

void	parent_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_open();
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(fd);
	close(p_fd[1]);
	close(p_fd[0]);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;

	if ((pipe(fd)) == -1)
		error_pipe();
	if (ac == 5)
	{
		pid = fork();
		if (pid == -1)
			error_fork();
		if (pid == 0)
			child_process(av, fd, env);
		if (pid != 0)
			parent_process(av, fd, env);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		error_argc();
}
