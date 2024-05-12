/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:28:28 by asaber            #+#    #+#             */
/*   Updated: 2024/05/09 21:26:35 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac >= 2)
		Pmergeme list(ac, av);
	else
		std::cout << ALERT << "bad input !!" << RESET << std::endl;
}