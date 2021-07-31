#include "ft_printf.h"

void	skip_asterisk(char **str, va_list *arg)
{
	while (**str == '*')
	{
		va_arg(*arg, int);
		(*str)++;
	}
}

char	*filling_element_from_dot(char **str, t_format *element, va_list *arg)
{
	if (**str == '.')
	{
		element->comma_flag = 1;
		(*str)++;
		if (**str == '*')
		{
			element->accuracy = va_arg(*arg, int);
			if (element->accuracy < 0)
			{
				element->accuracy = 0;
				element->comma_flag = 0;
			}
			(*str)++;
			skip_asterisk(str, arg);
		}
		else
			element->accuracy = ft_mini_atoi(str);
	}
	skip_asterisk(str, arg);
	if (ft_strchr("0123456789-.", **str))
		*str = filling_element(str, element, arg);
	else
		element->type = *(*str)++;
	element->check_type = ft_strchr("cspdiuxX%%", element->type);
	return (*str);
}

char	*filling_element(char **str, t_format *element, va_list *arg)
{
	while (**str == '0' || **str == '-' || **str == '*')
	{
		if (**str == '0')
			element->zero_flag = 1;
		if (**str == '-')
			element->minus_flag = 1;
		if (**str == '*')
		{
			element->width = va_arg(*arg, int);
			if (element->width < 0)
			{
				element->width = element->width * -1;
				element->minus_flag = 1;
			}
		}
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
		element->width = ft_mini_atoi(str);
	if (**str == '*')
		*str = filling_element(str, element, arg);
	*str = filling_element_from_dot(str, element, arg);
	if (!element->check_type)
		element->error = 1;
	return (*str);
}

void	null_element(t_format *elem, char **str, va_list *arg)
{
	elem->check_type = NULL;
	elem->comma_flag = 0;
	elem->minus_flag = 0;
	elem->zero_flag = 0;
	elem->accuracy = 0;
	elem->width = 0;
	elem->type = 0;
	elem->error = 0;
	(*str)++;
	filling_element(str, elem, arg);
}

int	ft_printf(const char *source, ...)
{
	t_format	element;
	va_list		arg;
	char		*str;
	int			len;

	len = 0;
	str = (char *)source;
	if (str == NULL)
		return (-1);
	va_start(arg, source);
	while (*str)
	{
		if (*str == '%')
		{
			null_element(&element, &str, &arg);
			len = len + major_parser(&arg, element);
			if (len == -1 || element.error == 1)
				return (-1);
		}
		else
			if (++len)
				write(1, str++, 1);
	}
	va_end(arg);
	return (len);
}
