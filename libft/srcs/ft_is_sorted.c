int ft_is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
