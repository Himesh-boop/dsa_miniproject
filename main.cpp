#include <iostream>
#include <string>
#include "URLshortener.cpp"

using namespace std;

int main() {
    URLshortener shortener;
    int choice;
    string url, shortCode;

    while (true) {
        cout << "\n===== URL Shortener (DSA Project) =====\n";
        cout << "1. Shorten a URL\n";
        cout << "2. Retrieve Original URL\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            cout << "Enter long URL: ";
            getline(cin, url);

            string shortUrl = shortener.shortenURL(url);
            cout << "Shortened URL: " << shortUrl << endl;
        }
        else if (choice == 2) {
            cout << "Enter short code: ";
            getline(cin, shortCode);

            string original = shortener.getOriginalURL(shortCode);

            if (original != "") {
                cout << "Original URL: " << original << endl;
            } else {
                cout << "URL not found!\n";
            }
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}