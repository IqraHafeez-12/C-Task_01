#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function
using namespace std;

// Constants for array sizes
const int NUM_CATEGORIES = 7;
const int MAX_ITEMS_PER_CATEGORY = 3;

// Arrays to store item details
string categories[NUM_CATEGORIES] = {"Case", "RAM", "Main HDD", "SSD", "Second HDD", "Optical Drive", "Operating System"};
string itemCodes[NUM_CATEGORIES][MAX_ITEMS_PER_CATEGORY] = {
    {"A1", "A2"},
    {"B1", "B2", "B3"},
    {"C1", "C2", "C3"},
    {"D1", "D2"},
    {"E1", "E2", "E3"},
    {"F1", "F2"},
    {"G1", "G2"}};
string itemDescriptions[NUM_CATEGORIES][MAX_ITEMS_PER_CATEGORY] = {
    {"Compact", "Tower"},
    {"8 GB", "16 GB", "32 GB"},
    {"1 TB HDD", "2 TB HDD", "4 TB HDD"},
    {"240 GB SSD", "480 GB SSD"},
    {"1 TB HDD", "2 TB HDD", "4 TB HDD"},
    {"DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer"},
    {"Standard Version", "Professional Version"}};
double itemPrices[NUM_CATEGORIES][MAX_ITEMS_PER_CATEGORY] = {
    {75.00, 150.00},
    {79.99, 149.99, 299.99},
    {49.99, 89.99, 129.99},
    {59.99, 119.99},
    {49.99, 89.99, 129.99},
    {50.00, 100.00},
    {100.00, 175.00}};

// Function to display available items in a category
void displayCategoryItems(int categoryIndex) {
    cout << "Available " << categories[categoryIndex] << "s:" << endl;
    for (int i = 0; i < MAX_ITEMS_PER_CATEGORY; ++i) {
        cout << itemCodes[categoryIndex][i] << ": " << itemDescriptions[categoryIndex][i] << " - $" << itemPrices[categoryIndex][i] << endl;
    }
}

// Function to choose an item from a category with input validation
string chooseItem(int categoryIndex) {
    string choice;
    displayCategoryItems(categoryIndex);

    bool validChoice = false;
    while (!validChoice) {
        cout << "Enter the item code to choose: ";
        cin >> choice;

        // Validate the entered item code
        for (int i = 0; i < MAX_ITEMS_PER_CATEGORY; ++i) {
            if (choice == itemCodes[categoryIndex][i]) {
                validChoice = true;
                break;
            }
        }

        if (!validChoice) {
            cout << "Invalid item code. Please enter a valid code." << endl;
        }
    }

    return choice;
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Basic set of components
    double basicComponentsPrice = 200.00;

    // Chosen items
    string chosenCase, chosenRAM, chosenMainHDD, chosenOS;
    double totalPrice = basicComponentsPrice;

    // Task 1 - Choosing main items
    cout << "Task 1 - Choosing main items" << endl;
    chosenCase = chooseItem(0); // Case
    chosenRAM = chooseItem(1);  // RAM
    chosenMainHDD = chooseItem(2); // Main HDD

    // Calculate the price of the computer
    totalPrice += itemPrices[0][chosenCase[1] - '1']; // Case price
    totalPrice += itemPrices[1][chosenRAM[1] - '1'];  // RAM price
    totalPrice += itemPrices[2][chosenMainHDD[1] - '1']; // Main HDD price

    // Display chosen items and total price
    cout << "\nChosen Items:" << endl;
    cout << "Case: " << itemDescriptions[0][chosenCase[1] - '1'] << endl;
    cout << "RAM: " << itemDescriptions[1][chosenRAM[1] - '1'] << endl;
    cout << "Main HDD: " << itemDescriptions[2][chosenMainHDD[1] - '1'] << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;

    // Task 2 - Ordering additional items
    cout << "\nTask 2 - Ordering additional items" << endl;
    char additionalItemsChoice;
    cout << "Do you want to purchase additional items? (y/n): ";
    cin >> additionalItemsChoice;

    if (additionalItemsChoice == 'y' || additionalItemsChoice == 'Y') {
        string chosenSSD, chosenSecondHDD, chosenOpticalDrive;
        chosenSSD = chooseItem(3);           // SSD
        chosenSecondHDD = chooseItem(4);      // Second HDD
        chosenOpticalDrive = chooseItem(5);   // Optical Drive

        // Update the price of the computer with additional items
        totalPrice += itemPrices[3][chosenSSD[1] - '1']; // SSD price
        totalPrice += itemPrices[4][chosenSecondHDD[1] - '1']; // Second HDD price
        totalPrice += itemPrices[5][chosenOpticalDrive[1] - '1']; // Optical Drive price

        // Display additional items and new total price
        cout << "\nAdditional Items:" << endl;
        cout << "SSD: " << itemDescriptions[3][chosenSSD[1] - '1'] << endl;
        cout << "Second HDD: " << itemDescriptions[4][chosenSecondHDD[1] - '1'] << endl;
        cout << "Optical Drive: " << itemDescriptions[5][chosenOpticalDrive[1] - '1'] << endl;
        cout << "New Total Price: $" << fixed << setprecision(2) << totalPrice << endl;

        // Task 3 - Offering discounts
        cout << "\nTask 3 - Offering discounts" << endl;
        int numAdditionalItems = 3; // Default to all additional items
        double discountPercentage = 0.0;

        if (numAdditionalItems == 1) {
            discountPercentage = 5.0;
        } else if (numAdditionalItems >= 2) {
            discountPercentage = 10.0;
        }

        double discountAmount = (discountPercentage / 100.0) * totalPrice;
        totalPrice -= discountAmount;

        // Display discount details and final total price
        cout << "Discount Applied: " << discountPercentage << "%" << endl;
        cout << "Amount Saved: $" << fixed << setprecision(2) << discountAmount << endl;
        cout << "Final Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    } else {
        cout << "\nNo additional items purchased. Final Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    }

    return 0;
}
