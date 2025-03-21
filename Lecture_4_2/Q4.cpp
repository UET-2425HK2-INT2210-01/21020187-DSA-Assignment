#include <iostream>
using namespace std;

struct Student {
    int ID;
    string name;
    string class_name;
    Student* next;
};

class StudentManagement {
private:
    Student* head;

public:
    StudentManagement() : head(nullptr) {}

    //Insert fucntion
    void insert(int ID, const string& name, const string& class_name) {
        Student* newStudent = new Student;
        newStudent->ID = ID;
        newStudent->name = name;
        newStudent->class_name = class_name;
        newStudent->next = head;
        head = newStudent;
    }

    //Delete function
    void deleteStudent(int ID) {
        Student* current = head;
        Student* prev = nullptr;
        while (current != nullptr && current->ID != ID) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
    }

    //Print student information
    void infor(int ID) {
        Student* current = head;
        while (current != nullptr) {
            if (current->ID == ID) {
                cout << current->name << "," << current->class_name << endl;
                return;
            }
            current = current->next;
        }
        cout << "NA,NA" << endl;
    }

    ~StudentManagement() {
        while (head != nullptr) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentManagement sm;
    string command;
    
    while (getline(cin, command)) {
        if (command.find("Insert(") == 0) {
            int ID;
            size_t start = 7, mid1 = command.find(',', start), mid2 = command.find(',', mid1 + 1), end = command.find(')');
            ID = stoi(command.substr(start, mid1 - start));
            string name = command.substr(mid1 + 1, mid2 - mid1 - 1);
            string class_name = command.substr(mid2 + 1, end - mid2 - 1);
            sm.insert(ID, name, class_name);
        } else if (command.find("Delete(") == 0) {
            int ID = stoi(command.substr(7, command.size() - 8));
            sm.deleteStudent(ID);
        } else if (command.find("Infor(") == 0) {
            int ID = stoi(command.substr(6, command.size() - 7));
            sm.infor(ID);
        }
    }
    return 0;
}
