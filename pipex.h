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


// Function prototypes

void	error_exit(const char *message, int number);
char	*get_command_path(char *cmd, char **envp);
void	ft_free_split(char **str);
void	run_command(char *cmd, char **envp);
void	child_process(int *fd, char **av, char **envp);
void	parent_process(int *fd, char **av, char **envp);
void	parsing_envp(char **envp);



#endif
