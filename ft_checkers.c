int	is_conversion(const char chr)
{
	char	*conversions;

	conversions = "cspdiuxX%";
	while (conversions)
		if (*conversions++ == chr)
			return (1);
	return (0);
}

int	is_flag(const char chr)
{
	char	*flags;

	flags = "-0.*";
	while (flags)
		if (chr == *flags++)
			return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c < 58) && (c > 47))
		return (1);
	return (0);
}
