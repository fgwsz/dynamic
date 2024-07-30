#include<iostream>

#include"dynamic/box.hpp"
#include"dynamic/type_name.hpp"

struct Point{
    Point(int x,int y)
        :x_(x),y_(y)
    {}
    int x_,y_;
};

int main(int argc,char* argv[]){
    ::dynamic::Box<::std::string> val;
    val="hello world!";
    ::std::cout<<"val="<<val.get()<<'\n';
    ::dynamic::Box<Point> p({1,2});
    ::std::cout<<"sizeof(Box)="<<sizeof(::dynamic::Box<void*>)<<'\n';
    ::std::cout<<"sizeof(void*)="<<sizeof(void*)<<'\n';
    ::std::cout<<::dynamic::type_name<
        typename ::dynamic::Box<void*>::value_type
    >()<<'\n';
    return 0;
}
