#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Form.hpp"

class AForm;

class Bureaucrat {

public:

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	const std::string getName() const;
	void gradeChecker(int grade);
	void gradeModifier(int modifier);
	void upGrade();
	void downGrade();
	int	getGrade() const;
	void signForm(AForm &form) const;
	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
	public:
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

private:

	const std::string	_name;
	int					_grade;

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif