#ifndef CINEMASYSTEM_H
#define CINEMASYSTEM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= MOVIE =================
class Movie {
private:
    string name;
    string Egy_or_foreig;
    string genre;
    double price;
    string showtimes[10];
    int countshow;

public:
    Movie(string n, string eof, string g, double p);

    void updateShowtimes(string time);
    void displayMovieInfo();

    string getName();
    double getPrice();
};

// ================= SNACKBAR =================
class SnackBar {
private:
    double popcornPrice;
    double drinksPrice;

public:
    SnackBar();
    void showMenu();
    double calculateBill(int popQty, int drinkQty);
};

// ================= PARKING =================
class Parking {
public:
    double calculatePrice(int minutes);
};

// ================= FINANCE =================
class Finance {
private:
    double taxRate;

public:
    Finance();
    double calculateIncome(double ticketSales, double snackSales, double parkingSales);
    double calculateTax(double totalIncome);
    double calculateNetProfit(double totalIncome);
};

// ================= HALL =================
class Hall {
public:
    int capacity;
    string type;

    Hall(int c, string t);
    void displayHallInfo();
};

// ================= TICKET =================
class Ticket {
private:
    Movie movie;
    string time;
    double price;
    int seatNumber;
    string hallType;
    bool isWeekend;

public:
    Ticket(Movie m, string t, int seat, string hall, bool weekend);

    void calculatePrice();
    void displayTicket();
};

// ================= EMPLOYEE =================
class Employee {
private:
    string name;
    string position;
    int daysWorked;
    double salary_per_day;

public:
    Employee(string n, string p, double s);

    void work(int d = 1);
    double calculateSalary();
    void display_info();
};

// ================= CINEMA =================
class Cinema {
private:
    vector<Movie> movies;
    vector<Hall> halls;
    vector<Employee> employees;

    SnackBar snackBar;
    Parking parking;
    Finance finance;

public:
    void addMovie(Movie m);
    void addHall(Hall h);
    void addEmployee(Employee e);

    void viewAllMovies();
    void displayAllEmployees();
    Movie* findMovieByName(string name);

    SnackBar* getSnackBar();
    Parking* getParking();
    Finance* getFinance();

    double getIncome();
};

#endif
