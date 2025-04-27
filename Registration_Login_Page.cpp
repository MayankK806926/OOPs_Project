/*
Here we are creating a registration and login page:
It includes:
1. Register User,
2. Login User,
3. Show User Info,
4. Search User,
5. Delete User.
6. Exit the program.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <limits>
using namespace std;

// User class to store individual user's username and password
class User{
    private:
        string username;
        string password;
    public:
        User(string name, string passwd){
            username = name;
            password = passwd;
        }
        string get_username(){
            return username;
        }
        string get_password(){
            return password;
        }
};

// Class to perform operations on users like Register, Login, Show, Find, Delete
class User_operations{
    private:
        vector<User> users; // Vector to store all users
    public:
        // Function to register a new user
        void Register_User(){
            string username, password;
            cout << "Enter your Username:" << endl;
            cin >> username;

            // Check if username already exists
            for (auto user : users){
                if (user.get_username() == username){
                    cout << "Username already exists! Try another one." << endl;
                    return;
                }
            }

            cout << "Enter your Password:" << endl;
            cin >> password;

            User newUser(username, password); // Create new User object
            users.push_back(newUser); // Add user to the list

            cout << "Successful Registration of the user." << endl;
        }

        // Function to login user
        bool Login_User(string name, string passwd){
            bool username_check = false;
            for (int i = 0; i < users.size(); ++i){
                if (users[i].get_username() == name && users[i].get_password() == passwd){
                    cout << "The user logged in successfully." << endl;
                    return true;
                }
                if (users[i].get_username() == name){
                    username_check = true; // Username exists but password wrong
                }
            }
            if (username_check){
                cout << "Wrong Password." << endl;
            } else {
                cout << "Invalid Username." << endl;
            }
            return false;
        }

        // Function to display all registered users
        void show_User(){
            if (users.empty()){
                cout << "No users registered yet!" << endl;
                return;
            }
            cout << "Here is the users list:" << endl;
            for (int i = 0; i < users.size(); ++i){
                cout << i + 1 << ". " << users[i].get_username() << endl;
            }
        }

        // Function to find a user by username
        void find_User(string user_name){
            int n = users.size();
            for (int i = 0; i < n; ++i){
                if (users[i].get_username() == user_name){
                    cout << "User Found:" << endl;
                    cout << "Username: " << users[i].get_username() << endl;
                    
                    // Display password as stars
                    int size = users[i].get_password().length();
                    string pwd(size, '*');
                    cout << "Password: " << pwd << endl;
                    return;
                }
            }
            cout << "User not found!" << endl;
        }

        // Function to delete a user
        void del_User(string user_name){
            int n = users.size();
            for (int i = 0; i < n; ++i){
                if (user_name == users[i].get_username()){
                    users.erase(users.begin() + i); // Remove user from vector
                    cout << "User Removed Successfully." << endl;
                    return;
                }
            }
            cout << "User not found! Cannot delete." << endl;
        }
};

int main(){
    User_operations user_op; // Create object for operations
    int option;
    string choice;

    do{
        system("cls"); // Clear the screen (comment if not using Windows)

        // Menu display
        cout << "Different actions you can take are:" << endl;
        cout << "1 -> To Register User" << endl;
        cout << "2 -> To Login" << endl;
        cout << "3 -> To Show User Info" << endl;
        cout << "4 -> To Find the User" << endl;
        cout << "5 -> To Delete any User" << endl;
        cout << "6 -> Exit" << endl;

        cout << "Enter your choice from above:" << endl;

        // Input validation: Ensure that the user enters a valid number
        while (!(cin >> option) || option < 1 || option > 6) {
            cout << "Invalid input. Please enter a valid option (1-6):" << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }

        // Handle the user option
        switch (option){
            case 1:{
                user_op.Register_User();
                break;
            }
            case 2:{
                string username, password;
                cout << "Enter the username:" << endl;
                cin >> username;
                cout << "Enter the password:" << endl;
                cin >> password;
                user_op.Login_User(username, password);
                break;
            }
            case 3:{
                user_op.show_User();
                break;
            }
            case 4:{
                string user_name;
                cout << "Enter the username to search:" << endl;
                cin >> user_name;
                user_op.find_User(user_name);
                break;
            }
            case 5:{
                string user_name;
                cout << "Enter the username to delete:" << endl;
                cin >> user_name;
                user_op.del_User(user_name);
                break;
            }
            case 6:{
                cout << "Exiting Program. Goodbye!" << endl;
                exit(0); // Exit the program
            }
            default:
                cout << "Invalid Input." << endl;
                break;
        }

        // Ask if the user wants to continue
        cout << "Do you want to continue [\"Yes\"/\"No\"]?" << endl;
        cin >> choice;
        
        // Convert choice to lowercase for easier checking
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        
        if (choice != "yes") break;

    } while (true);

    return 0;
}
