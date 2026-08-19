#include "Staffsystem.h"

Staffsystem::Staffsystem() : m_num(0), StaffArray(nullptr) {}

void Staffsystem::ShowMenu() {
    cout << "***********************************" << endl;
    cout << "****** 欢迎使用职工管理系统！******" << endl;
    cout << "****** 添加职工信息请输入：1 ******" << endl;
    cout << "****** 显示职工信息请输入：2 ******" << endl;
    cout << "****** 删除职工信息请输入：3 ******" << endl;
    cout << "****** 修改职工信息请输入：4 ******" << endl;
    cout << "****** 查询职工信息请输入：5 ******" << endl;
    cout << "****** 按照编号排序请输入：6 ******" << endl;
    cout << "****** 清空所有文档请输入：7 ******" << endl;
    cout << "****** 退出管理系统请输入：0 ******" << endl;
    cout << "***********************************" << endl;
}

bool Staffsystem::CheckEmpty() {
    return this->m_num;
}

void Staffsystem::ShowStaff() {
    if(!this->CheckEmpty()) {
        cout << "职工列表为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < this->m_num; i++) {
        this->StaffArray[i]->showifo();
    }
    system("pause");
    system("cls");
}

void Staffsystem::AddStaff() {
    cout << "请输入添加职工数量：" << endl;
    int addNum;
    while(cin >> addNum) {
        if(addNum > 0) break;
        cout << "输入有误，请重新输入！" << endl;
    }


    int newNum = this->m_num + addNum;
    Staff **NewArray = new Staff* [newNum];
 
    
    for(int i = 0; i < this->m_num; i++) {
        NewArray[i] = this->StaffArray[i];
    }
    delete[] this->StaffArray;

    int id, pos;
    string name;
    Staff *worker = nullptr;
    for(int i = 0; i < addNum; i++) {
        cout << "请输入第 " << i+1 << " 位添加职工的编号：" << endl;
        cin >> id;

        cout << "请输入第 " << i+1 << " 位添加职工的姓名：" << endl;
        cin >> name;

        cout << "请输入第 " << i+1 << " 位添加职工的职位：" << endl;
        cout << "1：老板  2：经理  3：普通员工" << endl;

        while(cin >> pos) {
            if(pos == 1) {
                worker = new Boss(id, name, pos);
                break;
            }
            else if(pos == 2) {
                worker = new Manager(id, name, pos);
                break;
            }
            else if(pos == 3) {
                worker = new Employee(id, name, pos);
                break;
            } 
            else cout << "输入有误，请重新输入！" << endl;           
        }
        NewArray[this->m_num+i] = worker;
    }
        
    this->StaffArray = NewArray;
    this->m_num = newNum;

    cout << "成功添加 " << addNum << " 位职工！" << endl;
    system("pause");
    system("cls");
}

int Staffsystem::FindStaff() {

    cout << "请选择查找方式：" << endl;
    cout << "1：编号查找  2：姓名查找" << endl;
    int confirm;
    while(cin >> confirm) {
        if(confirm == 1 || confirm == 2) break;
        cout << "输入有误，请重新输入！" << endl;
        cout << "1：编号查找  2：姓名查找" << endl;
    }
    if(confirm == 1) {
        cout << "请输入查找职工的编号：" << endl;
        int id;
        cin >> id;
        for(int i = 0; i < this->m_num; i++) {
            if(this->StaffArray[i]->m_id == id) return i;
        }
        return -1;
    } 
    else {
        cout << "请输入查找职工的姓名：" << endl;
        string name;
        cin >> name;
        for(int i = 0; i < this->m_num; i++) {
            if(this->StaffArray[i]->m_name == name) {
                cout << "确认是否为该职工？" << endl;
                this->StaffArray[i]->showifo();
                cout << "1：是  0：否" << endl;
                int confirm;
                while(cin >> confirm) {
                    if(confirm == 1 || confirm == 0) break;
                    cout << "输入有误，请重新输入！" << endl;
                    cout << "1：是  0：否" << endl;
                }
                if(confirm) return i;
                else cout << "继续查找中..." << endl;
            }
        }
        return -1; 
    }             
}

// int Staffsystem::FindStaff_id(int id) {
//     for(int i = 0; i < this->m_num; i++) {
//         if(this->StaffArray[i]->m_id == id) return i;
//     }
//     return -1;
// }

// int Staffsystem::FindStaff_name(string name) {
//     for(int i = 0; i < this->m_num; i++) {
//         if(this->StaffArray[i]->m_name == name) {
//             cout << "确认是否为该职工？" << endl;
//             this->StaffArray[i]->showifo();
//             cout << "1：是  0：否" << endl;
//             int confirm;
//             while(cin >> confirm) {
//                 if(confirm == 1 || confirm == 0) break;
//                 cout << "输入有误，请重新输入！" << endl;
//                 cout << "1：是  0：否" << endl;
//             }
//             if(confirm) return i;
//             else cout << "继续查找中..." << endl;
//         }
//     }
//     return -1;
// }

void Staffsystem::DeleteStaff() {
    if(!this->CheckEmpty()) {
        cout << "职工列表为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    
    int i = Staffsystem::FindStaff();
    if(i == -1) {
        cout << "查无此人，删除失败！" << endl;
    } else {
        
        cout << "删除成功！" << endl;
    }

    system("pause");
    system("cls");
}