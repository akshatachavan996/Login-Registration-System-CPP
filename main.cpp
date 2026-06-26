#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check whether a username already exists
bool usernameExists(string username)
{
    ifstream file("users.txt");

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n=====================================\n";
    cout << "          USER REGISTRATION\n";
    cout << "=====================================\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    // Validate Username
    if (username.length() < 3)
    {
        cout << "\nError: Username must contain at least 3 characters.\n";
        return;
    }

    // Validate Password
    if (password.length() < 6)
    {
        cout << "\nError: Password must contain at least 6 characters.\n";
        return;
    }

    // Check Duplicate Username
    if (usernameExists(username))
    {
        cout << "\nError: Username already exists.\n";
        return;
    }

    // Save User Credentials
    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "\nError: Unable to open users.txt file.\n";
        return;
    }

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}
// Login Function
void loginUser()
{
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n=====================================\n";
    cout << "              USER LOGIN\n";
    cout << "=====================================\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    ifstream file("users.txt");

    if (!file)
    {
        cout << "\nError: Unable to open users.txt file.\n";
        return;
    }

    bool loginSuccess = false;

    while (file >> storedUsername >> storedPassword)
    {
        if (username == storedUsername &&
            password == storedPassword)
        {
            loginSuccess = true;
            break;
        }
    }

    file.close();

    if (loginSuccess)
    {
        cout << "\n=====================================\n";
        cout << "Login Successful!\n";
        cout << "Welcome, " << username << "!\n";
        cout << "=====================================\n";
    }
    else
    {
        cout << "\n=====================================\n";
        cout << "Invalid Username or Password!\n";
        cout << "=====================================\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}