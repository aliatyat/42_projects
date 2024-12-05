/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:18:32 by alalauty          #+#    #+#             */
/*   Updated: 2024/11/10 19:18:35 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	free_split(char **split);
void	free_and_return(char **cmds);
void	handle_path_error(char *cmd, char **cmds);
void	execute_command(char *cmd, char **envp);
void	child_process(char *cmd, int input_fd, int output_fd, char **envp);
int		open_files(int argc, char **argv, int *fd_in, int *fd_out);
void	launch_first_child(char *cmd, int fds[2], int pipe_fd[2], char **envp);
void	launch_second_child(char *cmd, int pipe_fd[2], int fd_out, char **envp);
char	*find_path(char **env, char **cmd);

#endif
