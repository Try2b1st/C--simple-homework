#include <iostream>

#include "CEmployee.h"
#include "CManager.h"
#include "CMgr.h"
#include "CSales.h"
#include "CWage.h"
#include "FileController.h"
#include "UserController.h"

using namespace std;

int main() {
    //д�빦��--����
    //CEmployee cEmployee("wgz","Men","CMgr",BDay(2004,12,05),9000.0);
    //vector<CEmployee> cEmployees;
    //cEmployees.push_back(cEmployee);
    //FileController::writeEmployeeToFile(cEmployees,R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //������ɾ��--����
    //string name = "wgz";
    //CEmployee::deleteEmployeeFromFile(name,R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //�������޸�--����
    //CEmployee cEmployee("wz", "Men", "CMgr", BDay(2004, 12, 05), 6000.0);
    //CEmployee::UpdateEmployeeFromFile("wgz", cEmployee, R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //�����ֲ�ѯ�����ز�ѯ����Ա����Ϣ --����
    //optional<CEmployee> cEmployee = FileController::searchByNameFormFile("wz", R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //cEmployee->printData();


    //���ļ�--����
    //vector<CEmployee> employees = FileController::readEmployeesFromFile(R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //for (CEmployee &employee: employees) {
    //    employee.printData();
    //    std::cout << "------" << std::endl;
    //}

    //����Ա��ְλ��ѯԱ�� --����
    //vector<CEmployee> cEmployees = FileController::searchByTypeFromFile("CMgr",R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //for(CEmployee &cEmployee: cEmployees){
    //    cEmployee.printData();
    //    cout << "==========" <<endl;
    //}

    //���������н�� --����
    //FileController::getSalaryByFile("post",R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

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
    if (result) {
        cout << "���Ǳ�ϵͳ�Ĺ���Ա" << endl;
    } else {
        cout << "�㲻�Ǳ�ϵͳ�Ĺ���Ա" << endl;
    }


    return 0;
}
