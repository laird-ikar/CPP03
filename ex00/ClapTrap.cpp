/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:34:21 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 15:07:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/***********************
*	Constructors & Destructor
***********************/

ClapTrap::ClapTrap(void)
{
	this->hp = 10;
	this->ep = 10;
	this->atk = 0;
	std::cout << "A new ClapTrap was build." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	std::cout << "A new ClapTrap was build, on the model of " << src << "."
		<< std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	this->hp = 10;
	this->ep = 10;
	this->atk = 0;
	this->name = name;
	std::cout << "A new ClapTrap was build." << std::endl;
	std::cout << "It was named " << name << "." << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << *this << " got destroyed..." << std::endl;
	return ;
}

/***********************
*	Assignation Operators
***********************/

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
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

std::ostream	&operator<<(std::ostream &o, ClapTrap const &ct)
{
	return (o << "ClapTrap named " << ct.get_name());
}

/***********************
*	Getters & Setters
***********************/

std::string	ClapTrap::get_name(void) const
{
	return (this->name);
}

/***********************
*	Methods
***********************/

void	ClapTrap::attack(const std::string &target)
{
	if (this->ep <= 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " don't have enough energy to attack " << target << "..."
			<< std::endl;
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " is too dead to attack " << target << "..."
			<< std::endl;
		return ;
	}
	this->ep--;
	std::cout << "ClapTrap " << this->name
		<< " attacks " << target << ", causing " << this->atk
		<< " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name
		<< " got attacked for " << amount << " points of damage!"
		<< std::endl;
	if (this->hp <= 0)
		std::cout << "It has died on impact..." << std::endl;
	else
		std::cout << "It has " << this->hp << " hit points left..."
			<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep <= 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " don't have enough energy to repair itself..." << std::endl;
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " is too dead to repair itself..." << std::endl;
		return ;
	}
	this->ep--;
	this->hp += amount;
	std::cout << "ClapTrap " << this->name
		<< " repaired itself of " << amount << " points of damage! It has now "
		<< this->hp << " hit points!"
		<< std::endl;
	return ;
}
