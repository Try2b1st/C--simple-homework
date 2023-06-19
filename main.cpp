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

    string name;
    string sex;
    string kind;
    BDay bDay = BDay(0, 0, 0);
    double totalSalary;
    string isAdd = "y";

    if (result) {
        int chooseId = 0;
        while (chooseId != 7) {
            cout << "=============== 你是本系统的管理员 ===============" << endl;
            cout << "1.将员工数据写入文件." << endl;
            cout << "2.按名字从文件中删除员工信息." << endl;
            cout << "3.按名字从文件中修改员工信息" << endl;
            cout << "4.按名字从文件中查询员工信息" << endl;
            cout << "5.按职位从文件中查询员工信息" << endl;
            cout << "6.输出薪资" << endl;
            cout << "7.退出系统" << endl;
            cout << "请输入你的选择：" << endl;
            cin >> chooseId;
            cin.ignore();


            if (chooseId == 1) {
                vector<CEmployee> cEmployees;

                while (isAdd == "y") {
                    cout << "请输入员工的姓名：";
                    getline(cin, name);
                    cout << "请输入员工的性别：";
                    getline(cin, sex);
                    cout << "请输入员工的类型：";
                    getline(cin, kind);
                    cout << "请输入生日的日期、月份和年份：\n";
                    cout << "日期：";
                    cin >> bDay.day;
                    cin.ignore();

                    cout << "月份：";
                    cin >> bDay.month;
                    cin.ignore();

                    cout << "年份：";
                    cin >> bDay.year;
                    cin.ignore();

                    cout << "请输入员工总工资：";
                    cin >> totalSalary;
                    cin.ignore();

                    CEmployee cEmployee(name, sex, kind, bDay, totalSalary);
                    cEmployees.push_back(cEmployee);

                    cout << "是否还要添加员工?(y/n)" << endl;
                    cin >> isAdd;
                    cin.ignore();


                    if (isAdd != "y") {
                        isAdd = "n";
                    }
                }

                FileController::writeEmployeeToFile(cEmployees,
                                                    R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
            } else if (chooseId == 2) {
                cout << "请输入员工的姓名：";
                getline(cin, name);
                FileController::deleteEmployeeFromFile(name,
                                                       R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                cout << "删除成功" << endl;
            } else if (chooseId == 3) {
                cout << "请输入员工的姓名：";
                getline(cin, name);
                CEmployee cEmployee1 = FileController::searchByNameFormFile(name,
                                                                            R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)").value();
                cEmployee1.printData();
                string choose = "n";

                cout << "是否要修改员工性别(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "请输入员工的性别：";
                    getline(cin, sex);
                    choose = "n";
                }

                cout << "是否要修改员工类型(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "请输入员工的类型：";
                    getline(cin, kind);
                    choose = "n";
                }

                cout << "是否要修改员工生日(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "请输入生日的日期、月份和年份：\n";
                    cout << "日期：";
                    cin >> bDay.day;
                    cout << "月份：";
                    cin >> bDay.month;
                    cout << "年份：";
                    cin >> bDay.year;
                    choose = "n";
                }

                cout << "是否要修改员工工资(y/n)" << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << "请输入员工总工资：";
                    cin >> totalSalary;
                    choose = "n";
                }

                FileController::UpdateEmployeeFromFile("wgz", cEmployee1,
                                                       R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
            } else if (chooseId == 4) {
                cout << "请输入员工的姓名：";
                getline(cin, name);
                CEmployee cEmployee2 = FileController::searchByNameFormFile("wz",
                                                                            R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)").value();
                cEmployee2.printData();
            } else if (chooseId == 5) {
                string type;
                cout << "1.CManager：" << endl;
                cout << "2.CMgr" << endl;
                cout << "3.CWage" << endl;
                cout << "4.CSales" << endl;
                cout << "选择员工职位：" << endl;
                getline(cin,type);
                vector<CEmployee> cEmployees1 = FileController::searchByTypeFromFile(type,
                                                                                     R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                for (CEmployee &cEmployee3: cEmployees1) {
                    cEmployee3.printData();
                }
            } else if (chooseId == 6) {
                string type;
                cout << "1.kind：" << endl;
                cout << "2.name" << endl;
                cout << "3.money" << endl;
                cout << "选择输出类型：" << endl;
                getline(cin,type);
                FileController::getSalaryByFile(type,
                                                R"(D:\C or C++\C++\Employees\Employees-management-system\C--simple-homework\employee.data)");
                cout << "输出到了salary.data文件中" << endl;
            } else {
                cout << "没有这个选项！" << endl;
            }
        }
    } else {
        cout << "你不是本系统的管理员" << endl;
    }


    return 0;
}
