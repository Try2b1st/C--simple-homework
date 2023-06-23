#include <iostream>
#include <string>

#include "CEmployee.h"
#include "CManager.h"
#include "CMgr.h"
#include "CSales.h"
#include "CWage.h"
#include "FileController.h"
#include "UserController.h"

using namespace std;

int main() {

    //�û��Ƿ�Ϊ����Ա --����
    string userName;
    string password;
    cout << "�������û�����" << endl;
    getline(cin, userName);
    cout << "���������룺" << endl;
    getline(cin, password);
    cout << "��������û����ǣ�" << userName << endl;
    cout << "������������ǣ�" << password << endl;

    bool result = UserController::UserIsAdmin(userName, password);

    string name;
    string sex;
    string kind;
    BDay bDay = BDay(0, 0, 0);
    double totalSalary;
    string isAdd = "y";

    if (result) {
        int chooseId = 0;
        while (chooseId != 8) {
            cout << "=============== ���Ǳ�ϵͳ�Ĺ���Ա ===============" << endl;
            cout << "1.��Ա������д���ļ�." << endl;
            cout << "2.�����ִ��ļ���ɾ��Ա����Ϣ." << endl;
            cout << "3.�����ִ��ļ����޸�Ա����Ϣ" << endl;
            cout << "4.�����ִ��ļ��в�ѯԱ����Ϣ" << endl;
            cout << "5.��ְλ���ļ��в�ѯԱ����Ϣ" << endl;
            cout << "6.���н��" << endl;
            cout << "7.���ļ��ж�ȡȫ��Ա������" << endl;
            cout << "8.�˳�ϵͳ" << endl;
            cout << "���������ѡ��" << endl;
            cin >> chooseId;
            cin.ignore();


            if (chooseId == 1) {
                vector<CEmployee> cEmployees;

                while (isAdd == "y") {
                    cout << "������Ա����������";
                    getline(cin, name);
                    cout << "������Ա�����Ա�";
                    getline(cin, sex);
                    cout << "������Ա�������ͣ�";
                    getline(cin, kind);
                    cout << "���������յ����ڡ��·ݺ���ݣ�\n";
                    cout << "���ڣ�";
                    cin >> bDay.day;
                    cin.ignore();

                    cout << "�·ݣ�";
                    cin >> bDay.month;
                    cin.ignore();

                    cout << "��ݣ�";
                    cin >> bDay.year;
                    cin.ignore();

                    cout << "������Ա���ܹ��ʣ�";
                    cin >> totalSalary;
                    cin.ignore();

                    CEmployee cEmployee(name, sex, kind, bDay, totalSalary);
                    cEmployees.push_back(cEmployee);

                    cout << "�Ƿ�Ҫ���Ա��?(y/n)" << endl;
                    cin >> isAdd;
                    cin.ignore();


                    if (isAdd != "y") {
                        isAdd = "n";
                    }
                }

                FileController::writeEmployeeToFile(cEmployees,
                                                    R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
            } else if (chooseId == 2) {
                cout << "������Ա����������";
                getline(cin, name);
                FileController::deleteEmployeeFromFile(name,
                                                       R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                cout << "ɾ���ɹ�" << endl;
            } else if (chooseId == 3) {
                cout << "������Ա����������";
                getline(cin, name);
                CEmployee cEmployee1 = FileController::searchByNameFormFile(name,
                                                                            R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)").value();
                cEmployee1.printData();
                string choose = "n";

                cout << "�Ƿ�Ҫ�޸�Ա���Ա�(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "������Ա�����Ա�";
                    cin >> sex;
                    choose = "n";
                }

                cout << "�Ƿ�Ҫ�޸�Ա������(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "������Ա�������ͣ�";
                    getline(cin, kind);
                    choose = "n";
                }

                cout << "�Ƿ�Ҫ�޸�Ա������(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "���������յ����ڡ��·ݺ���ݣ�\n";
                    cout << "���ڣ�";
                    cin >> bDay.day;
                    cout << "�·ݣ�";
                    cin >> bDay.month;
                    cout << "��ݣ�";
                    cin >> bDay.year;
                    choose = "n";
                }

                cout << "�Ƿ�Ҫ�޸�Ա������(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "������Ա���ܹ��ʣ�";
                    cin >> totalSalary;
                    choose = "n";
                }

                FileController::UpdateEmployeeFromFile(name, cEmployee1,
                                                       R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
            } else if (chooseId == 4) {
                cout << "������Ա����������";
                getline(cin, name);
                CEmployee cEmployee2 = FileController::searchByNameFormFile("wz",
                                                                            R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)").value();
                cEmployee2.printData();
            } else if (chooseId == 5) {
                string type;
                cout << "1.CManager��" << endl;
                cout << "2.CMgr" << endl;
                cout << "3.CWage" << endl;
                cout << "4.CSales" << endl;
                cout << "ѡ��Ա��ְλ(��Ҫ��������)��" << endl;
                getline(cin, type);
                vector<CEmployee> cEmployees1 = FileController::searchByTypeFromFile(type,
                                                                                     R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                for (CEmployee &cEmployee3: cEmployees1) {
                    cEmployee3.printData();
                }
            } else if (chooseId == 6) {
                string type;
                cout << "1.kind��" << endl;
                cout << "2.name" << endl;
                cout << "3.salary" << endl;
                cout << "ѡ���������(��Ҫ��������)��" << endl;
                getline(cin, type);
                FileController::getSalaryByFile(type,
                                                R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                cout << "�������salary.data�ļ���" << endl;
            } else if (chooseId == 7) {
                vector<CEmployee> cEmployees = FileController::readEmployeesFromFile(
                        R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                for (CEmployee cEmployee: cEmployees) {
                    cEmployee.printData();
                }
            } else {
                cout << "û�����ѡ�" << endl;
            }
        }
    } else {
        cout << "�㲻�Ǳ�ϵͳ�Ĺ���Ա" << endl;
    }


    return 0;
}
