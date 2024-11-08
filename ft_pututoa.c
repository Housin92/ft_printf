/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:31:07 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 13:44:33 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_intlenght(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	ft_pututoa(unsigned int n)
{
	char	*str;
	int		lenght;
	int		result;

	result = 0;
	lenght = ft_intlenght(n);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (0);
	str[lenght--] = '\0';
	while (n != 0)
	{
		str[lenght--] = (n % 10) + 48;
		n = n / 10;
	}
	result = ft_putstr(str);
	free(str);
	return (result);
}
