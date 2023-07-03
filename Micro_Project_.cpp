#include <iostream>
#include <string>

using namespace std;


struct Product {
    string name;
    int quantity;
    double price;
};

 
void addProduct(Product stock[], int& stockSize) {
    Product newProduct;
    cout << "Enter the product name: ";
    cin >> newProduct.name;
    cout << "Enter the product quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter the product price: ";
    cin >> newProduct.price;
    stock[stockSize] = newProduct;
    stockSize++;
    cout << "Product added successfully!\n";
}

void updateQuantity(Product stock[], int stockSize, double& totalProfit, double& totalLoss) {
    string productName;
    int soldQuantity;
    double saleAmount;
    cout << "Enter the product name: ";
    cin >> productName;
    cout << "Enter the sold quantity: ";
    cin >> soldQuantity;
    cout << "Enter the sale amount: rs";
    cin >> saleAmount;

    bool found = false;
    for (int i = 0; i < stockSize; i++) {
        if (stock[i].name == productName) {
            if (stock[i].quantity >= soldQuantity) {
                stock[i].quantity -= soldQuantity;
                double totalCost = stock[i].price * soldQuantity;
                cout << "Sold " << soldQuantity << " units of " << stock[i].name << " successfully!\n";
                cout << "Sale Amount: rs" << saleAmount << "\n";
                if (saleAmount > totalCost) {
                    double profit = saleAmount - totalCost;
                    cout << "Profit: rs" << profit << "\n";
                    totalProfit += profit;
                } else if (saleAmount < totalCost) {
                    double loss = totalCost - saleAmount;
                    cout << "Loss: rs" << loss << "\n";
                    totalLoss += loss;
                } else {
                    cout << "No profit or loss.\n";
                }
            } else {
                cout << "Insufficient stock for " << stock[i].name << ". Sold quantity exceeds available quantity.\n";
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found!\n";
    }
}


void displayStock(const Product stock[], int stockSize) {
    if (stockSize == 0) {
        cout << "Stock is empty!\n";
    } else {
        cout << "Current Stock:\n";
        for (int i = 0; i < stockSize; i++) {
            cout << "Product Name: " << stock[i].name << ", Quantity: " << stock[i].quantity << ", Price: $" << stock[i].price << "\n";
        }
    }
}

int main() {
    const int MAX_STOCK_SIZE = 100;
    Product stock[MAX_STOCK_SIZE];
    int stockSize = 0;
    double totalProfit = 0.0;
    double totalLoss = 0.0;
    int choice;

    string continueChoice;

    do {
        cout << "\nStock Management System\n";
        cout << "1. Add a new product\n";
        cout << "2. Sell product\n";
        cout << "3. Display stock\n";
       
        cout << "4. Total Profit\n";
        cout << "5. Total Loss\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(stock, stockSize);
                break;
            case 2:
                updateQuantity(stock, stockSize, totalProfit, totalLoss);
                break;
            case 3:
                displayStock(stock, stockSize);
                break;
            case 4:
                cout << "Total Profit: rs" << totalProfit << endl;
                break;
            case 5:
                cout << "Total Loss: rs" << totalLoss << endl;
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

        
        if (choice != 0) {
            cout << "Do you want to continue? (yes/no): ";
            cin >> continueChoice;
        }

    } while (continueChoice == "yes");

    return 0;
}
