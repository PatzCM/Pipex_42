#include "pipex.h"

int	parsing(char **argv, int fd[2]);

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	
	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (-1);
	}
	else
	{
		if (parsing(argv, fd) == -1)
			return (-1);
		fd[0] = open(argv[1], O_RDONLY);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		processing(argv[3], fd, envp);
	}
}
void	processing(char *command, int fd[2], char **envp);
{
	char	*path_cmd;

	path_cmd = get_path(command, envp);
	if (path_cmd == NULL)
	{
		ft_putstr_fd("Error: Command not found\n", 2);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error: Fork failed\n", 2);
		exit(1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(path_cmd, NULL, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execve(path_cmd, NULL, envp);
}

char	*get_path(char *cmd ,char **envp)
{
	char	**path;
	char	*path_cmd;
	char	*tmp;
	int		i;

	i = 0;
	while (!ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		path_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_cmd, F_OK) == 0)
		{
			free(path);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
}

int	parsing(char **argv, int fd[2])
{
	if (access(argv[4], F_OK) == -1)
	{
		ft_putstr_fd("Error: File does not exist\n", 2);
		return (-1);
	}
	if (access(argv[4], W_OK) == -1)
	{
		ft_putstr_fd("Error: File is not writable\n", 2);
		return (-1);
	}
	return (0);
}
