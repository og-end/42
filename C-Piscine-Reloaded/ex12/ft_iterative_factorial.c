/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:36:21 by eahmeti           #+#    #+#             */
/*   Updated: 2024/09/24 16:45:59 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		n = nb;
		while (n > 1)
		{
			nb = nb * (n - 1);
			n--;
		}
	}
	return (nb);
}
