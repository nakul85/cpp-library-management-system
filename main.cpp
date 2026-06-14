#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    Library library;

    library.loadBooks();
    library.loadUsers();

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Register User\n";
        cout << "5. Display Users\n";
        cout << "6. Borrow Book\n";
        cout << "7. Return Book\n";
        cout << "8. Save Data\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.registerUser();
                break;

            case 5:
                library.displayUsers();
                break;

            case 6:
                library.borrowBook();
                break;

            case 7:
                library.returnBook();
                break;

            case 8:
                library.saveBooks();
                library.saveUsers();
                cout << "\nData saved successfully!\n";
                break;

            case 9:
                library.saveBooks();
                library.saveUsers();
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}