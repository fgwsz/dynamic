#pragma once
#include<type_traits>//::std::is_class_v
#include<typeindex>//::std::type_index

#include"dynamic/macro.hpp"
#include"dynamic/type_traits.hpp"

namespace dynamic{

template<typename Class__>
class Object final{
    DYNAMIC_MACRO_STATIC_ASSERT(
        ::dynamic::is_value_type_v<Class__>
        &&::std::is_class_v<Class__>
    );
    void* data_;
    unsigned long long offset_;
    ::std::type_index type_;
public:
    Object(Class__ const&);
    Object(Class__&&);
    Object(Object<Class__> const&);
    Object(Object<Class__> &&);
    template<typename DerivedClass__>
    Object(Object<DerivedClass__> const&);
    template<typename DerivedClass__>
    Object(Object<DerivedClass__> &&);
    Object<Class__>& operator=(Class__ const&);
    Object<Class__>& operator=(Class__&&);
    Object<Class__>& operator=(Object<Class__> const&);
    Object<Class__>& operator=(Object<Class__> &&);
    template<typename DerivedClass__>
    Object<Class__>& operator=(DerivedClass__ const&);
    template<typename DerivedClass__>
    Object<Class__>& operator=(DerivedClass__ &&);
    template<typename DerivedClass__>
    Object<Class__>& operator=(Object<DerivedClass__> const&);
    template<typename DerivedClass__>
    Object<Class__>& operator=(Object<DerivedClass__> &&);
    ~Object();
    Class__& get_mut();
    Class__ const& get_const()const;
    Class__& get();
    Class__ const& get()const;
    template<typename Type__>
    Type__& cast_mut();
    template<typename Type__>
    Type__ const& cast_const()const;
    template<typename Type__>
    Type__& cast();
    template<typename Type__>
    Type__ const& cast()const;
    template<typename Type__>
    Object<Type__> copy_to_object();
    template<typename Type__>
    Object<Type__> move_to_object();
};

}//namespace dynamic
