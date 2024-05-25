#include <iostream>
#include <stdexcept>
using namespace std;

class Patient {
protected:
    int id;
    string name;
    int age;

public:
    Patient() {
        id = 1;
        name = "Maxwell";
        age = 28;
    }

    void setId(int id) {
        if (id <= 0) throw invalid_argument("Invalid ID: ID must be greater than 0");
        this->id = id;
    }

    void setAge(int age) {
        if (age <= 20) throw invalid_argument("Invalid Age: Age must be greater than 20");
        this->age = age;
    }

    void show() {
        cout << "Patient id is: " << id << endl;
        cout << "Patient name is: " << name << endl;
        cout << "Patient age is: " << age << endl;
    }
};

class MedicalRecord : public Patient {
protected:
    int patientid;
    string treatment;
    string test;

public:
    void Medical() {
        patientid = 10;
        treatment = "Fever";
        test = "Test is OK";
    }

    void show() {
        cout << "Medical Record of Patient id is: " << patientid << endl;
        cout << "Treatment of Patient is: " << treatment << endl;
        cout << "Test of Patient is: " << test << endl;
        Patient::show();
    }
};

class Doctor : public MedicalRecord {
protected:
    int d_id;
    string d_name;
    string specialization;

public:
    void input() {
        d_id = 56;
        d_name = "ALEX";
        specialization = "Dermatologist";
    }

    void display() {
        cout << "Doctor id is: " << d_id << endl;
        cout << "Doctor name is: " << d_name << endl;
        cout << "Doctor specialization is: " << specialization << endl;
    }
};

class Appointment : public Doctor {
private:
    int a_id;
    string location;
    string reason;

public:
    void Appoint(int x, string y, string z) {
        a_id = x;
        location = y;
        reason = z;
    }

    void print() {
        cout << "Appointment id is: " << a_id << endl;
        cout << "Location is: " << location << endl;
        cout << "Reason is: " << reason << endl;
    }
};

int main() {
    Appointment aa;
    aa.Medical();
    aa.show();
    aa.input();
    aa.display();
    aa.Appoint(3, "Multan", "Micro Needling");
    aa.print();

    while (true) {
        try {
            int userId;
            int userAge;
            cout<<"Enter a valid user age:" ;
            cin>>userAge;
            cout << "Enter a valid patient ID: ";
            cin >> userId;
            aa.setId(userId);
            aa.setAge(userAge);
            break;  // Exit loop if no exception is thrown
        } catch (const invalid_argument &e) {
            cerr << "Error: " << e.what() << ". Please try again." << endl;
        }
    }

    return 0;
}
