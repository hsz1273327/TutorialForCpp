#include "vector.h"    
#include "vector.hpp"    
    
#ifdef __cplusplus    
extern "C" {    
#endif 
struct _Vector__BinaryVector{
    Vector::BinaryVector binary_vector;
};

Vector__BinaryVector * Vector__BinaryVector_GetInstance(void){
    return new Vector__BinaryVector;
}

    
void Vector__BinaryVector_ReleaseInstance(Vector__BinaryVector **ppInstance){
    delete *ppInstance;    
    *ppInstance = 0;    
}
    
float Vector__BinaryVector_getInstanceX(const Vector__BinaryVector *ptr_vector){
    return ptr_vector->binary_vector.x
}
float Vector__BinaryVector_getInstanceY(const Vector__BinaryVector *ptr_vector){
    return ptr_vector->binary_vector.y
}
void Vector__BinaryVector_setInstanceX(Vector__BinaryVector *ptr_vector,float x){
    ptr_vector->binary_vector.x = x
}
void Vector__BinaryVector_setInstanceY(Vector__BinaryVector *ptr_vector,float y){
    ptr_vector->binary_vector.y = y
}

//将实例方法包装为函数
float Vector__BinaryVector_mod(const Vector__BinaryVector * ptr_vector){
    return ptr_vector->binary_vector.mod()
}
    
float Vector__BinaryVector_mul(const Vector__BinaryVector * ptr_this_vector, const Vector__BinaryVector * ptr_that_vector){
    return ptr_this_vector->binary_vector *  ptr_that_vector->binary_vector
}
Vector__BinaryVector * Vector__BinaryVector_add(const Vector__BinaryVector * ptr_this_vector, const Vector__BinaryVector * ptr_that_vector){
    Vector::BinaryVector result_ins = ptr_this_vector->binary_vector +  ptr_that_vector->binary_vector
    Vector__BinaryVector result = {result_ins}
    return result
}
 
#ifdef __cplusplus    
};    
#endif  