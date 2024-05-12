/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:47:23 by asaber            #+#    #+#             */
/*   Updated: 2024/04/29 23:48:36 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define ALLERT "\033[1;33m"
#define RESET "\033[0m"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Start_RPN(av[1]);
	}
	else
	{
		std::cout << ALLERT << "bad passing inputs !!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}