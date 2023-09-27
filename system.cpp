#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password0, password1, password2, pass, name, passworde, age, user, word, word1;
    string creds[2], cp[2];

    cout << "Security System" << endl;
    cout << "_____________________________" << endl;
    cout << "|      1. Register           |" << endl;
    cout << "|      2. Login              |" << endl;
    cout << "|      3. Change password    |" << endl;
    cout << "|      4. End Program        |" << endl
         << endl;

    do {
        cout << endl
             << endl;
        cout << "Enter your choice:---";
        cin >> a;
        switch (a) {
            case 1: {
                cout << "_______________________" << endl
                     << endl;
                cout << "|      --Register--       | " << endl;
                cout << "|_________________________|" << endl
                     << endl;
                cout << "Please enter username:- ";
                cin >> name;
                cout << "Please enter the password: ";
                cin >> password0;
                cout << "Please enter your age:- ";
                cin >> age;

                ofstream of1;
                of1.open("file.txt");

                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0;
                    of1.close(); // Close the file after writing
                    cout << "Registration successful" << endl;
                }
                break;
            }

            case 2: {
                i = 0;
                cout << "_____________________________" << endl
                     << endl;
                cout << "|----------Login--------------|" << endl;
                cout << "______________________________" << endl
                     << endl;

                ifstream of2;
                of2.open("file.txt");

                cout << "Please enter the username:- ";
                cin >> user;
                cout << "Please enter the password: ";
                cin >> pass;

                if (of2.is_open()) {
                    bool found = false;

                    while (getline(of2, text)) {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }

                    if (user == creds[0] && pass == creds[1]) {
                        found = true;
                        cout << "---Log in successful---" << endl;
                        cout << endl << "Details: " << endl;
                        cout << "Username: " << user << endl;
                        cout << "Password: " << pass << endl;
                        cout << "Age: " << age << endl;
                    }

                    if (!found) {
                        cout << "Incorrect Credentials" << endl;
                        cout << "| 1. Press 2 to Login            |" << endl;
                        cout << "| 2. Press 3 to change password  |" << endl;
                    }
                } else {
                    cout << "Incorrect Credentials" << endl;
                }
                of2.close();
                break;
            }

            case 3: {
                i = 0;
                cout << "---Change password--" << endl;
                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the old password:- ";
                cin >> old;

                if (of0.is_open()) {
                    bool passwordChanged = false;
                    while (getline(of0, text)) {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }

                    if (old == cp[1]) {
                        of0.close();
                        ofstream of1;
                        of1.open("file.txt");

                        if (of1.is_open()) {
                            cout << "Enter your new password:- ";
                            cin >> password1;
                            cout << "Enter your password again:- ";
                            cin >> password2;

                            if (password1 == password2) {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                passwordChanged = true;
                                cout << "Password changed successfully" << endl;
                            } else {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Passwords do not match" << endl;
                            }

                            of1.close();
                        }
                    }

                    if (!passwordChanged) {
                        cout << "Please enter a valid old password" << endl;
                    }
                } else {
                    cout << "File not found" << endl;
                }
                of0.close();
                break;
            }

            case 4:
                cout << "__________thank you____________" << endl;
                break;

            default:
                cout << "Enter a valid choice" << endl;
        }
    } while (a != 4);
    return 0;
}

