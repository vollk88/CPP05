/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:01:25 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 00:28:36 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() :
_name("default_name"),
_isSigned(false),
_gradeToSign(150),
_gradeToExecute(150)
{
	cout << LGREEN_C "[Form] Default constructor called" END_C << endl;
}

Form::Form(const Form &obj) :
_name(obj._name),
_isSigned(obj._isSigned),
_gradeToSign(obj._gradeToSign),
_gradeToExecute(obj._gradeToExecute)
{
	cout << LGREEN_C "[Form] Copy constructor called" END_C << endl;
}

Form::Form(string name, int gradeToSign, int gradeToExecute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	cout << LGREEN_C "[Form] Constructor called" END_C << endl;
	try
	{
		if (gradeToExecute > MINGRADE || gradeToSign > MINGRADE)
			throw GradeTooLowException();
		else if (gradeToExecute < MAXGRADE || gradeToSign < MAXGRADE)
			throw GradeTooHighException();
	}
	catch (Form::GradeTooHighException &high)
	{
		std::cerr << high.what() << endl;
	}
	catch (Form::GradeTooLowException &low)
	{
		std::cerr << low.what() << endl;
	}
}

Form::~Form()
{
	cout << LRED_C "~[Form] Destructor called" END_C << endl;
}

const string Form::getName() const { return (this->_name); }
bool Form::isSigned() const { return (this->_isSigned); }
int Form::getGradeToSign() const { return (this->_gradeToSign); }
int Form::getGradeToExecute() const { return (this->_gradeToExecute); }

Form& Form::operator=(const Form &obj)
{
	this->_isSigned = obj._isSigned;
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->getGradeToSign()) return;
	this->_isSigned = true;
	cout << YELLOW_C "[Form] " FUXIN_C << this->getName()
	<< LGREEN_C " be signed by bureaucrat " ORNGE_C
	<< bur.getName() << END_C "." << endl;
}

std::ostream& operator<<(std::ostream &obj, Form const &f)
{
	return (
	obj << YELLOW_C "[Form] " END_C << f.getName() << ", with grade "
	<< f.getGradeToSign() << " required to be signed and grade "
	<< f.getGradeToExecute() << "it have grade:" BLBLUE_C
	<< f.isSigned() << END_C);
}
