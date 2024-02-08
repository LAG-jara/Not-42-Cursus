/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:02:21 by cwan              #+#    #+#             */
/*   Updated: 2024/02/08 16:15:47 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const extern char	**environ;

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*ft_findpath(char *cmdzero)
{
	char	**path;
	char	*testpath;
	int		i;

	i = 0;
	while (environ[i] && (ft_strncmp(environ[i], "PATH=", 5)))
		i++;
	if (environ[i] && !(ft_strncmp(environ[i], "PATH=", 5)))
		path = ft_split(environ[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		testpath = ft_strjoin(ft_strjoin(path[i], "/"), cmdzero);
		if (!(access(testpath, F_OK)))
			return (ft_free(path), testpath);
		free(testpath);
		i++;
	}
	return (ft_free(path), NULL);
}

int	ft_process(char *file, char *cmd, int fd, int pid)
{
	char	**cmdsplit;
	char	*cmdpath;
	int		filefd;

	cmdsplit = ft_split(cmd, ' ');
	cmdpath = ft_findpath(cmdsplit[0]);
	if (access(cmdpath, F_OK))
		return (ft_printf("command not found: %s\n", cmdsplit[0]), \
			ft_free(cmdsplit), free(cmdpath), -1);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	pipefd[2];

	if (ac != 5 || !av[0])
		return (ft_printf("Invalid argument count\n"), 0);
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		return (errno = EPERM, perror("Failed fork: "), 0);
	if (pid == 0)
	{
		close(pipefd[0]);
		ft_process(av[1], av[2], pipefd[1], pid);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		ft_process(av[4], av[3], pipefd[0], pid);
	}
	return (0);
}
