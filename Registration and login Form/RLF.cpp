#include <iostream>
#include <fstream>
using namespace std;
class User {
private:
   string username;
   string password;
public:
   User() = default;
   void registerUser(const string & uname, const string& pass) {
       username = uname;
       password = pass;
       // Saving  user data to a file
       ofstream file("users.txt", ios::app);
       if (file.is_open()) {
           file << username << " " << password << endl;
           file.close();
           cout << "Registration successful!" << endl;
       } else {
           cout << "Error saving user data!" << endl;
       }
   }
   bool loginUser(const string& uname, const string& pass) {
       ifstream file("users.txt");
       string storedUsername, storedPassword;
       if (file.is_open()) {
           while (file >> storedUsername >> storedPassword) {
               if (storedUsername == uname && storedPassword == pass) {
                   return true;
               }
           }
           file.close();
       }
       return false;
   }
};
int main() {
   User user;
   int choice;
   string username, password;
   while (true) {
       cout << "\n1. Register\n2. Login\n3. Exit\nEnter your choice: ";
       cin >> choice;
       switch (choice) {
           case 1:
               cout << "Enter username: ";
               cin >> username;
               cout << "Enter password: ";
               cin >> password;
               user.registerUser(username, password);
               break;
           case 2:
               cout << "Enter username: ";
               cin >> username;
               cout << "Enter password: ";
               cin >> password;
               if (user.loginUser(username, password)) {
                   cout << "Login successful!" << endl;
               } else {
                   cout << "Invalid credentials!" << endl;
               }
               break;
           case 3:
               cout << "Exiting..." << endl;
               return 0;
           default:
               cout << "Invalid choice! Try again." << endl;
       }
   }
}