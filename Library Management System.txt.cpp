#include <iostream>
#include <fstream>

using namespace std;

// =====================================
// BOOK CLASS
// =====================================

class Book
{
public:
    int bookId;
    string title;
    string author;
    bool isIssued;
    float fine;
    int issueDay;
    int returnDay;
    
};

// =====================================
// MEMBER CLASS
// =====================================

class Member
{
public:
    int memberId;
    string name;
};

// =====================================
// ARRAYS
// =====================================

Book books[100];
Member members[100];

// =====================================
// GLOBAL VARIABLES
// =====================================

int totalBooks = 0;
int totalMembers = 0;

// =====================================
// FUNCTION DECLARATIONS
// =====================================

bool login();
void addBook();
void showBooks();
void searchBook();
void saveToFile();
void loadFromFile();
void issueBook();
void returnBook();
void deleteBook();
void updateBook();
void showStatistics();

// =====================================
// LOGIN SYSTEM
// =====================================

bool login()
{
    string username;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (username == "admin" &&
        password == "1234")
    {
        cout << "\nLogin Successful!\n";

        return true;
    }

    else
    {
        cout << "\nInvalid Username Or Password!\n";

        return false;
    }
}


// =====================================
// MAIN FUNCTION
// =====================================

int main()
{
if (!login())
{
    return 0;
}
    int choice;
    
    loadFromFile();

    while (true)
    {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";

        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Update Book\n";
        cout << "8. Library Statistics\n";
        cout << "9. Exit\n";

        cout << "========================================\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addBook();
        }

        else if (choice == 2)
        {
            showBooks();
        }

        else if (choice == 3)
        {
            searchBook();
        }

        else if (choice == 4)
{
    issueBook();
}

else if (choice == 5)
{
    returnBook();
}
else if (choice == 6)
{
    deleteBook();
}

else if (choice == 7)
{
    updateBook();
}
else if (choice == 8)
{
    showStatistics();
}

else if (choice == 9)
{
    cout << "\nThank You For Using The System!\n";
    break;
}
        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}
// =====================================
// ADD BOOK FUNCTION
// =====================================

void addBook()
{
    cout << "\nEnter Book ID: ";
    cin >> books[totalBooks].bookId;
    
    for (int i = 0; i < totalBooks; i++)
{
    if (books[i].bookId ==
        books[totalBooks].bookId)
    {
        cout << "\nBook ID Already Exists!\n";
        return;
    }
}

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[totalBooks].title);

    cout << "Enter Author Name: ";
    getline(cin, books[totalBooks].author);

    books[totalBooks].isIssued = false;
    
    books[totalBooks].issueDay = 0;
    
    books[totalBooks].returnDay = 0;
    
    books[totalBooks].fine = 0;

    totalBooks++;
    
    saveToFile();

    cout << "\nBook Added Successfully!\n";
}


// =====================================
// SHOW BOOKS FUNCTION
// =====================================

void showBooks()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    cout << "\n=============== BOOK LIST ===============\n";

    for (int i = 0; i < totalBooks; i++)
    {
        cout << "\nBook " << i + 1 << endl;

        cout << "Book ID : "
             << books[i].bookId << endl;

        cout << "Title   : "
             << books[i].title << endl;

        cout << "Author  : "
             << books[i].author << endl;

        cout << "Status  : ";
        
        cout << "Fine    : ₹"
             << books[i].fine << endl;

        if (books[i].isIssued)
        {
            cout << "Issued\n";
        }
        
        if (books[i].isIssued)
{
    cout << "Return Day : "
         << books[i].returnDay << endl;
}

        else
        {
            cout << "Available\n";
        }
    }
}

// =====================================
// SEARCH BOOK FUNCTION
// =====================================

void searchBook()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID To Search: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            found = true;

            cout << "\n=========== BOOK FOUND ===========\n";

            cout << "Book ID : "
                 << books[i].bookId << endl;

            cout << "Title   : "
                 << books[i].title << endl;

            cout << "Author  : "
                 << books[i].author << endl;

            cout << "Status  : ";

            if (books[i].isIssued)
            {
                cout << "Issued\n";
            }

            else
            {
                cout << "Available\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found.\n";
    }
}

// =====================================
// ISSUE BOOK FUNCTION
// =====================================

void issueBook()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID To Issue: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            found = true;

            if (books[i].isIssued)
            {
                cout << "\nBook Already Issued.\n";
            }

            else
            {
                books[i].isIssued = true;
                
                cout << "Enter Issue Day: ";
                cin >> books[i].issueDay;

                books[i].returnDay =
                books[i].issueDay + 7;

                saveToFile();

                cout << "\nBook Issued Successfully!\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found.\n";
    }
}

// =====================================
// SAVE TO FILE FUNCTION
// =====================================

void saveToFile()
{
    ofstream file("books.txt");

    for (int i = 0; i < totalBooks; i++)
    {
        file << books[i].bookId << endl;

        file << books[i].title << endl;

        file << books[i].author << endl;

        file << books[i].isIssued << endl;
        
        file << books[i].fine << endl;
        
        file << books[i].issueDay << endl;

        file << books[i].returnDay << endl;
    }

    file.close();
}

// =====================================
// LOAD FROM FILE FUNCTION
// =====================================

void loadFromFile()
{
    ifstream file("books.txt");

    while (file >> books[totalBooks].bookId)
    {
        file.ignore();

        getline(file, books[totalBooks].title);

        getline(file, books[totalBooks].author);

        file >> books[totalBooks].isIssued;
        
        file >> books[totalBooks].fine;
        
        file >> books[totalBooks].issueDay;

        file >> books[totalBooks].returnDay;

        file.ignore();

        totalBooks++;
    }

    file.close();
}

// =====================================
// RETURN BOOK FUNCTION
// =====================================

void returnBook()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID To Return: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            found = true;

            if (!books[i].isIssued)
            {
                cout << "\nThis Book Was Not Issued.\n";
            }

            else
            {
                int currentDay;

                cout << "Enter Current Day: ";
                cin >> currentDay;

                if (currentDay > books[i].returnDay)
                {
                    int lateDays =
                    currentDay - books[i].returnDay;

                    books[i].fine =
                    lateDays * 10;

                    cout << "\nBook Returned Late!\n";

                    cout << "Late By : "
                         << lateDays << " Days\n";

                    cout << "Fine Amount : ₹"
                         << books[i].fine << endl;
                }

                else
                {
                    books[i].fine = 0;
                }

                books[i].isIssued = false;

                saveToFile();

                cout << "\nBook Returned Successfully!\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found.\n";
    }
}

// =====================================
// DELETE BOOK FUNCTION
// =====================================

void deleteBook()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID To Delete: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            found = true;

            for (int j = i; j < totalBooks - 1; j++)
            {
                books[j] = books[j + 1];
            }

            totalBooks--;

            saveToFile();

            cout << "\nBook Deleted Successfully!\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found.\n";
    }
}

// =====================================
// UPDATE BOOK FUNCTION
// =====================================

void updateBook()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID To Update: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            found = true;

            cin.ignore();

            cout << "\nEnter New Book Title: ";
            getline(cin, books[i].title);

            cout << "Enter New Author Name: ";
            getline(cin, books[i].author);

            saveToFile();

            cout << "\nBook Updated Successfully!\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found.\n";
    }
}

// =====================================
// LIBRARY STATISTICS FUNCTION
// =====================================

void showStatistics()
{
    if (totalBooks == 0)
    {
        cout << "\nNo Books Found.\n";
        return;
    }

    int issuedBooks = 0;
    int availableBooks = 0;

    float totalFine = 0;

    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i].isIssued)
        {
            issuedBooks++;
        }

        else
        {
            availableBooks++;
        }

        totalFine =
        totalFine + books[i].fine;
    }

    cout << "\n========== LIBRARY STATISTICS ==========\n";

    cout << "Total Books       : "
         << totalBooks << endl;

    cout << "Issued Books      : "
         << issuedBooks << endl;

    cout << "Available Books   : "
         << availableBooks << endl;

    cout << "Total Fine Amount : ₹"
         << totalFine << endl;
}