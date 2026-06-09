#include "CinemaSystem.h"

// ================= MOVIE =================
Movie::Movie(string n, string eof, string g, double p) {
    name = n;
    Egy_or_foreig = eof;
    genre = g;
    price = p;
    countshow = 0;
}

void Movie::updateShowtimes(string time) {
    if (countshow < 10)
        showtimes[countshow++] = time;
}

void Movie::displayMovieInfo() {
    cout << "\nMovie: " << name << endl;
    cout << "Type: " << genre << endl;
    cout << "Price: " << price << endl;
}

string Movie::getName() { return name; }
double Movie::getPrice() { return price; }

// ================= SNACKBAR =================
SnackBar::SnackBar() {
    popcornPrice = 60;
    drinksPrice = 40;
}

void SnackBar::showMenu() {
    cout << "\n1. Popcorn = 60\n2. Drinks = 40\n";
}

double SnackBar::calculateBill(int p, int d) {
    return (p * popcornPrice) + (d * drinksPrice);
}

// ================= PARKING =================
double Parking::calculatePrice(int minutes) {
    if (minutes <= 0) return 0;
    return (minutes / 60.0) * 15;
}

// ================= FINANCE =================
Finance::Finance() {
    taxRate = 0.14;
}

double Finance::calculateIncome(double t, double s, double p) {
    return t + s + p;
}

double Finance::calculateTax(double total) {
    return total * taxRate;
}

double Finance::calculateNetProfit(double total) {
    return total - calculateTax(total);
}

// ================= HALL =================
Hall::Hall(int c, string t) {
    capacity = c;
    type = t;
}

void Hall::displayHallInfo() {
    cout << type << " Hall | Capacity: " << capacity << endl;
}

// ================= TICKET =================
Ticket::Ticket(Movie m, string t, int s, string h, bool w)
    : movie(m) {
    time = t;
    seatNumber = s;
    hallType = h;
    isWeekend = w;
    calculatePrice();
}

void Ticket::calculatePrice() {
    price = movie.getPrice();

    if (isWeekend) price += 50;
    if (hallType == "VIP") price += 30;
}

void Ticket::displayTicket() {
    cout << "\nMovie: " << movie.getName();
    cout << "\nTime: " << time;
    cout << "\nSeat: " << seatNumber;
    cout << "\nHall: " << hallType;
    cout << "\nPrice: " << price << endl;
}

// ================= EMPLOYEE =================
Employee::Employee(string n, string p, double s) {
    name = n;
    position = p;
    salary_per_day = s;
    daysWorked = 0;
}

void Employee::work(int d) {
    daysWorked += d;
}

double Employee::calculateSalary() {
    return daysWorked * salary_per_day;
}

void Employee::display_info() {
    cout << name << " - " << position << endl;
}

// ================= CINEMA =================
void Cinema::addMovie(Movie m) { movies.push_back(m); }
void Cinema::addHall(Hall h) { halls.push_back(h); }
void Cinema::addEmployee(Employee e) { employees.push_back(e); }

void Cinema::viewAllMovies() {
    for (auto& m : movies) m.displayMovieInfo();
}

void Cinema::displayAllEmployees() {
    for (auto& e : employees) e.display_info();
}

Movie* Cinema::findMovieByName(string name) {
    for (auto& m : movies)
        if (m.getName() == name)
            return &m;
    return nullptr;
}

SnackBar* Cinema::getSnackBar() { return &snackBar; }
Parking* Cinema::getParking() { return &parking; }
Finance* Cinema::getFinance() { return &finance; }

double Cinema::getIncome() {
    return finance.calculateIncome(1000, 500, 200);
}