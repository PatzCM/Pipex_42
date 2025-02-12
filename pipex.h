/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:08:31 by palexand          #+#    #+#             */
/*   Updated: 2025/01/28 20:28:39 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_pipex
{
	char	**cmd;
	char	**path;
	int		fd_in;
	int		fd_out;
}	t_pipex;

// Function prototypes
int	ft_strchrlen(char *str, char c);
void	free_loop(char *s, char **cmd, char **path, int j);
void	free_path(char **path);
int	set_commands(t_pipex **pipex, char **av, char **path, int size);
int	parsing_input(t_pipex	**pipex, char **av, char **envp, int size);
void	run_command(t_pipex **pipex, int index, char **envp);

int	error_exit(t_pipex **pipex, char *error);
void	free_split(char **str);
int	redirect_process(t_pipex **pipex, char **envp);
int	second_process(t_pipex **pipex, char **envp, int *fd, pid_t *pid);
void	init_pipex(t_pipex **pipex);
#endif
