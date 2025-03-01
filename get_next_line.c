
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

char	*ft_strdup(char *c)
{
	int	i;
	char	*res;

	i = 0;
	while (c[i])
		i++;
	res = malloc(i + 1);
	i = 0;
	while (c[i])
	{
		res[i] = c[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	size;
	static int	pos;
	int	i;
	char	line[5000];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while (9)
	{
		if (pos >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
				break;
		}
		if (buffer[pos] == '\n')
		{
			line[i++] = buffer[pos++];
			break;
		}
		line[i++] = buffer[pos++];
	}
	if (i == 0 && size <= 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
/*
int	main(void)
{
	int	fd;
	char	*res;

	fd = open("./lorem.txt", O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
