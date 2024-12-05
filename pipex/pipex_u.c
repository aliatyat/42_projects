/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:18:17 by alalauty          #+#    #+#             */
/*   Updated: 2024/11/10 19:18:18 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char **envp)

{	
	char			*path;
	char			**cmds;

	if (!cmd || *cmd == '\0')
		return ;
	cmds = ft_split(cmd, ' ');
	if (!cmds || !*cmds || *cmds[0] == '\0')
		return (free_and_return(cmds));
	path = find_path(envp, cmds);
	if (!path)
		return (handle_path_error(cmd, cmds));
	execve(path, cmds, envp);
	ft_putstr_fd("execve error\n", 2);
	free(path);
	free_split(cmds);
	exit(EXIT_FAILURE);
}

void	child_process(char *cmd, int input_fd, int output_fd, char **envp)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		close(input_fd);
		close(output_fd);
		exit(EXIT_FAILURE);
	}
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		close(input_fd);
		close(output_fd);
		exit(EXIT_FAILURE);
	}
	close(input_fd);
	close(output_fd);
	execute_command(cmd, envp);
}

int	open_files(int argc, char **argv, int *fd_in, int *fd_out)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (EXIT_FAILURE);
	}
	*fd_in = open(argv[1], O_RDONLY);
	if (*fd_in == -1)
	{
		perror ("");
	}
	if (access(argv[argc - 1], W_OK) == -1 && access(argv[argc - 1], F_OK) == 0)
	{
		perror("");
	}
	*fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out == -1)
	{
		ft_putstr_fd("File open error\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	launch_first_child(char *cmd, int fds[2], int pipe_fd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (fds[1] != -1)
			close(fds[1]);
		close(pipe_fd[0]);
		child_process(cmd, fds[0], pipe_fd[1], envp);
	}
	if (fds[0] != -1)
		close(fds[0]);
}

void	launch_second_child(char *cmd, int pipe_fd[2], int fd_out, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipe_fd[1]);
		child_process(cmd, pipe_fd[0], fd_out, envp);
	}
}
