# cinema-management-system-cpp
A C++ console-based Cinema Management System that allows users to manage movies, book tickets, view schedules, and handle cinema operations efficiently.
# 🎬 Cinema Management System

##  Overview

The Cinema Management System is an Object-Oriented Programming (OOP) project developed using C++.

The system is designed to automate cinema operations including movie management, hall management, ticket booking, employee management, salary calculation, income tracking, parking services, and snack ordering.

The project applies important OOP concepts such as:

- Classes & Objects
- Encapsulation
- Inheritance
- Composition
- Aggregation
- Constructors
- Initializer Lists
- Dynamic Data Storage using Vectors

# Project Objectives

The system aims to solve common cinema management problems such as:

- Managing movies and showtimes
- Managing halls and seating
- Ticket booking and pricing
- Employee management
- Salary calculations
- Revenue tracking
- Parking services
- Snack ordering
- Improving customer experience

---

# Features

## Movie Management

The system allows:

- Add movies
- Remove movies
- Display movies
- Manage showtimes

### Movie Attributes

- Name
- Type (Egyptian / Foreign)
- Genre
- Ticket Price
- Showtimes
- 
## Hall Management
Supports multiple hall types:

- Normal Hall
- VIP Hall

### Hall Attributes

- Capacity
- Type

##Ticket Management

Users can:

- Select a movie
- Choose a showtime
- Choose hall type
- Generate a ticket

### Ticket Pricing Rules

Base Price = Movie Price

Additional Charges:

- +50 EGP for Weekend Booking
- +30 EGP for VIP Hall

## Employee Management

The owner can:

- Add employees
- View employees
- Manage employee information

### Employee Attributes

- Name
- Days Worked

##  Salary System

Salary is calculated based on working days.

Formula:

Salary = Days Worked × Daily Rate

##  Finance System

The finance module calculates:

- Ticket Income
- Snack Income
- Parking Income
- Total Income

Formula:

Total Income = Ticket Income + Snack Income + Parking Income

##  Snack Bar

Available items:

- Popcorn
- Drinks

Functions:

- Show Menu
- Calculate Bill

Formula:

Bill = (Popcorn × 60) + (Drinks × 40)


## Parking System

Parking fees are calculated based on time.

Formula:

Price = (Minutes / 60) × 15

## Screen Types

Supported screen types:

- 2D
- 3D
- VR

---

#  Project Structure

## Person 1 – Core System

### Classes

- Cinema
- Movie
- Ticket
- Screen

Responsibilities:

- Movie Management
- Ticket Management
- Core System Logic


## Person 2 – Cinema Structure

### Classes

- Hall
- Floor
- FirstFloor
- SecondFloor

Responsibilities:

- Hall Management
- Floor Organization
- Inheritance Implementation

---

## Person 3 – Users

### Classes

- Owner
- Employee
- Customer
- UserActions

Responsibilities:

- User Operations
- Employee Management
- Owner Features

---

## Person 4 – Services

### Classes

- SnackBar
- Parking
- Finance
- Salary
- ThirdFloor

Responsibilities:

- Financial Calculations
- Extra Services
- Salary System

---

# OOP Concepts Used

## Encapsulation

Data members are declared as private and accessed using getters.

Example:

```cpp
private:
    string name;
    double price;
```

---

## Inheritance

Example:

```cpp
class FirstFloor : public Floor
```

---

## Composition

Example:

```cpp
class Ticket {
    Movie movie;
};
```

The Ticket class contains a Movie object.

---

## Aggregation

Example:

```cpp
Cinema* cinema;
```

Used inside UserActions.

---

#  Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Console-Based Interface

---

#  Future Improvements

- Database Integration
- GUI Application
- Online Booking System
- User Authentication
- Payment Gateway
- Reports & Analytics

---

#  System Workflow

1. Owner adds movies.
2. Movies are stored in Cinema.
3. User views available movies.
4. User books a ticket.
5. Ticket price is calculated automatically.
6. User may order snacks.
7. User may use parking.
8. Finance calculates total income.

---

#  How To Run

Compile:

```bash
g++ all_Classes.cpp -o cinema
```

Run:

```bash
./cinema
```

---

#  Conclusion

The Cinema Management System is a complete simulation of cinema operations developed using C++ and Object-Oriented Programming concepts. It demonstrates the practical use of OOP principles while providing a scalable and organized solution for cinema management.

---

**Course:** Object-Oriented Programming (OOP)

**Language:** C++

**Project Type:** Academic Team Project

**Team:** Team NOSIGNAL 🚀
