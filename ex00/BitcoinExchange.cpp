/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:07:13 by asaber            #+#    #+#             */
/*   Updated: 2024/05/19 23:54:22 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bitcoin_data::bitcoin_data(std::map<std::string, float> o_databtc)
{
	this->databtc = o_databtc;	
}

bitcoin_data::bitcoin_data(const bitcoin_data& other)
{
	this->databtc = other.databtc;
}

bool ifisdigit(std::string str)
{
	for(int i = 0; i < (int)str.length(); i++)
	{
		if(!isdigit(str[i]) && str[i] != '.' && str[0] != '-')
			return false;
	}
	return true;
}
// format 2009-01-02,0
bool parse_data(std::string &date_string)
{
	int year, month, day;
	std::string s_value;
    char dash1, dash2, comma;

    std::istringstream ss(date_string);
    ss >> year >> dash1 >> month >> dash2 >> day >> comma >> s_value;
    if (dash1 != '-' || dash2 != '-' || comma != ',' || month > 12 || month <= 0 || day <= 0 || day > 31 || year <= 0 || year / 1000 < 1 || !ifisdigit(s_value))
		return false;
    return true;
}
//2011-09-14 | 390.57
bool parse_input(std::string input)
{
	int year, month, day;
    char dash1, dash2, pip;
	std::string s_value;
	
	std::istringstream ss(input);
	ss >> year >> dash1 >> month >> dash2 >> day >> pip >> s_value;
	if (dash1 != '-' || dash2 != '-' || pip != '|' || month > 12 || month <= 0 || day <= 0 || day > 31 || year <= 0 || year / 1000 < 1 || !ifisdigit(s_value))
		return false;
	else
        return true;
}

bitcoin_data::bitcoin_data()
{
	std::string line;
	std::string data;
	float value;
	size_t find;
	std::ifstream input("data.csv");
	try{
		if (!input.is_open())
			throw std::runtime_error("can't open data.csv");
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	int count = 1;
	while (getline(input, line))
	{
		if (line.find("date,exchange_rate") != std::string::npos){
			++count;
			continue;
		}
		if (!parse_data(line)){
			std::cerr << ICYAN << "this data is incorrect in line " + std::to_string(count) << RESET << std::endl;
			exit(1);
		}
		find = line.find(',');
		data = line.substr(0, find);
		try{
			value = std::stod(line.substr(find + 1));
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		set_data(data, value);	
		++count;
	}
	input.close();
}

bitcoin_data& bitcoin_data::operator=(const bitcoin_data& other)
{
	if (&other != this)
		this->databtc = other.databtc;
	return *this;
}


void	bitcoin_data::set_data(std::string data, float value)
{
	databtc.insert(std::make_pair(data, value));
}

void	bitcoin_data::print_data()
{
	std::map<std::string, float>::iterator it = databtc.begin();
	while (it != databtc.end())
	{
		std::cout << it->first << "=>" << it->second << std::endl;
		it++;
	}
}

void	set_date(int position, int curent_date, std::string &date)
{
	std::ostringstream ss;

	ss << curent_date;
	if (curent_date < 10)
		date.replace(position, 2, "0" + ss.str());
	else
		date.replace(position, 2, ss.str());
}
void decriment_date(std::string &date)
{
	int position = 8;
	std::string to_change = date.substr(position);
	int curent_date = atoi(to_change.c_str());

	if (curent_date == 1)
	{
		position = 5;
		to_change = date.substr(position, 2);
		curent_date = atoi(to_change.c_str());
		if (curent_date == 1)
		{
			to_change = date.substr(2, 2);
			curent_date = atoi(to_change.c_str());
			set_date(2, --curent_date, date);
			date.replace(position, 2, "12");
		}
		else
			set_date(position, --curent_date, date);
		date.replace(8, 2, "31");
	}
	else
		set_date(position, --curent_date, date);
}


float bitcoin_data::search_date(std::string date)
{
	std::string tmp;
	std::map<std::string, float>::iterator it;
	it = --databtc.end();
	if (std::strcmp(date.c_str(), it->first.c_str()) >= 0)
		return (it->second);
	else
		it = databtc.begin();
	
	while(std::strcmp(date.c_str(), "2009-01-02") >= 0)
	{
		while(it != databtc.end())
		{
			if (it->first == date)
				return it->second;
			it++;
		}
		decriment_date(date);
		it = databtc.begin();
	}
	return(0);
}

bool ifhasnum(std::string line)
{
	for(int i = 0; i < (int) line.size(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
			return true;
	}
	return false;
}

void	bitcoin_data::start(std::string input_file)
{
	std::ifstream input(input_file);
	std::string line;
	size_t find;
	float value;
	std::string date;
	try{
		if (!input.is_open())
			throw std::runtime_error("can't open " + input_file);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	while (getline(input, line))
	{
		if (line.find("date | value") != std::string::npos)
			continue;
		try{
			find = line.find(' ');
			if (!parse_input(line))
				throw std::runtime_error("Error: bad input => " + line);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
			continue;
		}
		date = line.substr(0, find);
		value = search_date(date);
		try{
			if (std::stod(line.substr(find + 3)) > 1000)
				throw std::runtime_error("Error: too large a number.");
			int val = std::stod(line.substr(find + 3)) * value;
			if (val < 0)
				throw std::runtime_error("Error: not a positive number.");
			std::cout << date << " => " + line.substr(find + 3) + " = " << std::stod(line.substr(find + 3)) * value << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	input.close();
}

bitcoin_data::~bitcoin_data()
{
	
}