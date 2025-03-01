# include <stdarg.h>
# include <unistd.h>

void put_string(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		*len += write(1, &s[i], 1);
		i++;
	}
}

void	put_digit(long int digit, int	base, int *len)
{
	if ( digit < 0)
	{
		digit = digit * -1;
		*len += write(1, "-", 1);
	}
	if (digit >= base)
		put_digit((digit/base), base, len);
	*len += write(1, & "0123456789abcdef"[digit % base], 1);
}



int	ft_printf(const char *format, ...)
{
	int	len;
	int	i;
	va_list	args;
	
	i = 0;
	va_start(args, format);
	len = 0;
	while (format[i])
	{
		if ((format[i] == '%') && ((format[i + 1] == 's') ||( format[i + 1] == 'd') || (format[i + 1] == 'x')))
		{
			i++;
			if (format[i] == 's')
				put_string(va_arg(args,char *), &len);
			else if (format[i] == 'd')
				put_digit((long int)va_arg(args, int), 10, &len);
			else if (format[i] == 'x')
				put_digit((long int)va_arg(args, unsigned int),16,  &len);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return (va_end(args), len);
}

