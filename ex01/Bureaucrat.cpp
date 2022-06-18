/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:43:39 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 00:25:49 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Bur"), _grade(75)
{
	std::cout << GRAY_C "[Bureaucrat] Default Constructor called" END_C << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	std::cout << "[Bureaucrat] Set Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(string const name, int grade) : _name(name)
{
	std::cout << YELLOW_C "[Bureaucrat] Constructor called" END_C << std::endl;
	try
	{
		if (grade < MAXGRADE) throw Bureaucrat::GradeTooHighException();
		else if (grade > MINGRADE) throw Bureaucrat::GradeTooLowException();
		else this->_grade = grade;
	}
	catch (GradeTooHighException &high)
	{
		this->_grade = MAXGRADE;
		std::cerr << high.what() << endl;
	}
	catch (Bureaucrat::GradeTooLowException &low)
	{
		this->_grade = MINGRADE;
		std::cerr << low.what() << endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << LRED_C "~[Bureaucrat] Destructor called"  END_C << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	return (*this);
}

string Bureaucrat::getName() const { return (this->_name); }


void Bureaucrat::addGrade()
{
	try
	{
		if (this->_grade - 1 < MAXGRADE) throw Bureaucrat::GradeTooHighException();
		else this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &high)
	{
		std::cerr << high.what() << endl;
	}
}

void Bureaucrat::removeGrade()
{
	try
	{
		if (this->_grade + 1 > MINGRADE) throw Bureaucrat::GradeTooLowException();
		else this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &low)
	{
		std::cerr << low.what() << endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	if (this->getGrade() < form.getGradeToSign())
		cout << this->getName() << " signed " << form.getName() << endl;
	else
		cout << ORNGE_C << this->getName() << LRED_C " couldn’t sign "
		<< form.getName() << " because Bureaucrat is not grow up((" END_C << endl;
	form.beSigned(*this);
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}
