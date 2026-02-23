#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct expenseTracker 
{
    string title;
    float amount;
    string category;
}exp;

vector<expenseTracker> expense;

void add_expense(vector<expenseTracker> &expen){
    exp e;
    cout << "Add Expenses"<<endl;
    cout<< "enter title: ";
    cin >> e.title;
    cout << "enter the amount: ";
    cin>> e.amount;
    cout<<"enter the category: ";
    cin >> e.category;

    expen.push_back(e);
    cout << "expense added!"<<endl;
}
void show_expense(vector<expenseTracker> &expen){
    cout<<"your expenses are: "<< expen.size()<<endl;

    for(auto a: expen){
        cout<<"title: "<<a.title <<endl;
        cout <<"amount: "<<a.amount <<endl;
        cout <<"category: "<< a.category<<endl;
        cout<< "--------------\n"<<endl;
    }
}

bool search_expense(vector<expenseTracker> &expen, string categ){
    bool present = false;
    for(auto a: expen){
        if(a.category == categ){
            cout<< a.title << endl;
            cout<< a.amount <<endl;
            cout<< a.category <<endl;
            present = true;
        }   
    } 
    if(present == false) cout<< "category not found."<< endl;
    return present;
}

void sum_expense(vector<expenseTracker> &expen){
    float sum = 0;
    for(auto a:expen){
        sum += a.amount;
    }
    cout <<"your total expense is " << sum <<"!"<<endl;
}

int main(){
    cout<< "===EXPENSE TRACKER===" <<endl;
    
    int choice = 0;
    vector<expenseTracker> expense;
    //cout <<"press 1 for adding new expense."<<endl <<"press 2 for viewing all expenses."<< endl<<"press 3 for searching any expense."<<endl<<"press 4 for summing up all the expenses."<<endl<<"press any other number for exiting."<<endl;
   
    //using do while loop.
        cout << "1.ADD EXPENSES\n";
        cout << "2.show expenses\n";
        cout << "3.search expenses\n";
        cout << "4.sum of all the expenses\n";
        cout << "5.exit\n";
    do{
        
        cout << "Enter choice:";
        cin >>choice;

        if(choice == 1){
            add_expense(expense);
            cout << endl;
        }
        else if(choice == 2){
            show_expense(expense);
            cout << endl;
        }
        else if(choice == 3){
            string categ;
            cout<<"enter the category to search: ";
            cin >> categ;
            search_expense(expense, categ);
            cout << endl;
        }
        else if(choice == 4){
            sum_expense(expense);
            cout << endl;
        }
    }while(choice != 5);

   return 0;
}