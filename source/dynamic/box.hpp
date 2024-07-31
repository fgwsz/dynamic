#pragma once
#include<memory>//::std::addressof
#include<utility>//::std::move

#include"dynamic/type_traits.hpp"
#include"dynamic/macro.hpp"

namespace dynamic{

template<typename Type__>
class Box final{
    DYNAMIC_MACRO_STATIC_ASSERT(::dynamic::is_value_type_v<Type__>);
public:
    Box(Type__ const& value);
    Box(Box<Type__> const& rhs);
    Box(Type__&& value={});
    Box(Box<Type__>&& rhs);
    Box<Type__>& operator=(Type__ const& value);
    Box<Type__>& operator=(Box<Type__> const& rhs);
    Box<Type__>& operator=(Type__&& value);
    Box<Type__>& operator=(Box<Type__>&& rhs);
    ~Box();
    Type__& get_mut();
    Type__ const& get_const()const;
    Type__& get();
    Type__ const& get()const;
    using value_type=Type__;
private:
    Type__* data_;
};

template<typename Type__>
Box<Type__>::Box(Type__ const& value){
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
Box<Type__>::Box(Type__&& value/*={}*/){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        this->data_=new Type__{::std::move(value)};
    }else{
        new((Type__*)(&(this->data_)))Type__{::std::move(value)};
    }
}

template<typename Type__>
Box<Type__>::Box(Box<Type__>&& rhs){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        this->data_=rhs.data_;
        rhs.data_=nullptr;
    }else{
        new((Type__*)(&(this->data_)))Type__{
            ::std::move(*(Type__*)(&(rhs.data_)))
        };
    }
}

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
    return this->operator=(rhs.get());
}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Type__&& value){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        *(this->data_)=::std::move(value);
    }else{
        *(Type__*)(&(this->data_))=::std::move(value);
    }
    return *this;
}

template<typename Type__>
Box<Type__>& Box<Type__>::operator=(Box<Type__>&& rhs){
    if(rhs.data_==this->data_){
        return *this;
    }
    if constexpr(::dynamic::is_big_type_v<Type__>){
        delete this->data_;
        this->data_=rhs.data_;
        rhs.data_=nullptr;
    }else{
        *(Type__*)(&(this->data_))=::std::move(*(Type__*)(&(rhs.data_)));
    }
    return *this;
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
Type__& Box<Type__>::get_mut(){
    if constexpr(::dynamic::is_big_type_v<Type__>){
        return *(this->data_);
    }else{
        return *(Type__ *)(&(this->data_));
    }
}

template<typename Type__>
Type__ const& Box<Type__>::get_const()const{
    return const_cast<Box<Type__>*>(this)->get_mut();
}

template<typename Type__>
Type__& Box<Type__>::get(){
    return this->get_mut();
}

template<typename Type__>
Type__ const& Box<Type__>::get()const{
    return this->get_const();
}

}//namespace dynamic
