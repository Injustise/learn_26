### 一些笔记
1. - 函数名前 `const` ：函数**返回值是常量**，只读不改。
   - 对于返回非引用、非指针的普通类型（如 `int`、`double`）时，因为**返回的本身就是右值**（临时对象），本来就不允许赋值,所以前加 `const` **几乎没有实际意义**：
        ``` c++
        class Person {
        private:
            string name;
        public:
            void set_name(string n) {
                name = n;
            }
            string get_name() { //前加与不加 const 都无法做到修改，加只不过下面的赋值语句报错而已
                return name;
            }
        };
        ```
        ``` c++
        Person p;
        p.set_name("John");
        p.get_name() = "Alice"; //返回的是右值，无效修改
        cout << p.get_name(); //依旧输出 John
        ``` 
    - 对于返回引用或指针时，因为**返回的本身可以作为左值**，所以前加 `const` 能够**保护引用或指针的对象只读不改**：
        ``` c++
        const string &get_name() { 
            return name;
        }
        ``` 
        ``` c++
        Person p;
        p.set_name("John");
        //p.get_name() = "Alice"; //错误，返回的是左值值，本可以修改，但前加 cosnt 不允许修改
        ```
2. - （成员）函数名后 `const` ：（成员）函数本身**不允许修改当前对象的成员变量（除 `mutable` 外）**。
   - 注意：被 `mutable` 修饰的成员变量，在 `const` 成员函数中可以修改：
        ``` c++
        class Person {
        private:
            string name;
            mutable int age;
        public:
            void set_name(string n) {
                name = n;
            }
            string get_name() const {
                age++; //正确，mutable 类型的成员变量允许修改
                //name = "Alice"; //错误，其他类型的成员变量不允许修改
                return name;
            }
        };
        ```
   - **`const` 修饰的对象只能调用 `const` 成员函数**：
        ``` c++
        void print(const Person &p) { 
            string n = p.get_name(); //这里的 p 只能调用后加 const 的成员函数
            cout << n << endl;
        } 
        ``` 