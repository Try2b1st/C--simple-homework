//
// Created by 下水道的小老鼠 on 2023/6/13.
//

#ifndef UNTITLED_USERCONTROLLER_H
#define UNTITLED_USERCONTROLLER_H

#include <regex>

using namespace std;

class UserController {
public:
    static bool UserIsAdmin(string userName, string passWord) {
        //定义正则表达式
        regex regEx("[ _`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。，、？\n\r\t]");

        //对用户名是否是包含特殊字符
        bool result = regex_search(userName, regEx);
        if (result) {
            return false;
        }

        if (userName == "wsRoot" && passWord == "123456789") {
            return true;
        } else {
            return false;
        }

    }
};

#endif //UNTITLED_USERCONTROLLER_H
