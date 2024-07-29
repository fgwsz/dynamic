#include<iostream>

#include"dynamic/box.hpp"

int main(int argc,char* argv[]){
    ::dynamic::Box<::std::string> val;
    val="hello world!";
    ::std::cout<<"val="<<val.get()<<'\n';
    return 0;
}
