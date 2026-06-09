#include "CinemaSystem.h"

int main() {
    Cinema c;

    c.addMovie(Movie("Avengers", "Foreign", "Action", 150));
    c.addMovie(Movie("El Hareefa", "Egyptian", "Comedy", 120));

    c.addEmployee(Employee("Ali", "Manager", 700));
    c.addEmployee(Employee("Sara", "Cashier", 500));

    cout << "=== Movies ===\n";
    c.viewAllMovies();

    cout << "\n=== Employees ===\n";
    c.displayAllEmployees();

    Ticket t(*c.findMovieByName("Avengers"), "7 PM", 5, "VIP", true);
    t.displayTicket();

    cout << "\nSnack = " << c.getSnackBar()->calculateBill(2, 1);
    cout << "\nParking = " << c.getParking()->calculatePrice(120);
    cout << "\nIncome = " << c.getIncome();

    return 0;
}