/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:31:17 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/02/12 16:50:08 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h>

void	error_126(void);
void	error_1(void);
void	error_argc(void);
void	error_fork(void);
void	ft_free(char **tab);
char	*my_getenv(char *name, char **env);
char	*find_path(char *cmd, char **env);
void	execute(char *cmd, char **env);
void	child_process(char **av, int *p_fd, char **env);
void	parent_process(char **av, int *p_fd, char **env);

#endif
