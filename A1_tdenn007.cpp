#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

using namespace std; 

struct booktype
{
    string book_title;
    string author_name;
    string year;
    string language; 
    string genre;
};

struct authortype
{
    string name;
    string DOB; 
    string notable_book; 
};

struct matchedtype
{
    string author_name; 
    string nationality; 
    string book_title; 

};

void ReadBookFile(vector<booktype>& book_list)
{
    string filename = "Books.txt";
    int counter = 0; 

    ifstream inFile; 
    inFile.open(filename);

    inFile >> counter; 

    for (int i = 0; i < counter; i++)
    {
        inFile >> book_list[i].book_title
                >> book_list[i].author_name
                >> book_list[i].year
                >> book_list[i].language
                >> book_list[i].genre; 

    }

}

void ReadAuthorFile(vector<authortype>& author_list)
{
    string filename = "authors.txt";
    int counter = 0; 

    ifstream inFile; 
    inFile.open(filename);

    inFile >> counter; 

    for (int i = 0; i < counter; i++)
    {
        inFile >> author_list[i].name
                >> author_list[i].DOB
                >> author_list[i].notable_book;
    }

}

void PrintBookList(const vector<booktype>& book_list)
{
    for (auto i: book_list)
    {
        cout << i.book_title
                << i.author_name
                << i.year
                << i.language
                << i.genre
                << endl;
    }
    
}

void PrintAuthorList(const vector<authortype>& author_list)
{
    for (auto i: author_list)
    {
        cout << i.name
                << i.DOB
                << i.notable_book
                << endl;
    }
    
}

vector<matchedtype> GetMatchedList(const vector<authortype>& author_list,const vector<booktype>& book_list)
{
    vector<matchedtype> matched_list; 
    int counter = 0;
   
    for (auto i: author_list)
    {
        for(auto j: book_list)
        {
            if (i.name == j.author_name)
            {
                matched_list[counter].author_name = i.name;
                matched_list[counter].book_title = j.book_title;
                matched_list[counter].nationality = j.language;
                counter++;
            }
            
        }
    }

    return matched_list;
}

void PrintMatchedList(const vector<authortype>& author_list,const vector<booktype>& book_list)
{
    vector<matchedtype> matched_list = GetMatchedList(author_list,book_list);

    for(auto i: matched_list)
    {
        cout << i.author_name <<"    "
            << i.nationality << "   "
            << i.book_title << endl;
    }
}

void DisplayOptions()
{
    cout <<"1. Print Books" << endl;
    cout << "2. Print Authors" << endl;
    cout << "3. Print Matches" << endl;
    cout << "4. Terminate" << endl; 
    cout <<"Enter Selection: "; 
}

void Menu ()
{
    char action;
    bool terminate = false;
    vector<booktype> book_list;
    vector<authortype> author_list;
    ReadBookFile(book_list);
    ReadAuthorFile(author_list);

    do
    {
        DisplayOptions();
        cin >> action;

        switch (action)
        {
            case '1':
                PrintBookList(book_list);
                break;

            case '2':
                PrintAuthorList(author_list);
                break;

            case '3':
                PrintMatchedList(author_list,book_list);
                break;

            case '4':
                terminate = true;

            default:
                cout << "incorrect input" << endl;
                break;
        }
    } while (terminate != true);
    
    
}

int main ()
{
    Menu();
    return 0;
}