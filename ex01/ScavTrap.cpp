/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:05:07 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 15:06:58 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/***********************
*	Constructors & Destructor
***********************/

ScavTrap::ScavTrap(void):ClapTrap()
{
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
	std::cout << "A new ScavTrap was build." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src):ClapTrap()
{
	*this = src;
	std::cout << "A new ScavTrap was build, on the model of " << src << "."
		<< std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name):ClapTrap()
{
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
	this->name = name;
	std::cout << "A new ScavTrap was build." << std::endl;
	std::cout << "It was named " << name << "." << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " got destroyed..." << std::endl;
	return ;
}

/***********************
*	Assignation Operators
***********************/

ScavTrap &	ScavTrap::operator=(ScavTrap const &src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->atk = src.atk;
	return (*this);
}

/***********************
*	Boolean Operators
***********************/

/***********************
*	Arithmetic Operators
***********************/

/***********************
*	Stream Operators
***********************/

std::ostream	&operator<<(std::ostream &o, ScavTrap const &ct)
{
	return (o << "ScavTrap named " << ct.get_name());
}

/***********************
*	Getter & Setters
***********************/

/***********************
*	Methods
***********************/

void		ScavTrap::guardGate()
{
	std::cout << *this << " entered Gate keeper mode ! *kaboom*" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->ep <= 0)
	{
		std::cout << "ScavTrap " << this->name
			<< " don't have enough energy to attack " << target << "..."
			<< std::endl;
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->name
			<< " is too dead to attack " << target << "..."
			<< std::endl;
		return ;
	}
	this->ep--;
	std::cout << "ScavTrap " << this->name
		<< " attacks " << target << ", causing " << this->atk
		<< " points of damage!" << std::endl;
	return ;
}
