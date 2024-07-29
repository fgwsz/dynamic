#pragma once
#include<memory>//::std::addressof

#include"dynamic/type_traits.hpp"
#include"dynamic/macro.hpp"

namespace dynamic{

template<typename Type__>
class Box{
    DYNAMIC_MACRO_STATIC_ASSERT(::dynamic::is_value_type_v<Type__>);
public:
    Box();
    Box(Type__ const& value);
    Box(Box<Type__> const& rhs);
    Box<Type__>& operator=(Type__ const& value);
    Box<Type__>& operator=(Box<Type__> const& rhs);
    virtual ~Box();
    Type__ const& get()const;
    bool empty()const;
    explicit operator bool()const;
private:
    Type__* data_;
};

template<typename Type__>
Box<Type__>::Box(){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        this->data_=nullptr;
    }else{
        new((Type__*)(&(this->data_)))Type__{};
    }
}

template<typename Type__>
Box<Type__>::Box(Type__ const& value)
    :Box(){
    this->operator=(value);
}

template<typename Type__>
Box<Type__>::Box(Box<Type__> const& rhs)
    :Box(){
    this->operator=(rhs);
}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Type__ const& value){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        if(::std::addressof(value)==this->data_){
            return *this;
        }
        if(!this->data_){
            this->data_=new Type__{value};
        }else{
            *(this->data_)=value;
        }
    }else{
        if(::std::addressof(value)==(Type__*)(&(this->data_))){
            return *this;
        }
        *(Type__*)(&(this->data_))=value;
    }
    return *this;
}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Box<Type__> const& rhs){
    if(::std::addressof(rhs)==this){
        return *this;
    }
    if constexpr(::dynamic::is_big_type_v<Type__>){
        if(!rhs.data_){
            if(this->data_){
                delete this->data_;
                this->data_=nullptr;
            }
            return *this;
        }else{
            return this->operator=(rhs);
        }
    }else{
        return this->operator=(rhs);
    }
}

template<typename Type__>
Box<Type__>::~Box(){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        if(this->data_){
            delete this->data_;
            this->data_=nullptr;
        }
    }else{
        ((Type__*)(&(this->data_)))->~Type__();
    }
}

template<typename Type__>
Type__ const& Box<Type__>::get()const{
    if constexpr(::dynamic::is_big_type_v<Type__>){
        if(this->data_){
            return *(this->data_);
        }else{
            DYNAMIC_MACRO_RUNTIME_ERROR("Box is empty!");
        }
    }else{
        return *(Type__ *)(&(this->data_));
    }
}

template<typename Type__>
bool Box<Type__>::empty()const{
    if constexpr(::dynamic::is_big_type_v<Type__>){
        return !this->data_;
    }else{
        return false;
    }
}

template<typename Type__>
Box<Type__>::operator bool()const{
    return this->empty();
}

}//namespace dynamic
