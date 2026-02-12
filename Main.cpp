#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <limits>

using namespace std;

struct CoffeeOrder {
    string name;
    int espressoShots;
    string size;
    string temperature;
    string flavor;
    string milkType;
    bool coldFoam;
    double price;
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void customizeDrink(CoffeeOrder &order);
void displaySummary(const CoffeeOrder *order);

int main() {
    cout << fixed << setprecision(2);

    CoffeeOrder myOrder;
    myOrder.price = 5.00;

    cout << "\n--- Welcome to Ysabelle's Coffee Shop! ---\n";
    cout << "What is the name for the order?: ";
    cin >> ws; 
    getline(cin, myOrder.name);

    customizeDrink(myOrder);
    displaySummary(&myOrder);

    cout << "Goodbye!\n";
    return 0;
}
void customizeDrink(CoffeeOrder &order) {
    int choice;

    cout << "\nChoose a size:\n1. Small: 12oz\n2. Medium: 16oz (+$1.00)\n3. Large: 20oz (+$1.50)\nChoice: ";
    while (!(cin >> choice) || choice < 1 || choice > 3) { 
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        clearInput();
    }

    if (choice == 1) {
        order.size = "Small";
    } else if (choice == 2) { 
        order.size = "Medium"; 
        order.price += 1.0; 
    } else { 
        order.size = "Large"; 
        order.price += 1.5; 
    }

    cout << "Temperature (Hot or Iced): ";
    cin >> order.temperature;

    cout << "How many espresso shots? : ";
    while (!(cin >> order.espressoShots) || order.espressoShots < 0) {
        cout << "Please enter a valid number: ";
        clearInput();
    }
    order.price += (order.espressoShots * 0.25);

    cout << "Flavor (Vanilla/Mocha/Caramel/Rose/Cookie Butter): ";
    cin >> ws; 
    getline(cin, order.flavor);

    cout << "Milk Type (Whole/Oat/Almond): ";
    getline(cin, order.milkType);

    char foamChoice;
    cout << "Add Cold Foam? (y/n): ";
    cin >> foamChoice;
    order.coldFoam = (foamChoice == 'y' || foamChoice == 'Y');
    if (order.coldFoam) order.price += 1.00;
}

void displaySummary(const CoffeeOrder *order) {
    cout << "\n------------------------------";
    cout << "\n--- ORDER SUMMARY FOR " << order->name << " ---";
    cout << "\nDrink: " << order->size << " " << order->temperature << " " << order->flavor << " Latte";
    cout << "\nEspresso Shots: " << order->espressoShots;
    cout << "\nMilk: " << order->milkType;
    cout << "\nCold Foam: " << (order->coldFoam ? "Yes" : "No");
    cout << "\nTotal Price: $" << order->price;
    cout << "\nThank you for your order! Enjoy your coffee!";
    cout << "\n------------------------------\n" << endl;
}
