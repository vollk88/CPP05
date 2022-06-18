/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 00:41:42 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 11:48:25 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():
	Form("Presidential Pardon Default Form", 25, 5),
	target("You"){}

PresidentialPardonForm::PresidentialPardonForm
	(PresidentialPardonForm const &src):
	Form("Presidential Pardon Default Form", 25, 5),
	target(src.target){}

PresidentialPardonForm::PresidentialPardonForm(string const &target):
	Form("Presidential Pardon Default Form", 25, 5),
	target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm	&PresidentialPardonForm::operator=
	(PresidentialPardonForm const &src)
{
	this->target = src.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute() || !this->isSigned())
		throw GradeTooLowException();
	cout << this->target << " got pardoned by Zaphod Beeblebrox."
	<< endl;
}
