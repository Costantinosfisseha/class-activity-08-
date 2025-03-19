#include <iostream>
#include <string>
using namespace std;

//function to check if a string is empty
bool isValidString(string input) {
    return !input.empty();  //returns true if the string is NOT empty
}

//function to check if a number is valid mean greater  than zero
bool isValidNumber(int num) {
    return num > 0;  //returns true if number is positive
}

//function to check if an email is valid contains '@' and '.' by using find 
bool isValidEmail(string email) {// we used bool because it's simply true or false
    return (email.find('@') != string::npos) && (email.find('.') != string::npos);
}

//address structure
struct Address {
    string street;
    string city;
    int zipcode;
};

//customer structure with nested Address
struct Customer {
    string Name;
    int Id;
    string email;
    Address address;
};

int main()
{
    Customer customer1;

    //get user input with validation
    do {
        cout << "Enter customer name: ";
        getline(cin, customer1.Name);
    } while (!isValidString(customer1.Name));//checks if name is valid means not empty 

    do {
        cout << "Enter customer ID: ";
        cin >> customer1.Id;
        cin.ignore();  // Clear the buffer
    } while (!isValidNumber(customer1.Id));//the isValidNumber been called

    do {
        cout << "Enter email: ";
        getline(cin, customer1.email);
    } while (!isValidEmail(customer1.email));

    do {
        cout << "Enter street: ";
        getline(cin, customer1.address.street);
    } while (!isValidString(customer1.address.street));

    do {
        cout << "Enter city: ";
        getline(cin, customer1.address.city);
    } while (!isValidString(customer1.address.city));//the isValidString been checked

    do {
        cout << "Enter zipcode: ";
        cin >> customer1.address.zipcode;
        cin.ignore();  //clear the buffer
    } while (!isValidNumber(customer1.address.zipcode));

    //display customer details
    cout << "\nCustomer Details:\n";
    cout << "Name: " << customer1.Name << endl;
    cout << "ID: " << customer1.Id << endl;
    cout << "Email: " << customer1.email << endl;
    cout << "Address: " << customer1.address.street << ", " 
         << customer1.address.city << ", " << customer1.address.zipcode << endl;

    return 0;
}
