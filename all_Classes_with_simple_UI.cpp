#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Movie {
private:
    string name;
    string Egy_or_foreig;
    string genre;
    double price;
    string showtimes[10];
    int countshow;
public:
    Movie(string n, string eof, string g, double p) {
        name = n;
        Egy_or_foreig = eof;
        genre = g;
        price = p;
        countshow = 0;
    }
    void updateShowtimes(string time) {
        if (countshow < 10) {
            showtimes[countshow] = time;
            countshow++;
        }
    }
    void displayMovieInfo() {
        cout << "\nmovie name: " << name << endl;
        cout << "The movie is Egyption or foreigen: " << Egy_or_foreig << endl;
        cout << "The Type: " << genre << endl;
        cout << "The price: " << price << endl;
        cout << "showtimes for this movie: ";
        for (int h = 0;h < countshow;h++) {
            cout << showtimes[h] << "  " << endl;
        }
    }
    string getEgy_or_foreig() {
        return Egy_or_foreig;
    }
    string gettype() {
        return genre;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }

};

class Hall {
public:
    int capacity;
    string type;
    Hall(int c, string t);
    void displayHallInfo();
};

class Employee {
public:
    string name;
};

class SnackBar {
public:

    void showMenu() {
        cout << "\n--- Snack Menu ---\n";
        cout << "1- Popcorn: 60 EGP\n";
        cout << "2- Drinks: 40 EGP\n";
    }

    double calculateBill(int popcorn, int drinks) {
        return popcorn * 60 + drinks * 40;
    }
};

class Parking {
public:
    double calculatePrice(int minutes) {
        return (minutes / 60.0) * 15;
    }
};

class Finance {
public:
    double calculateIncome(double t, double s, double p) {
        return t + s + p;
    }
};



class Cinema {
private:
    vector<Movie> movies; 
    vector<Hall> halls; 
    vector<Employee> employees;
    //Finance finance; 

    SnackBar snackBar;
    Parking parking;    
    Finance finance;
public:
    void addMovie(Movie m) {
        movies.push_back(m);
    }

    SnackBar* getSnackBar(){
        return &snackBar;
    }
    Parking* getParking(){ 
        return &parking;
    }
    Finance* getFinance(){ 
        return &finance;
    }

    void viewAllMovies() {
        for (size_t i = 0; i < movies.size(); i++){
            movies[i].displayMovieInfo();
        }
    }
    void removemovie(string name) {
        for (size_t i = 0; i < movies.size(); i++) {
            if (movies[i].getName() == name) {
                movies.erase(movies.begin() + i);
                break;
            }
        }
    }
    void addHall(Hall h) { 
        halls.push_back(h);
    }
    //void viewIncome() {    
        //double tickitIncome=5000; 
        //double snackIncome=2000;
        //double parkingIncome=1000;
        //double total=bookTicket+orderSnacks+useParking; 
    //    cout << "total income: " << total << endl; 
        //cout<<"total income: "<<calculateIncome(); 
    //}
    double getIncome() {
        return finance.calculateIncome(1000, 500, 200); 
    }
    void manageEmployees() { 
        int choice;
        cout<<"\n ====Employee Managment====\n";
        cout<<"1-Add employee\n";
        cout<< "2-Showing employee\n";
        cout <<"3-calculate salary to employee";
        cout<<"0-exit\n";
        cin>>choice;
        if(choice == 1){
            cout<<"Employee added successfully\n";
        }
        else if(choice == 2) {
            cout<<"Displaying employees\n";
        }
        else if(choice == 3) {
            cout<<"Salary calculated\n";
        }

    }
    void displayAllEmployees() {
    cout << "Employees list...\n";
    }
    Movie* findMovieByName(string name) {
    for  (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].getName() == name) {
            return &movies[i];
        }
    }
    return nullptr;
    }

};

class Ticket {
private:
    Movie movie;     
    string time;
    double price;
    int seatNumber;
    string hallType;    
    //    Hall hallType; 
    bool isWeekend;

public:

    Ticket(Movie m, string t, int seat, string hall, bool weekend) : movie(m){
    time=t;
    seatNumber=seat;
    hallType=hall;
    isWeekend=weekend;
    calculatePrice();
    }
    void calculatePrice() {
        price=movie.getPrice();   
        if(isWeekend){
            price=price+50;
        }
        if(hallType == "VIP") {
            price= price+30;
        }
    }
    void displayTicket() {
        cout<<"\n=== Ticket ===\n";
        cout<<"Movie: "<< movie.getName()<<endl; 
        cout<<"Time: "<<time<<endl;
        cout<<"Seat: "<< seatNumber<<endl;
        cout<<"Hall: "<<hallType<<endl;
        cout<<"Price: " <<price<<" EGP\n";
    }
};

class Customer {
private:
    string name;
    string customer_id;
    vector<Ticket*> tickets;
    vector<string> snack_orders;
public:
    Customer(string n, string id) : name(n), customer_id(id) {}
    void add_ticket(Ticket* t);
    void add_snack_order(const string& order);
    void display_info() const;
    string getName() const { return name; }
};
void Customer::add_ticket(Ticket* t) {
    if (t) tickets.push_back(t);
}
void Customer::add_snack_order(const string& order) {
    snack_orders.push_back(order);
}
void Customer::display_info() const {
    cout << " Customer: " << name << " | ID: " << customer_id << endl;
    cout << "   Number of tickets: " << tickets.size() << endl;
    cout << "   Number of snack orders: " << snack_orders.size() << endl;
}

class UserActions {
private:
    Customer* customer;
    Cinema* cinema;
public:
    UserActions(Customer* cust, Cinema* cin) : customer(cust), cinema(cin) {}
    void showMovies() const;
    Ticket* bookTicket(const string& movie_name, const string& showtime, const string& hall_type = "Normal");
    void orderSnacks();
    double useParking(int minutes);
};
void UserActions::showMovies() const {
    cout << "\nWelcome " << customer->getName() << "! Here are the currently available movies:" << endl;
    if (cinema) {
        cinema->viewAllMovies();
    }
}
Ticket* UserActions::bookTicket(const string& movie_name, const string& showtime, const string& hall_type) {
    if (!cinema) return nullptr;
    Movie* movie = cinema->findMovieByName(movie_name);
    if (!movie) {
        cout << " Movie '" << movie_name << "' not found!" << endl;
        return nullptr;
    }
    Ticket* ticket = new Ticket(*movie, showtime, 5, hall_type, false);
    customer->add_ticket(ticket);
    cout << "Ticket booked successfully!" << endl;
    ticket->displayTicket();
    return ticket;
}
void UserActions::orderSnacks() {
 if (cinema && cinema->getSnackBar()) {
//        cinema->getSnackBar()->showMenu();
        cout << " " << customer->getName() << " ordered snacks" << endl;
        double bill = cinema->getSnackBar()->calculateBill(2, 1);
        cout << " Snacks bill: " << bill << " EGP" << endl;
    }
    else {
        cout << " Snack Bar is currently unavailable" << endl;
    }
}
double UserActions::useParking(int minutes) {
    if (cinema && cinema->getParking()) {
        double price = cinema->getParking()->calculatePrice(minutes);
        cout << " Parking fee for " << minutes << " minutes: " << price << " EGP" << endl;
        return price;
    }
    else {
        cout << "Parking service is unavailable" << endl;
        return 0.0;
    }
}

class User {
protected:
    string name;
    string user_id;
public:
    User(string n, string id) : name(n), user_id(id) {}
    virtual void display_info() const = 0;
};

class Owner : public User {
private:
    Cinema* cinema;
public:
    Owner(string n, string id, Cinema* c) : User(n, id), cinema(c) {}
    void addMovie(Movie* movie);
    void viewIncome() const;
    void manageEmployees() const;
    void display_info() const override;
};
void Owner::addMovie(Movie* movie) {
    if (cinema) {
        cinema->addMovie(*movie);
        cout << "Movie '" << movie->getName() << "' has been successfully added by " << name << endl;
    }
}
void Owner::viewIncome() const {
    if (cinema && cinema->getFinance()) {
        double income = cinema->getFinance()->calculateIncome(1000, 500, 200); 
        cout << "Total Income: " << income << " EGP" << endl;
    }
    else {
        cout << "Finance system error" << endl;
    }
}
void Owner::manageEmployees() const {
    cout << "\nEmployee Management (by " << name << "):" << endl;
    if (cinema) {
        cinema->displayAllEmployees();
    }
}
void Owner::display_info() const {
    cout << " Owner: " << name << " | ID: " << user_id << endl;
};


class Screen {
private:
    string type; 
public:
    Screen(string t) {
        type = t;
    }
    string getType() {
        return type;
    }

    void displayScreenInfo() {
        cout<<"Screen Type: " <<type<<endl;
    }
};

class Salary {
private:
    int daysWorked;
    double dailyRate;
    double total;
public:
    Salary(int days,double rate){
        daysWorked=days;
        dailyRate=rate;
        total=0;
    }
    void calculateSalary(){
        total=daysWorked*dailyRate;
    }
    void displaySalary(){
        cout<<"\n===Salary===\n";
        cout<<"days worked: "<<daysWorked<<endl;
        cout<<"daily rate: "<<dailyRate<<endl;
        cout<<"total Salary: "<<total<<endl;
    }

};

class Floor {
protected:
    int floorNumber;
    vector<Hall> halls;

public:
    Floor(int n) {
        floorNumber = n;
    }

    void addHall(Hall h) {
        halls.push_back(h);
    }

    virtual void displayFloorInfo() {
        cout << "Floor: " << floorNumber << endl;
    }
};

class FirstFloor : public Floor {
public:
    FirstFloor() : Floor(1) {}

    void displayFloorInfo() {
        cout << "First Floor (Small halls + Snacks)\n";
    }
};

class SecondFloor : public Floor {
public:
    SecondFloor() : Floor(2) {}

    void displayFloorInfo() {
        cout << "Second Floor (VIP halls)\n";
    }
};

class ThirdFloor : public Floor {
public:
    ThirdFloor() : Floor(3) {}

    void displayFloorInfo() {
        cout << "Third Floor (Kids area + Restaurant)\n";
    }
};


// ================= UI =================
class UI {
public:

    int mainMenu() {
        int choice;
        cout << "\n=== MAIN MENU ===\n";
        cout << "1- Owner\n";
        cout << "2- User\n";
        cout << "0- Exit\n";
        cout << "Choose: ";
        cin >> choice;
        return choice;
    }

    int ownerMenu() {
        int choice;
        cout << "\n=== OWNER MENU ===\n";
        cout << "1- View Movies\n";
        cout << "2- Add Movie\n";
        cout << "3- View Income\n";
        cout << "0- Back\n";
        cout << "Choose: ";
        cin >> choice;
        return choice;
    }

    int userMenu() {
        int choice;
        cout << "\n=== USER MENU ===\n";
        cout << "1- Show Movies\n";
        cout << "2- Book Ticket\n";
        cout << "3- Order Snacks\n";
        cout << "4- Parking\n";
        cout << "0- Back\n";
        cout << "Choose: ";
        cin >> choice;
        return choice;
    }
};

int main() {

    Cinema cinema;
    UI ui;

    // 🎬 بيانات مبدئية
    cinema.addMovie(Movie("Avengers", "Foreign", "Action", 150));
    cinema.addMovie(Movie("Titanic", "Foreign", "Romance", 120));

    Customer c("Hamza", "001");
    UserActions user(&c, &cinema);
    Owner owner("Admin", "999", &cinema);

    while (true) {

        int choice = ui.mainMenu();

        // 👑 OWNER
        if (choice == 1) {
            while (true) {
                int op = ui.ownerMenu();

                if (op == 1) {
                    cinema.viewAllMovies();
                }
                else if (op == 2) {
                    string name, type, genre;
                    double price;

                    cout << "Movie name: ";
                    cin >> name;
                    cout << "Type (Egyptian/Foreign): ";
                    cin >> type;
                    cout << "Genre: ";
                    cin >> genre;
                    cout << "Price: ";
                    cin >> price;

                    owner.addMovie(new Movie(name, type, genre, price));
                }
                else if (op == 3) {
                    owner.viewIncome();
                }
                else break;
            }
        }

        // 👤 USER
        else if (choice == 2) {
            while (true) {
                int op = ui.userMenu();

                if (op == 1) {
                    user.showMovies();
                }
                else if (op == 2) {
                    string movie, time, hall;

                    cout << "Movie name: ";
                    cin >> movie;
                    cout << "Time: ";
                    cin >> time;
                    cout << "Hall (VIP/Normal): ";
                    cin >> hall;

                    user.bookTicket(movie, time, hall);
                }
                else if (op == 3) {
                    user.orderSnacks();
                }
                else if (op == 4) {
                    int mins;
                    cout << "Enter minutes: ";
                    cin >> mins;
                    cout << "Parking cost: "
                         << user.useParking(mins) << " EGP\n";
                }
                else break;
            }
        }

        else if (choice == 0) {
            cout << "Goodbye 👋\n";
            break;
        }
    }

    return 0;
}