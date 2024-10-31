#include <bits/stdc++.h>
using namespace std;

string name_save[10][3];
class User {
public:
    string username;
    string password;

    User(string uname, string pwd) : username(uname), password(pwd) {}
};

class HostelManage 
{
public:
    User current_user;

    void registerUser() 
	{
        string username, password;
        cout << "Enter your desired username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        current_user = User(username, password);
        cout << "Registration successful!" << endl;
    }

    bool loginUser() 
	{
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (username == "admin" && password == "admin123") 
		{
            current_user = User(username, password);
            cout << "Login successful!" << endl;
            return true;
        } else 
		{
            cout << "Login failed. Invalid credentials." << endl;
            return false;
        }
    }
};

class Node
{
public:
    int room_capacity = 1;
    int fill_room = 0;
    char name[3][10];
    Node *next;
    Node *previous;
};

class hostel
{
    Node *head[3];
    Node *created_node;
public:
    hostel()
    {
        for (int i = 0; i < 3; i++)
            head[i] = NULL;
    }
    void create();
    void display();
};

void hostel :: create()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            Node *newnode = new Node;
            newnode->next = NULL;
            newnode->previous = NULL;
            if (head[i] == NULL)
            {
                head[i] = newnode;
                newnode -> room_capacity = 1;
            }
            else
            {
                Node *created_node = head[i];
                while (created_node -> next != NULL)
                {
                    created_node = created_node -> next;
                }
                if (j == 3 || j == 5 || j == 7 || j == 8)
                {
                    created_node -> room_capacity = 3;
                }
                if (j == 2 || j == 4 || j == 6)
                {
                    created_node -> room_capacity = 2;
                }
                created_node -> next = newnode;
                newnode -> previous = created_node;
            }
        }
    }
}

void hostel :: display()
{
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < 60; i++)
	{
        cout << "--";
    }
    cout << endl;
    for (int i = 1; i < 4; i++)
	{
        cout << " Floor number : " << i << " \t\t\t";
    }
    cout << endl;
    for (int i = 0; i < 60; i++)
	{
        cout << "--";
    }
    created_node = head[j];
    Node *secondfloor_node = head[j + 1];
    Node *thirdfloor_node = head[j + 2];
    cout << endl;
    while (created_node != NULL)
	{
        if (created_node->fill_room != created_node->room_capacity && created_node->room_capacity != 0)
		{
            j++;
            cout << " Room no: " << j;
            cout << ":-- Vacant Room --: " << created_node -> room_capacity;
        }
        else
		{
            j++;
            cout << " Room no: " << j;
            cout << " Already Booked by: "<< name_save[j-1][0];
        }
        if (secondfloor_node->fill_room != secondfloor_node->room_capacity && secondfloor_node->room_capacity != 0)
		{
            k++;
            cout << "\t Room no: " << k;
            cout << ":-- Vacant Room --: "<< secondfloor_node->room_capacity;
        }
        else
		{
            k++;
            cout << "\t Room no: " << k;
            cout << "\t Already Booked by: "<< name_save[k-1][1];
        }
        if(thirdfloor_node->fill_room != thirdfloor_node->room_capacity && thirdfloor_node->room_capacity != 0)
		{
            l++;
            cout << "\t Room no: " << l;
            cout << ":-- Vacant Room --: "<< thirdfloor_node->room_capacity << "| ";
        }
        else
		{
            l++;
            cout << " Room no: " << l;
            cout << "\t Already Booked by: "<< name_save[l-1][2];
        }
        cout << " " << endl;
        cout << endl;
        created_node = created_node->next;
        secondfloor_node = secondfloor_node->next;
        thirdfloor_node = thirdfloor_node->next;
    }
    for (int i = 0; i < 60; i++)
	{
        cout << "--";
    }
    cout << endl;
}

int main()
{
    hostel management;
    int choice, floorcheck;
    char ch;
    string namecheck;
    HostelManage manage;
    cout << "Welcome to Hostel Booking System" << endl;

    char loginChoice;
    do {
        cout << "Do you have an account? (Y/N): ";
        cin >> loginChoice;

        if (loginChoice == 'N' || loginChoice == 'n') 
		{
            manage.registerUser();
        } 
		else if (loginChoice == 'Y' || loginChoice == 'y') 
		{
            if (!manage.loginUser()) 
			{
                continue;
            }
        } 
		else 
		{
            cout << "Invalid choice. Please enter Y or N." << endl;
            continue;
        }
        break; 
    } while (true);
    management.create();
    do
	{
        cout << "1. Display Current Status of Rooms" << endl;
        cout << "2. Book a Room for 1 person." << endl;
        cout << "3. Book a Room for 2 person." << endl;
        cout << "4. Book a Room for 3 person." << endl;
        cout << "5. Cancel a Room" << endl;
        cout << "6. Search a Name" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
		{
            case 1:
                management.display();
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
        cout << "Do You want to Continue (Y/N): ";
        cin >> ch;
        cout << endl;
    }
	while(ch == 'Y' || ch == 'y');
    return 0;
}
