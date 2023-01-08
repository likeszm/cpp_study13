/*
* 名称: 继承测试
* 
* 收获:
* 1、对继承方式有了了解,知道了一般情况下只用public继承
* 2、由于构造函数不会被继承，派生类的构造函数的初始化列表可以直接调用基类的构造函数
* 3、还可以通过给基类的构造函数的参数赋默认值来避免报错
* 
*/

#include <iostream>
#define DEBUG
#ifdef DEBUG
std::string debug_str;
#endif // DEBUG


class Width_c
{
protected:
    double width_length;
public:
    //double width_length;
    Width_c(double len):width_length(len)               //可以内联
    { 
        #ifdef DEBUG
            debug_str = "Width_c::Width_c";
            std::clog << "___LOG : running " + debug_str + "() " << std::endl;
        #endif // DEBUG
    }
    double get_width_length(void);
    void set_width_length(double len); 
};

class Height_c
{
    double height_length;
public:
    Height_c(double len = 0);       //给一个默认值
    double get_height_length(void);
    void set_height_length(double len);
};

class Rectengle_c : public Width_c,public Height_c
{
public:
    double area;
    Rectengle_c(double wid, double hei);
    double get_area(void);
};


void inherit_test(void);


int main()
{
    //inherit_test();

    std::cout << "\n测试完成\n";
    return 0;
}

//Width_c::Width_c(double len) : width_length(len)
//{
//#ifdef DEBUG
//    debug_str = "Width_c::Width_c";
//    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
//#endif // DEBUG
//}

void Width_c::set_width_length(double len)
{
#ifdef DEBUG
    debug_str = "Width_c::set_width_length";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG

    width_length = len;
}

double Width_c::get_width_length(void)
{
#ifdef DEBUG
    debug_str = "Width_c::get_width_length";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG

    return width_length;
}


Height_c::Height_c(double len) : height_length(len)
{
#ifdef DEBUG
    debug_str = "Height_c::Height_c";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG
}

void Height_c::set_height_length(double len)
{
#ifdef DEBUG
    debug_str = "Height_c::set_height_length";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG

    height_length = len;
}

double Height_c::get_height_length(void)
{
#ifdef DEBUG
    debug_str = "Height_c::get_height_length";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG

    return height_length;
}


double Rectengle_c::get_area(void)
{
#ifdef DEBUG
    debug_str = "Rectengle_c::get_area";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG

    return (get_height_length() * get_width_length());
}

//,Height_c(hei)注释掉也不会报错，说明缺省值起作用了!
Rectengle_c::Rectengle_c(double wid, double hei):Width_c(wid), Height_c(hei)
{
#ifdef DEBUG
    debug_str = "Rectengle_c::get_area";
    std::clog << "___LOG : running " + debug_str + "() " << std::endl;
#endif // DEBUG
    area = 0;
}


void inherit_test(void)
{
    std::cout << "尝试创建一个派生类的对象: " << std::endl;

    Rectengle_c shape_1(2,3);

    std::cout << "尝试访问继承来的方法和属性: " << std::endl;

    std::cout << "get_width() = " << shape_1.get_width_length()
//        << "shape.width = " << shape_1.width_length       //受保护的成员不可访问
        << std::endl;

    std::cout << "get_height() = " << shape_1.get_height_length()
 //       << "shape.height = " << shape_1.height_length     //私有的成员不可访问
        << std::endl;

    std::cout << "get_area() = " << shape_1.get_area()
        << std::endl;

}

