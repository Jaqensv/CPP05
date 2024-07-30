#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

# include "Form.hpp"

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	virtual void execute(Bureaucrat const &executor) const;
	virtual void execution(Bureaucrat const &executor) const;

};

#endif