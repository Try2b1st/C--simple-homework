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
    //写入功能--测试
    //CEmployee cEmployee("wgz","Men","CMgr",BDay(2004,12,05),9000.0);
    //vector<CEmployee> cEmployees;
    //cEmployees.push_back(cEmployee);
    //FileController::writeEmployeeToFile(cEmployees,R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //按名字删除--测试
    //string name = "wgz";
    //CEmployee::deleteEmployeeFromFile(name,R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //按名字修改--测试
    //CEmployee cEmployee("wz", "Men", "CMgr", BDay(2004, 12, 05), 6000.0);
    //CEmployee::UpdateEmployeeFromFile("wgz", cEmployee, R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //按名字查询，返回查询到的员工信息 --测试
    //optional<CEmployee> cEmployee = FileController::searchByNameFormFile("wz", R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //cEmployee->printData();


    //读文件--测试
    //vector<CEmployee> employees = FileController::readEmployeesFromFile(R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //for (CEmployee &employee: employees) {
    //    employee.printData();
    //    std::cout << "------" << std::endl;
    //}

    //根据员工职位查询员工 --测试
    //vector<CEmployee> cEmployees = FileController::searchByTypeFromFile("CMgr",R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
    //for(CEmployee &cEmployee: cEmployees){
    //    cEmployee.printData();
    //    cout << "==========" <<endl;
    //}

    //按名字输出薪资 --测试
    //FileController::getSalaryByFile("post",R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");

    //用户是否为管理员 --测试
    string userName;
    string password;
    cout << "请输入用户名：" << endl;
    getline(cin, userName);
    cout << "请输入密码：" << endl;
    getline(cin, password);

    cout << "你输入的用户名是：" << userName << endl;
    cout << "你输入的密码是：" << password << endl;

    bool result = UserController::UserIsAdmin(userName, password);
    if (result) {
        cout << "你是本系统的管理员" << endl;
    } else {
        cout << "你不是本系统的管理员" << endl;
    }


    return 0;
}
