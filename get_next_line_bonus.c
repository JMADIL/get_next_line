/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:11 by ajamoun           #+#    #+#             */
/*   Updated: 2024/12/19 06:02:58 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_line(char *stored)
{
	char	*line;
	int	a;
	int	i;
	
	i = 0;
	a = -1;
	if (!stored || !stored[0])
		return (NULL);
	while (stored[i] != '\n' && stored[i] != '\0')
		i++;
	if (stored[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (++a < i)
		line[a] = stored[a];
	line[a] = '\0';
	return (line);
}

char	*clean_static(char *stored)
{
	char	*rest;
	char	*newline;

	if (!stored)
		return (NULL);
	newline = ft_strchr(stored, '\n');
	if (!newline)
	{
		free(stored);
		return (NULL);
	}
	rest = ft_strdup(newline + 1);
	if (!rest)
	{
		free(stored);
		return (NULL);
	}
	free(stored);
	return (rest);
}

char	*readfn(int fd, char *stored)
{
	char		*buffer;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!stored)
		stored = ft_strdup("");
	if(!stored)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stored), NULL);
	while (bytes_read > 0 && !ft_strchr(stored, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stored), buffer = NULL, stored = NULL, NULL);
		buffer[bytes_read] = '\0';
		stored = ft_strjoin(stored, buffer);
		if (!stored)
			return (free(buffer), NULL);
	}
	free(buffer);
	buffer = NULL;
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored[10240];
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
		return (free(stored[fd]), stored[fd] = NULL, NULL);
	stored[fd] = readfn(fd, stored[fd]);
	if (!stored[fd])
		return (free(stored[fd]), stored[fd] = NULL, NULL);
	line = find_line(stored[fd]);
	if (!line)
		return (free(stored[fd]), stored[fd] = NULL, NULL);
	stored[fd] = clean_static(stored[fd]);
	return (line);
}

// void ll()
// {
//     system("leaks -q a.out");
// }
// #include <stdio.h>
// // #include <stdio.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDWR, 0777);
// 	write (fd, "", 0);

// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
//     atexit(ll);
// }

///////

// #include <stdio.h>

// void ll()
// {
//     system("leaks -q a.out");
// }
// int main()
// {
//     char *line;
//     int fd = open("test.txt", O_RDONLY);
    
//     // //* Test case 1: Normal file reading
//     int i = 1;
//     while (i < 4)
//     {
//         line = get_next_line(fd);
//         printf("call[%d]=======NEXT=LINE=====>  :%s\n", i, line);
//         free(line);//! Don't forget to free the returned line
//         i++;
//     }
//     close(fd);
//     atexit(ll);
    
//     // //* Test case 2: EOF handling: empty file
//     // //* Test case 3: Invalid fd  : fd = -1
//     // //* Test case 4: from std in : fd = 0
//     return (0);
// }