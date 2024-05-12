/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:40:03 by asaber            #+#    #+#             */
/*   Updated: 2024/05/08 23:56:57 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


void calculat(std::stack<double> &RNP, char operation)
{
	double b = RNP.top();
	RNP.pop();
	double a = RNP.top();
	RNP.pop();
	switch (operation)
	{
	case '+':
		RNP.push(a + b);
		break;
	case '*':
		RNP.push(a * b);
		break;
	case '-':
		RNP.push(a - b);
		break;
	case '/':
		RNP.push(a / b);
		break;
	}
}

void	Start_RPN(std::string input)
{
	std::stack<double> RNP;
	for(size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue;
		if (isdigit(input[i]))
		{
			double nbr = input[i] - '0';
			RNP.push(nbr);
		}
		else if (input[i] == '+' && RNP.size() == 2)
			calculat(RNP, input[i]);
		else if (input[i] == '*' && RNP.size() == 2)
			calculat(RNP, input[i]);
		else if (input[i] == '-' && RNP.size() == 2)
			calculat(RNP, input[i]);
		else if (input[i] == '/' && RNP.size() == 2)
			calculat(RNP, input[i]);
		else
		{
			if (input[i] != '/' && input[i] != '+' && input[i] != '*' && input[i] != '-')
				std::cout << "Error" << std::endl;
			else	
				std::cout << "resault is: 0" << std::endl;
			return;
		}
	}
	if (RNP.size() == 1)
	{
		std::cout << "resualt is: " << RNP.top() << std::endl;
		RNP.pop();
	}
	else
		std::cout << "bad input " << std::endl;
}