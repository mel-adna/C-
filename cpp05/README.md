# C++ Module 05 - Repetition and Exceptions

## Overview
This module introduces **exception handling** and **abstract classes** in C++. The project simulates a bureaucratic system with forms, bureaucrats, and interns, demonstrating key OOP concepts like inheritance, polymorphism, and exception safety.

## Project Structure
```
cpp05/
├── ex00/  # Basic Bureaucrat class with exceptions
├── ex01/  # Form class and signing mechanism
├── ex02/  # Abstract forms with concrete implementations
└── ex03/  # Intern class with form factory pattern
```

---

## Exercise 00: Bureaucrat Class

### 🎯 **Objective**
Create a `Bureaucrat` class that represents a government employee with a name and grade, implementing proper exception handling for invalid grades.

### 📋 **Class Design: Bureaucrat**

#### **Attributes**
- `const std::string name` - Bureaucrat's immutable name
- `int grade` - Grade from 1 (highest) to 150 (lowest)

#### **Key Methods**
- `getName()` / `getGrade()` - Accessors
- `incrementGrade()` - Decreases grade number (improves rank)
- `decrementGrade()` - Increases grade number (worsens rank)

#### **Exception Classes**
```cpp
class GradeTooHighException : public std::exception
class GradeTooLowException : public std::exception
```

#### **Grade Logic** 🔢
- **Grade 1** = Highest authority
- **Grade 150** = Lowest authority
- **Increment** = Grade 3 → Grade 2 (promotion)
- **Decrement** = Grade 3 → Grade 4 (demotion)

### 🧪 **Testing**
- ✅ Valid grade creation (1-150)
- ✅ Invalid grade exceptions (0, 151)
- ✅ Grade increment/decrement boundaries
- ✅ Exception catching with try/catch blocks

---

## Exercise 01: Form Class

### 🎯 **Objective**
Extend the bureaucratic system with forms that can be signed by bureaucrats based on grade requirements.

### 📋 **Class Design: Form**

#### **Attributes**
- `const std::string name` - Form identifier
- `bool isSigned` - Signing status (default: false)
- `const int gradeToSign` - Minimum grade required to sign
- `const int gradeToExecute` - Minimum grade required to execute

#### **Key Methods**
- `beSigned(const Bureaucrat& b)` - Attempts to sign the form
- `getters` for all attributes
- Overloaded `<<` operator for form information display

#### **Interaction with Bureaucrat**
- `Bureaucrat::signForm(Form& form)` - Attempts to sign with error handling

### 🔄 **Signing Process**
1. Bureaucrat calls `signForm()`
2. Form's `beSigned()` checks grade requirement
3. Success: Form marked as signed + success message
4. Failure: Exception thrown + error message displayed

### 🧪 **Testing**
- ✅ Valid form creation with grade requirements
- ✅ Successful signing (sufficient grade)
- ✅ Failed signing (insufficient grade)
- ✅ Invalid form grade exceptions

---

## Exercise 02: Abstract Forms

### 🎯 **Objective**
Transform the Form class into an abstract base class and implement three concrete form types with actual execution functionality.

### 📋 **Class Design: AForm (Abstract Base)**

#### **Key Changes**
- Made class **abstract** with pure virtual `execute()` method
- Added execution validation in base class
- Renamed from `Form` to `AForm`

#### **Execution Requirements**
```cpp
virtual void execute(Bureaucrat const & executor) const = 0;
```
- Form must be **signed**
- Executor must have **sufficient grade**

### 📋 **Concrete Form Classes**

#### **1. ShrubberyCreationForm**
- **Sign Grade:** 145 | **Execute Grade:** 137
- **Functionality:** Creates `<target>_shrubbery` file with ASCII trees
- **File Output:** Beautiful ASCII art trees written to filesystem

#### **2. RobotomyRequestForm**
- **Sign Grade:** 72 | **Execute Grade:** 45
- **Functionality:** 50% chance robotomy success/failure
- **Random Element:** Uses `std::rand()` for realistic unpredictability

#### **3. PresidentialPardonForm**
- **Sign Grade:** 25 | **Execute Grade:** 5
- **Functionality:** Presidential pardon message
- **Reference:** "Zaphod Beeblebrox" (Hitchhiker's Guide to the Galaxy)

### 🔄 **Execution Process**
1. `Bureaucrat::executeForm()` calls `AForm::execute()`
2. Base class validates signing status and grade
3. Concrete class performs specific action
4. Success/failure messages displayed

### 🧪 **Testing**
- ✅ Abstract class cannot be instantiated
- ✅ Concrete forms execute properly
- ✅ File creation (ShrubberyCreationForm)
- ✅ Random behavior (RobotomyRequestForm)
- ✅ Execution validation (signed + grade requirements)

---

## Exercise 03: Intern Class

### 🎯 **Objective**
Implement a factory pattern where interns can create forms by name, avoiding messy if/else chains.

### 📋 **Class Design: Intern**

#### **Key Method**
```cpp
AForm* makeForm(const std::string& formName, const std::string& target);
```

#### **Factory Pattern Implementation**
- **Function pointers** array for form creators
- **String array** for form name matching
- **Clean, scalable** design avoiding if/else chains

#### **Supported Form Names**
- `"shrubbery creation"` → ShrubberyCreationForm
- `"robotomy request"` → RobotomyRequestForm  
- `"presidential pardon"` → PresidentialPardonForm

### 🔄 **Form Creation Process**
1. Intern receives form name and target
2. Searches through supported form names
3. Calls appropriate creator function
4. Returns pointer to new form (or NULL if invalid)

### 🧪 **Testing**
- ✅ Valid form creation by name
- ✅ Invalid form name handling
- ✅ Memory management (caller must delete)
- ✅ Multiple intern instances work independently

---

## 🏗️ **Design Patterns Used**

### **1. Exception Handling Pattern**
- Custom exception classes inheriting from `std::exception`
- RAII-safe exception propagation
- Meaningful error messages

### **2. Template Method Pattern**
- `AForm::execute()` defines execution algorithm
- Concrete classes implement specific behaviors
- Validation logic centralized in base class

### **3. Factory Pattern**
- `Intern::makeForm()` creates objects by string identifier
- Eliminates client knowledge of concrete classes
- Extensible design for new form types

### **4. Orthodox Canonical Form**
- All classes follow the "Rule of Three"
- Proper copy constructor, assignment operator, destructor
- Exception classes exempt from this requirement

---

## 🔧 **Technical Implementation Details**

### **Memory Management**
- No memory leaks in any exercise
- Proper cleanup in destructors
- Dynamic allocation only in Intern class

### **Const Correctness**
- Const member variables for immutable data
- Const methods for read-only operations
- Const parameters where appropriate

### **Exception Safety**
- Strong exception safety guarantee
- No resource leaks during exception propagation
- Proper exception specifications (`throw()`)

### **Polymorphism**
- Virtual destructors in base classes
- Pure virtual methods for abstract interfaces
- Runtime type resolution for form execution

---

## 🚀 **Compilation & Usage**

### **Build Commands**
```bash
# Each exercise has its own Makefile
cd ex00 && make    # Creates 'bureaucrat' executable
cd ex01 && make    # Creates 'bureaucrat' executable  
cd ex02 && make    # Creates 'ex02' executable
cd ex03 && make    # Creates 'ex03' executable
```

### **Compiler Flags**
- `-Wall -Wextra -Werror` - All warnings as errors
- `-std=c++98` - C++98 standard compliance
- Clean compilation with no warnings

### **Testing**
Each exercise includes comprehensive test cases demonstrating:
- Normal operations
- Error conditions
- Boundary cases
- Exception handling

---

## 📝 **Learning Outcomes**

### **Exception Handling**
- ✅ Custom exception classes
- ✅ Exception safety principles
- ✅ try/catch block usage
- ✅ Resource management during exceptions

### **Object-Oriented Design**
- ✅ Abstract base classes
- ✅ Virtual methods and polymorphism
- ✅ Inheritance hierarchies
- ✅ Interface segregation

### **Design Patterns**
- ✅ Factory pattern implementation
- ✅ Template method pattern
- ✅ Exception handling patterns
- ✅ RAII principles

### **C++98 Best Practices**
- ✅ Orthodox Canonical Form
- ✅ Const correctness
- ✅ Memory management
- ✅ Standard library usage

---

## 🎓 **Evaluation Points**

### **Code Quality**
- Clean, readable implementation
- Proper naming conventions
- Consistent coding style
- Well-documented functionality

### **Functionality**
- All requirements implemented correctly
- Comprehensive error handling
- Proper file operations
- Random behavior implementation

### **Design**
- Appropriate use of inheritance
- Clean factory pattern implementation
- Proper abstraction levels
- Extensible architecture

### **Testing**
- Thorough test coverage
- Edge case handling
- Clear demonstration of features
- Proper cleanup and resource management

This implementation demonstrates mastery of C++ exception handling, object-oriented design principles, and design patterns while maintaining clean, maintainable code that follows C++98 standards.