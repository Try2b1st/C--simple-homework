//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef untitled_SALES_H
#define untitled_SALES_H

#include "CEmployee.h"
#include <iostream>
#include <string>

using namespace std;

class CSales : public CEmployee {
private :
    double total;                //销售总额
    double percent;            //销售提成
public:
    //重载构造函数：参数自定义
    CSales(const char *name, const char *sex, const char *kind, BDay birthday, double salesTotal, double salesPercent)
            : total(salesTotal), percent(salesPercent),
              CEmployee(name, sex, kind, birthday, (salesTotal * salesPercent)) {};

    //输入销售员信息
    void inputData(){
        std::cout << "Please enter salesperson information:" << std::endl;
        std::cout << "salesTotal: ";
        std::cin >> total;
        std::cout << "salesPercent: ";
        std::cin >> percent;
    };

    //输出销售员信息
    void printData() {
        cout << "Name: " << getName() << endl;
        cout << "Sex: " << getSex() << endl;
        cout << "Kind: " << getKind() << endl;
        cout << "Birthday: " << getBirthday().year << "-" << getBirthday().month << "-" << getBirthday().day << endl;
        cout << "Sales Total: " << total << endl;
        cout << "Sales Percent: " << percent << endl;
        cout << "TotalSalary: " << getTotalSalary() << endl;
    };

    //计算销售员月薪：_salary=total*percent
    void computePay() {
        cout << "computePay = " << total * percent;
    };

    double getComputePay() const {
        return total * percent;
    }
    //析构函数
    ~ CSales() override = default;
};

#endif //untitled_SALES_H
