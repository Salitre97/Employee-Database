#include <iostream>
#include <vector>

using namespace std;

class Employee{
    public:
    Employee(string n,  string j, double w){
        setWages(w);
        setJobTitle(j);
        setName(n);
    }
    
void setName(string n){
    name = n;
}

void setWages(double w){
        if(w < 0){
            cout << "Invalid input:" << endl;
            cout << "Input value cannot be less than 0" << endl;
            return;
        }
       wages = w;
}
    
    
void setJobTitle(string title){
        job_title = title;
    
}
    
string getJobTitle() const {
        return job_title;
}  
    
double getWages() const {
        return wages;
}
string getName() const {
    return name;
}

    private:
    double wages;
    string job_title;
    string name; //hourly
    
};
double calcTotalWages(vector<Employee> E);

int main(){
    
    vector<Employee> Employees;
    string another;
    int input;
    
        Employee e("Cristian", "Engineer", 80.00);
        Employee e1("Jacob", "Electrician", 60.00);
        Employee e2("Josh", "clerk", 40.00);
        Employee e3("David", "Dentist", 80.00);
        Employee e4("John", "Youtuber", 200.75);
    
    
        Employees.push_back(e);
        Employees.push_back(e1);
        Employees.push_back(e2);
        Employees.push_back(e3);
        Employees.push_back(e4);
    
    cout << "The purpose of this application is to calculate the total amount of wages that employees are to be paid for the week" << endl;
    cout << endl;
    
    do{
        cout << "Please choose an option: " << endl;
        cout << endl;
        
        cout << "1. Print list of employees: " << endl;
        cout << "2. Calculate total wages: " << endl;
        cout << "3. Exit application: " << endl;
        cin >> input; 
        
        int list_num = 1;
        
        if(input == 1){
            for(int i = 0; i < Employees.size(); i++){
                cout << list_num << ". ";
                cout << "Name: " << Employees.at(i).getName() << endl;
                cout << "   Job Title: " << Employees.at(i).getJobTitle() << endl;
                cout << "   Hourly wages: " << "$" << Employees.at(i).getWages() << endl;
                cout << endl;
                list_num++;
            }
        }
        else if(input == 2) {
                calcTotalWages(Employees);
                cout << endl;
        }
        else if(input == 3){
                break;
        }
    
    cout << "To add a new employee press \"y\", to exit application enter any input: " << endl; 
    cin >> another;
    
    } while(another == "y");
    
    
    return 0;
}

double calcTotalWages(vector<Employee> E){
    double hrs = 0;
    double sum = 0;
    int list_num = 1;
    for(int i = 0; i < E.size(); i++){
        cout << "Please enter the total number of hours worked by employee: " << endl;
        cout << list_num << ". ";
        cout << "Employee Name: " << E.at(i).getName() << endl;
        cin >>  hrs;
        if(hrs < 0){
             do{
                cout << "Invalid input!!! \nInput value must be greater than zero. " << endl;
                cout << "Please enter the total number of hours worked by employee: " << endl;
                cout << list_num << ". ";
                cout << "Employee Name: " << E.at(i).getName() << endl;
                cin >>  hrs;
            }while(hrs < 0);
        } // 
        list_num++;
        sum += hrs * E.at(i).getWages();
    }
    cout << "Total wages: $" << sum; 
}