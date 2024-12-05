/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:18:24 by alalauty          #+#    #+#             */
/*   Updated: 2024/11/10 19:18:26 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths_from_env(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

char	*find_command_path(char **paths, char **cmd)
{
	int		i;
	char	*path;
	char	*part_path;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	while (paths && paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd[0]);
		free(part_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*find_path(char **env, char **cmd)
{
	char	**paths;
	char	*full_path;
	int		i;

	paths = get_paths_from_env(env);
	if (!paths)
		return (NULL);
	full_path = find_command_path(paths, cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (full_path);
}

void	close_on_exit(int *fds, int fd_count)
{
	int	i;

	i = 0;
	while (i < fd_count)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (EXIT_FAILURE);
	}
	open_files(argc, argv, &fd_in, &fd_out);
	if (pipe(pipe_fd) == -1)
	{
		close_on_exit((int []){fd_in, fd_out}, 2);
		ft_putstr_fd("pipe error\n", 2);
		return (EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != -1)
		launch_first_child(argv[2], (int []){fd_in, fd_out}, pipe_fd, envp);
	if (fd_out != -1)
		launch_second_child(argv[3], pipe_fd, fd_out, envp);
	close_on_exit((int []){fd_in, fd_out, pipe_fd[0], pipe_fd[1]}, 4);
	wait(NULL);
	wait(NULL);
	return (0);
}
