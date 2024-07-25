#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	void gradeChecker(int grade);
	std::string getName() const;
	int	getGrade() const;
	void upGrade();
	void downGrade();
	void signForm(Form &form);
	/////////////////////////////////////////////////////
	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(const char *error);
		virtual const char* what() const throw() {
			return this->_error;
		}
	private:
		const char *_error;
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too low!";
		}
	};

private:

	std::string	_name;
	int			_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif