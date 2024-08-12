#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "../includes/Form.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"

class Intern {

public:

	Intern();
	~Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &rhs);
	AForm* makeForm(std::string form_name, std::string target);

	class NoFormCreated : public std::exception {
	public:
		virtual ~NoFormCreated() throw();
		NoFormCreated(std::string error);
		virtual const char* what() const throw() {
			return _error.c_str();
		}
	private:
		std::string _error;
	};

};

#endif