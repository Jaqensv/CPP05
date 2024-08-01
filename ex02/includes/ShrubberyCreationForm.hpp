#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
	virtual void execute(Bureaucrat const &executor) const;
	virtual void execution(Bureaucrat const &executor) const;
	virtual void beSigned(Bureaucrat &bureaucrat);

};

#endif