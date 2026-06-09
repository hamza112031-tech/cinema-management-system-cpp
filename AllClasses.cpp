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
class SnackBar {          //person 4
private:
    double popcornPrice;
    double drinksPrice;

public:
    SnackBar() {
        popcornPrice = 60.0;
        drinksPrice = 40.0;
    }

    void showMenu() {
        cout << "\n--- No Signal Cinema SnackBar ---\n";
        cout << "1. Popcorn: " << popcornPrice << " EGP\n";
        cout << "2. Drinks:  " << drinksPrice << " EGP\n";
    }

    double calculateBill(int popQty, int drinkQty) {
        return (popQty * popcornPrice) + (drinkQty * drinksPrice);
    }
};



class Parking {              //person 4
public:
    double calculatePrice(int minutes) {
        if (minutes <= 0) return 0.0;
        return (minutes / 60.0) * 15.0;
    }
};

class Finance {               // person 4
private:
    double taxRate;

public:
    Finance() {
        taxRate = 0.14; // 14% VAT as per proposal
    }

    double calculateIncome(double ticketSales, double snackSales, double parkingSales) {
        return ticketSales + snackSales + parkingSales;
    }

    double calculateTax(double totalIncome) {
        return totalIncome * taxRate;
    }

    // Net profit after deducting taxes
    double calculateNetProfit(double totalIncome) {
        return totalIncome - calculateTax(totalIncome);
    }




};


//#include <Movie.h> //Me
//#include <Hall.h> //person 2
//#include <Employee.h> //person 3
//#include <Finance.h> //person 4

class Cinema {
private:
    vector<Movie> movies; //بتسحب من كلاس movie بتاعتي 
    vector<Hall> halls; //hall بتسحب من كلاس هول مع الشخص 2
    vector<Employee> employees;//employee بتسحب من كلاس  مع الشخص 3
    //Finance finance; //from person 4 use in viewIncome

    SnackBar snackBar;
    Parking parking;    //person 4
    Finance finance;
public:
    void addMovie(Movie m) {
        movies.push_back(m);
    }

    SnackBar* getSnackBar() { return &snackBar; }
    Parking* getParking() { return &parking; } // person 4
    Finance* getFinance() { return &finance; }

    void viewAllMovies() {
        for (int i = 0;i < movies.size();i++) {
            movies[i].displayMovieInfo();
        }
    }
    void removemovie(string name) {
        for (int i = 0; i < movies.size(); i++) {
            if (movies[i].getName() == name) {
                movies.erase(movies.begin() + i);
                break;
            }
        }
    }
    void addHall(Hall h) { //مع الشخص 2
        halls.push_back(h);
    }
    //void viewIncome() {    // هتكمل مع باقي كودهاعلي حسب الاكل واسامي الحاجات ال بيدفع فيها فلوس علشان تحسب دخل الفلوس بتسحب من فانكتشن الشخص 3
        //double tickitIncome=5000; 
        //double snackIncome=2000;
        //double parkingIncome=1000;
        //double total=bookTicket+orderSnacks+useParking; //دول عند الشخص  3 او عند 4 ناخدها من (كالكوليت انكوم)
    //    cout << "total income: " << total << endl; //لو هتاخد من 4 تغير توتال ل claculateIncome
        //cout<<"total income: "<<calculateIncome(); //from Finance in person 4     
    //}
    double getIncome() {
            return finance.calculateIncome(1000, 500, 200); 
    }
    void manageEmployees() { //هتكمل مع باقي كودها لما يبقي فيه لسته موظفين بتسحب من فانكتشن الشخص 3
        int choice;
        cout << "\n ====Employee Managment====\n";
        cout << "1-Add employee\n";
        cout << "2-Showing employee\n";
        cout << "3-calculate salary to employee";
        cout << "0-exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Employee added successfully\n";
        }
        else if (choice == 2) {
            cout << "Displaying employees\n";
        }
        else if (choice == 3) {
            cout << "Salary calculated\n";
        }

    }
    void displayAllEmployees() {
    cout << "Employees list...\n";
    }
    Movie* findMovieByName(string name) {
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getName() == name) {
            return &movies[i];
        }
    }
    return nullptr;
    }

};


//#include Hall
//#include Movie
class Ticket {
private:
    Movie movie;        // يعتمد على Movie (الشخص 1)
    string time;
    double price;
    int seatNumber;
    string hallType;    // جاي من Hall (الشخص 2)
    //    Hall hallType; 
    bool isWeekend;

public:

    Ticket(Movie m, string t, int seat, string hall, bool weekend) : movie(m){
    time = t;
    seatNumber = seat;
    hallType = hall;
    isWeekend = weekend;

    calculatePrice();
    }

    void calculatePrice() {
        price = movie.getPrice();   //  Movie

        if (isWeekend) {
            price = price + 50;
        }
        if (hallType == "VIP") {
            price = price + 30;
        }
    }

    void displayTicket() {
        cout << "\n=== Ticket ===\n";
        cout << "Movie: " << movie.getName() << endl;  // Movie
        cout << "Time: " << time << endl;
        cout << "Seat: " << seatNumber << endl;
        cout << "Hall: " << hallType << endl;
        cout << "Price: " << price << " EGP\n";
    }
};



//this class can use in class (Ticket),(Hall)

class Screen {
private:
    string type;
public:
    Screen(string t) {
        type = t;
    }
    void setType(string t) {
        type = t;
    }
    string getType() {
        return type;
    }
    void displayScreenInfo() {
        cout << "Screen Type: " << type << endl;
    }
};



class Salary {
private:
    int daysWorked; //from Employee
    double dailyRate; //سعر اليوم
    double total;
public:
    Salary(int days, double rate) {
        daysWorked = days;
        dailyRate = rate;
        total = 0;
    }
    void calculateSalary() {
        total = daysWorked * dailyRate;
    }
    void displaySalary() {
        cout << "\n===Salary===\n";
        cout << "days worked: " << daysWorked << endl;
        cout << "daily rate: " << dailyRate << endl;
        cout << "total Salary: " << total << endl;
    }

};


class Hall {
public:
    int capacity;
    string type;
    Hall(int c, string t);
    void displayHallInfo();
};

class Floor {
protected:
    int floorNumber;
    vector<Hall> halls;
public:
    Floor(int n);
    void addHall(Hall h);
    virtual void displayFloorInfo();
};

class FirstFloor : public Floor {
public:
    FirstFloor();
    void displayFloorInfo() override;
};

class SecondFloor : public Floor {
public:
    SecondFloor();
    void displayFloorInfo() override;
};

class ThirdFloor : public Floor {
public:
    ThirdFloor();
    void displayFloorInfo() override;
};





Hall::Hall(int c, string t) : capacity(c), type(t) {}

void Hall::displayHallInfo() {
    cout << "Hall Type: " << type << " | Capacity: " << capacity << endl;
}


Floor::Floor(int n) : floorNumber(n) {}

void Floor::addHall(Hall h) {
    halls.push_back(h);
}

void Floor::displayFloorInfo() {
    cout << "\n--- Floor #" << floorNumber << " ---" << endl;
    for (auto& h : halls) {
        h.displayHallInfo();
    }
}
FirstFloor::FirstFloor() : Floor(1) {}
void FirstFloor::displayFloorInfo() {
    Floor::displayFloorInfo();
    cout << "Services: Small Halls + SnackBar" << endl;
}

SecondFloor::SecondFloor() : Floor(2) {}
void SecondFloor::displayFloorInfo() {
    Floor::displayFloorInfo();
    cout << "Services: VIP Halls + SnackBar" << endl;
}

ThirdFloor::ThirdFloor() : Floor(3) {}
void ThirdFloor::displayFloorInfo() {
    Floor::displayFloorInfo();
    cout << "Services: Kids Area + Restaurant" << endl;
}



//int main() {
//    Hall h1(50, "Normal");
//
//    FirstFloor f1;
//    f1.addHall(h1);
//
//    f1.displayFloorInfo();
//
//    return 0;
//}


/////// person 3 


class User {
protected:
    string name;
    string user_id;
public:
    User(string n, string id) : name(n), user_id(id) {}
    virtual ~User() = default;
    virtual void display_info() const = 0;
    string getName() const { return name; }
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
}
void Owner::addMovie(Movie* movie) {
    if (cinema) {
        cinema->addMovie(*movie);
        cout << "Movie '" << movie->getName() << "' has been successfully added by " << name << endl;
    }
}
void Owner::viewIncome() const {
    if (cinema && cinema->getFinance()) {
        double income = cinema->getFinance()->calculateIncome(1000, 500, 200); //قيم مؤقته
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
        cinema->getSnackBar()->showMenu();
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


class ThirdFloor : public Floor {
public:
    ThirdFloor() : Floor(3) {}

    void displayFloorInfo() override {
        Floor::displayFloorInfo();
        cout << "Floor Services: Kids Area + Restaurant" << endl;
    }
};
