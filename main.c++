using namespace std; // So I don't have to use the : : thingies
#include <iostream> // Input and output library
#include <vector> // Library to use vectors
#include <string> // String library
#include <iomanip> // Library for formatting output (setw)
#include <fstream> // Library so it can see the files
#include <sstream> //  Library to seperate words



// Structure that represents a product in the inventory
struct Product {
    int id; // Product ID
    string name; // Product name
    int quantity; // Product quantity 
    double price; // Product price
};

// Vector that stores the products in the inventory
vector<Product> inventory;

// Function to add a new product to the inventory
void addProduct() {
    Product newProduct;
    cout << "Product ID: "; 
    cin >> newProduct.id; // Read the product ID
    cin.ignore(); // basically just ignore enter or space
    cout << "Product Name: "; 
    getline(cin, newProduct.name); // Read the product name (including spaces this time)
    cout << "Quantity: "; 
    cin >> newProduct.quantity; // Read the product quantity
    cout << "Price: "; 
    cin >> newProduct.price; // Read the product price

    inventory.push_back(newProduct); // Add the new product to the inventory
    cout << "Product added to inventory successfully! 🛍\n"; 

    // Wait for user input and clear the screen
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear||cls");
}

// Function to remove a product from the inventory
void removeProduct() {
    int id;
    cout << "Enter the ID of the product to be removed: "; 
    cin >> id; // Read the product ID

    // Search for the product in the inventory vector
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (it->id == id) { 
            inventory.erase(it); // Remove the product from the vector
            cout << "Product removed successfully! ❌\n"; 

            // Wait for user input and clear the screen
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            system("clear||cls");
            return;
        }
    }
    cout << "Product not found! ⚠️\n"; // Error message if the product is not found

    // Wait for user input and clear the screen
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear||cls");
}

// To edit/update the quantity of a product
void updateQuantity() {
    int id, newQuantity;
    cout << "Enter the product ID: "; 
    cin >> id; // Read the product ID
    cout << "New quantity: "; 
    cin >> newQuantity; // Read the new quantity

    // Search for the product in the inventory vector
    for (auto &product : inventory) {
        if (product.id == id) { 
            product.quantity = newQuantity; // Update the product quantity
            cout << "Quantity updated successfully! 🔄\n"; 

            // Wait for user input and clear the screen
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            system("clear||cls");
            return;
        }
    }
    cout << "Product not found! ⚠️\n"; // Error message if the product is not found

    // Wait for user input and clear the screen
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear||cls");
}

// Function to display all products in the inventory
void displayInventory() {
    // Display the table to make it look prettier and stuff
    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Quantity" << setw(10) << "Price" << "\n";
    cout << "------------------------------------------------------\n";

    // Display all the product info 
    for (const auto &product : inventory) {
        cout << left << setw(10) << product.id << setw(20) << product.name
             << setw(10) << product.quantity << setw(10) << product.price << "\n";
    }

    // Wait for user input and clear the screen
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear||cls");
}

// Function to save the inventory to a file
void saveInventory() {
    ofstream file("inventory.txt"); // Open the file for writing
    if (file.is_open()) { // Check if the file was successfully opened
        // Write the information of each product to the file
        for (const auto &product : inventory) {
            file << product.id << " " << product.name << " " << product.quantity
                 << " " << product.price << "\n";
        }
        file.close(); // Close the file
        cout << "Inventory saved successfully! 💾\n";
    } else {
        cout << "Error saving inventory! 🚨\n"; 
    }

    // Wait for user input and clear the screen
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear||cls");
}

// Function to load the inventory from a file
void loadInventory() {
    ifstream file("inventory.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was successfully opened
        string line;
        while (getline(file, line)) { // Read each line from the file 
            istringstream iss(line); // Create a string stream to seperate the line
            Product product;
            if (iss >> product.id >> product.name >> product.quantity >> product.price) { // Seperate the info so it's not all together
                inventory.push_back(product); // So it's in the inventory list (vector)
            }
        }
        file.close(); // Close the file
        cout << "Inventory loaded successfully! 📂\n"; 
    } else {
        cout << "Error loading inventory! 🚨\n"; 
    }


    system("clear||cls");
}

// Main function with the system menu
int main() {
#ifdef _WIN32
    system("chcp 65001 > nul"); // Code to make it support emojis
#endif

    int option;
    loadInventory(); 
    system("clear||cls"); // Clear the screen after loading inventory
    do {
        // Clear the screen before displaying the menu
        system("clear||cls");

        // Display the system menu
        cout << "\nInventory Management System 🛍\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Quantity\n";
        cout << "4. Display Inventory\n";
        cout << "5. Save Inventory\n";
        cout << "6. Exit\n";
        cout << "Choose an option: "; 
        cin >> option; 

        // Menu option 
        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                saveInventory();
                break;
            case 6:
                cout << "Exiting... 👋\n"; 
                break;
            default:
                cout << "Invalid option! ⚠️\n";
        }
    } while (option != 6);

    return 0;
}
