# Library Management System: Object-Oriented Programming in C++

In this project, we designed a **Library Management System** using **Object-Oriented Programming (OOP)** principles in **C++**. The system manages users, books, and database connections efficiently while implementing key OOP concepts such as **inheritance**, **polymorphism**, and **design patterns**. Below are the key highlights of the project:

## Key Classes and Inheritance

The system is built around several core classes, each handling specific aspects of library management.

### User Class (Base Class)
The `User` class is the base class for all types of users in the system. It contains common attributes and methods for user management.

### Reader Class (Inherits from `User`)
The `Reader` class inherits from the `User` class and represents users who borrow books. It includes methods specific to readers, such as book borrowing and returning.

### Admin Class (Inherits from `User`)
The `Admin` class inherits from the `User` class and represents system administrators. It provides functionalities such as adding, updating, and removing books from the system.

#### Polymorphism
All three classes implement a **virtual method** called `displayInfo()`, showcasing polymorphism. This method displays user-specific information, and depending on whether the user is a **Reader** or **Admin**, different outputs are generated.

### Example of Polymorphism:

```cpp
class User {
public:
    virtual void displayInfo() = 0; // Pure virtual method
};

class Reader : public User {
public:
    void displayInfo() override {
        std::cout << "Reader: Displaying reader information" << std::endl;
    }
};

class Admin : public User {
public:
    void displayInfo() override {
        std::cout << "Admin: Displaying admin information" << std::endl;
    }
};
