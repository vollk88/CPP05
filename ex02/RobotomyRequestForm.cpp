/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 00:41:46 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 21:02:33 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
Form("Robotomy Request Default Form", 72, 45), target("You"){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) :
Form(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute()), target(obj.target) {}

RobotomyRequestForm::RobotomyRequestForm(string const &target) :
Form("Robotomy Request Default Form", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	this->target = ref.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (rand() % 2)
		cout << LGREEN_C "Successfully robotised " << this->target <<END_C << endl;
	else
		cout << LRED_C "Successfully robotised " << this->target <<END_C << endl;
}

