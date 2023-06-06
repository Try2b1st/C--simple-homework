//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef untitled_CMGR_H
#define untitled_CMGR_H


#include "CManager.h"
#include "CSales.h"

class CMgr : public CManager, public CSales {
//根据你的设计自定义类CMgr，月薪=固定工资+销售提成
//固定工资和销售提成的值自定义
private:
    // 固定工资
    double fixedSalary;
    // 销售提成
    double salesPercent;
public:
    CMgr(const char *name, const char *sex, const char *kind, BDay birthday, int lateDays, int leaveDays,
         double salesTotal, double salesPercent) :
            CManager(name, sex, kind, birthday, lateDays, leaveDays),
            CSales(name, sex, kind, birthday, salesTotal, salesPercent),
            fixedSalary(CManager::getComputePay()), salesPercent(CSales::getComputePay()) {};

    void computePay() {
        cout << "computePay = " << fixedSalary + salesPercent;
    }

    void setTotalSalary() {
        CManager::setTotalSalary(fixedSalary + salesPercent);
    }

    void printData() {

    }

    ~ CMgr() override = default;
};


#endif //untitled_CMGR_H
