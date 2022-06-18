/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloki <hloki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 00:41:47 by hloki             #+#    #+#             */
/*   Updated: 2022/06/12 20:59:08 by hloki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class Bureaucrat ;

class RobotomyRequestForm : public Form
{
	private:
		string	target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		RobotomyRequestForm(string const &target);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);

		virtual void		execute(Bureaucrat const & executor) const;
};

#endif