#pragma once
#include<memory>//::std::addressof

#include"dynamic/type_traits.hpp"
#include"dynamic/macro.hpp"

namespace dynamic{

template<typename Type__>
class Box{
    DYNAMIC_MACRO_STATIC_ASSERT(::dynamic::is_value_type_v<Type__>);
public:
    Box(Type__ const& value={});
    Box(Box<Type__> const& rhs);
    Box<Type__>& operator=(Type__ const& value);
    Box<Type__>& operator=(Box<Type__> const& rhs);
    virtual ~Box();
    Type__ const& get()const;
private:
    Type__* data_;
};

template<typename Type__>
Box<Type__>::Box(Type__ const& value/*={}*/){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        this->data_=new Type__{value};
    }else{
        new((Type__*)(&(this->data_)))Type__{value};
    }
}

template<typename Type__>
Box<Type__>::Box(Box<Type__> const& rhs)
    :Box(rhs.get())
{}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Type__ const& value){
    Type__* data=nullptr;
    if constexpr(::dynamic::is_big_type_v<Type__>){
        data=this->data_;
    }else{
        data=(Type__*)(&(this->data_));
    }
    if(::std::addressof(value)!=data){
        *data=value;
    }
    return *this;
}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Box<Type__> const& rhs){
    if(::std::addressof(rhs)==this){
        return *this;
    }
    return this->operator=(rhs);
}

template<typename Type__>
Box<Type__>::~Box(){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        delete this->data_;
        this->data_=nullptr;
    }else{
        ((Type__*)(&(this->data_)))->~Type__();
    }
}

template<typename Type__>
Type__ const& Box<Type__>::get()const{
    if constexpr(::dynamic::is_big_type_v<Type__>){
        return *(this->data_);
    }else{
        return *(Type__ *)(&(this->data_));
    }
}

}//namespace dynamic
