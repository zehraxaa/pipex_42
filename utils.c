/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:33:13 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/02/12 15:04:06 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_perm(void)
{
	ft_putstr_fd("\e[35mpermission denied\n\e[0m", 2);
	exit(126);
}
void	error_not_found(void)
{
	ft_putstr_fd("\e[35mcommand not found\n\e[0m", 2);
	exit(127);
}
void	error_open(void)
{
	ft_putstr_fd("\e[35mNo such file or directory\n\e[0m", 2);
	exit(1);
}

void	error_pipe(void)
{
	ft_putstr_fd("\e[35mToo many open files\n\e[0m", 2);
	exit(1);
}

void	error_argc(void)
{
	ft_putstr_fd("\e[35mWrong number of arguments\n\e[0m", 2);
	exit(2);
}
void	error_fork(void)
{
	ft_putstr_fd("\e[35mFork error\n\e[0m", 2);
	exit(2);
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, name, 4) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free(s_cmd);
			ft_free(allpath);
			return (exec);
		}
		free(exec);
	}
	ft_free(allpath);
	ft_free(s_cmd);
	return (NULL);
}

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd || !s_cmd[0])
	{
		ft_free(s_cmd);
		error_perm();
	}
	path = find_path(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("\e[35mpipex: command not found: [0m", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free(s_cmd);
		exit(127);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		perror("execve error");
		ft_free(s_cmd);
		exit(1);
	}
}
