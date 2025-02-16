#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	char *dest;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int buffer_read;
	static int	buffer_pos;
	int	i = 0;
	char	line[5000];
	if (fd < 0 ||  BUFFER_SIZE <= 0)
		return NULL;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_pos] == '\n')
		{
		line[i++] = buffer[buffer_pos++];
		break ;
		}
		 line[i++] = buffer[buffer_pos++];
	}
	line[i] = '\0';
	if (i == 0 && buffer_read <= 0)
		return NULL;
	return (ft_strdup(line));
}
/*
int	main(void)
{	
	char	*test;
	int fd = open("./txt.txt", O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
    printf("%s", test);
	free(test);
	test = get_next_line(fd);
	}
	close(fd);
    return (0);
}*/

