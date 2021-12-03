// #include <iostream>
// #include <fstream>
// using namespace std;

// struct student{
//     int roll;
//     char name[30];
//     char div;
//     char address[30];
//     float percent;
//     char grade;
//     dob sdob;
// };

// struct dob{
//     int day,month,year;
// };

// class seqfile{
//     student s_rec;
//     ostream outfile;
//     istream infile;

//     public:
//     void create();
//     void display();
//     void add();
//     void search();
//     void modify();
//     void del();
// };

// void seqfile::create(){
//     ofstream outfile("student.txt");
//     if(!outfile){
//         cout << "Cannot open file.";
//     }
//     cout << "File opened";
// }

// void seqfile::add(){
//     char add;
//     ofstream outfile("student.txt");
//     cout << "Enter the data to be entered: ";
//     cin >> add;
//     cout << endl;
//     outfile << add;
//     outfile.close();
// }

// void seqfile::

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <sstream>

int main(){
    // creating file and checking if it is opened
    // ofstream file_name_used_in_code("file_name")
    ofstream file("demo.txt");
    if(!file){
        cout << "File cannot open";
    }
    cout << "File opened";

    // adding data to file
    char add,ch;
    cout << "Enter the data to be added: ";
    cin >> add;
    file << add;
    file.close();
    
    // reading a file
    ifstream infile("demo.txt");
    string line;
    int total=0;
    // reading line 
    while(!infile.eof()){
        getline(infile,line);
        // cout << line;
        // converting line string into int
        stringstream(line) >> total;
        cout << line << endl;
        cout << total +1 << endl;
    }

    // reading char by char
    // while(!infile.get(ch)){
    //     infile.get(ch);
    //     cout << ch;
    // }
// closing the file
    infile.close();
}