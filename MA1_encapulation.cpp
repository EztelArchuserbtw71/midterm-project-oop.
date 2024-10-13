#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
//class items
class Item {
private:
    string id;
    string name;
    string category;
    double price;
    int quantity;

public:
    Item(string id, string name, string category, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
    }

    string getID() {
        return id;
    }

    string getName() {
        return name;
    }

    string getCategory() {
        return category;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void display() {
        cout << setw(10) << left << id 
             << setw(15) << left << name 
             << setw(15) << left << category 
             << setw(10) << left << price 
             << setw(10) << left << quantity << endl;
    }
};
//class invetories
class Inventory {
private:
    Item* items[100];
    int itemCount;
//merge sort i use as my sorting algorithm thanks DSA!!
    void merge(Item* arr[], int left, int mid, int right, int sortBy) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Item** L = new Item*[n1];
        Item** R = new Item*[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            bool condition = (sortBy == 1) ? (L[i]->getPrice() <= R[j]->getPrice()) : (L[i]->getQuantity() <= R[j]->getQuantity());
            if (condition) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void mergeSort(Item* arr[], int left, int right, int sortBy) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid, sortBy);
            mergeSort(arr, mid + 1, right, sortBy);
            merge(arr, left, mid, right, sortBy);
        }
    }

public:
    Inventory() {
        itemCount = 0;
    }

    void addItem() {
        string id, name, category;
        double price;
        int quantity;

        cout << "--add item--\n";
        cout << "Enter product category (1=CLOTHING||2=ELECTRONICS||3=ENTERTAINMENT): ";
        int categoryChoice;
        cin >> categoryChoice;
        switch (categoryChoice) {
            case 1: category = "CLOTHING"; break;
            case 2: category = "ELECTRONICS"; break;
            case 3: category = "ENTERTAINMENT"; break;
            default: cout << "Category does not exist!\n"; return;
        }

        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product name: ";
        cin >> name;

        while (true) {
            cout << "Enter product price: ";
            cin >> price;
            if (cin.fail() || price <= 0) {
                cout << "Invalid pricing!!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter product quantity: ";
            cin >> quantity;
            if (cin.fail() || quantity < 0) {
                cout << "Invalid input! valid quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        items[itemCount++] = new Item(id, name, category, price, quantity);
        cout << "Item added successfully!\n";
    }

    void updateItem() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        cout << "--Inventory--\n";
        cout << setw(10) << left << "ID" 
             << setw(15) << left << "Name" 
             << setw(15) << left << "Category" 
             << setw(10) << left << "Price" 
             << setw(10) << left << "Quantity" << endl;

        for (int i = 0; i < itemCount; i++) {
            items[i]->display();
        }

        string id;
        cout << "Enter product ID to update: ";
        cin >> id;

        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getID() == id) {
                double newPrice;
                int newQuantity;

                cout << "Enter product price: ";
                cin >> newPrice;

                while (true) {
                    cout << "Enter product quantity: ";
                    cin >> newQuantity;
                    if (cin.fail() || newQuantity < 0) {
                        cout << "Invalid input! valid quantity: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }

                items[i]->setPrice(newPrice);
                items[i]->setQuantity(newQuantity);
                cout << "Item updated successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void removeItem() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        cout << "--Inventory--\n";
        cout << setw(10) << left << "ID" 
             << setw(15) << left << "Name" 
             << setw(15) << left << "Category" 
             << setw(10) << left << "Price" 
             << setw(10) << left << "Quantity" << endl;

        for (int i = 0; i < itemCount; i++) {
            items[i]->display();
        }

        string id;
        cout << "Enter product ID to remove: ";
        cin >> id;

        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getID() == id) {
                cout << "Item " << items[i]->getName() << " has been removed from the inventory!!\n";
                delete items[i];
                items[i] = items[itemCount - 1];
                itemCount--;
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void displayByCategory() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        int categoryChoice;
        cout << "Enter category to display (1=CLOTHING||2=ELECTRONICS||3=ENTERTAINMENT): ";
        cin >> categoryChoice;
        string category;

        switch (categoryChoice) {
            case 1: category = "CLOTHING"; break;
            case 2: category = "ELECTRONICS"; break;
            case 3: category = "ENTERTAINMENT"; break;
            default: cout << "Category does not exist!\n"; return;
        }

        cout << "--" << category << " Inventory--\n";
        cout << setw(10) << left << "ID" 
             << setw(15) << left << "Name" 
             << setw(15) << left << "Category" 
             << setw(10) << left << "Price" 
             << setw(10) << left << "Quantity" << endl;

        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getCategory() == category) {
                items[i]->display();
            }
        }
    }

    void displayAllItems() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        cout << "--Inventory--\n";
        cout << setw(10) << left << "ID" 
             << setw(15) << left << "Name" 
             << setw(15) << left << "Category" 
             << setw(10) << left << "Price" 
             << setw(10) << left << "Quantity" << endl;

        for (int i = 0; i < itemCount; i++) {
            items[i]->display();
        }
    }

    void searchItem() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        string id;
        cout << "Enter product ID to search: ";
        cin >> id;

        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getID() == id) {
                items[i]->display();
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void sortItems() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        int sortBy, order;
        cout << "Sort by (1=Price || 2=Quantity): ";
        cin >> sortBy;
        cout << "Order (1=Ascending || 2=Descending): ";
        cin >> order;

        mergeSort(items, 0, itemCount - 1, sortBy);
        if (order == 2) {
            // Reverse the sorted array for descending order
            for (int i = 0; i < itemCount / 2; i++) {
                Item* temp = items[i];
                items[i] = items[itemCount - 1 - i];
                items[itemCount - 1 - i] = temp;
            }
        }

        displayAllItems();
    }

    void displayLowStock() {
        if (itemCount == 0) {
            cout << "there is no item in inventory!\n";
            return;
        }

        cout << "--Low Stock Items--\n";
        cout << setw(10) << left << "ID" 
             << setw(15) << left << "Name" 
             << setw(15) << left << "Category" 
             << setw(10) << left << "Price" 
             << setw(10) << left << "Quantity" << endl;

        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getQuantity() < 5) {//if the stock item quantity is less than 5 its considerd as low stock
                items[i]->display();
            }
        }
    }
};

void displayMenu() {
    cout << "\n--Inventory Management System--\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. Remove Item\n";
    cout << "4. Display by Category\n";
    cout << "5. Display All Items\n";
    cout << "6. Search Item\n";
    cout << "7. Sort Items\n";
    cout << "8. Display Low Stock Items\n";
    cout << "9. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 9) {
            cout << "Error!! try again!!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
//my switches
        switch (choice) {
            case 1: inventory.addItem(); break;
            case 2: inventory.updateItem(); break;
            case 3: inventory.removeItem(); break;
            case 4: inventory.displayByCategory(); break;
            case 5: inventory.displayAllItems(); break;
            case 6: inventory.searchItem(); break;
            case 7: inventory.sortItems(); break;
            case 8: inventory.displayLowStock(); break;
            case 9: cout << "Exiting the program...\n"; return 0;
            default: cout << "Error!! try again!!\n"; break;
        }
    }

    return 0;
}
