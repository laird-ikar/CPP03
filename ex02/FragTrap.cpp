/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:05:07 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/20 15:15:37 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/***********************
*	Constructors & Destructor
***********************/

FragTrap::FragTrap(void):ClapTrap()
{
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
	std::cout << "A new FragTrap was build." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src):ClapTrap()
{
	*this = src;
	std::cout << "A new FragTrap was build, on the model of " << src << "."
		<< std::endl;
	return ;
}

FragTrap::FragTrap(std::string name):ClapTrap()
{
	this->hp = 100;
	this->ep = 30;
	this->atk = 30;
	this->name = name;
	std::cout << "A new FragTrap was build." << std::endl;
	std::cout << "It was named " << name << "." << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << *this << " got destroyed..." << std::endl;
	return ;
}

/***********************
*	Assignation Operators
***********************/

FragTrap &	FragTrap::operator=(FragTrap const &src)
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

std::ostream	&operator<<(std::ostream &o, FragTrap const &ct)
{
	return (o << "FragTrap named " << ct.get_name());
}

/***********************
*	Getter & Setters
***********************/

/***********************
*	Methods
***********************/

void		FragTrap::highFivesGuys()
{
	std::cout << *this << " asked for a high five ! But nobody came..." << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->ep <= 0)
	{
		std::cout << "FragTrap " << this->name
			<< " don't have enough energy to attack " << target << "..."
			<< std::endl;
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "FragTrap " << this->name
			<< " is too dead to attack " << target << "..."
			<< std::endl;
		return ;
	}
	this->ep--;
	std::cout << "FragTrap " << this->name
		<< " attacks " << target << ", causing " << this->atk
		<< " points of damage!" << std::endl;
	return ;
}
