
 /*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* nm) : value(v), name(nm)//1
    {}   
    int value;//2
    std::string name;//3
};

struct X                               //4
{/*
seems inputs should be able to be (const) & because we are not modifying the values. you said not to convert the function if a pointer is being returned. but how would I return something compatible with T* if the inputs are const T&?
*/
    T* compare( T* a, T* b) const//5
    {        
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
                    
        return nullptr;
    }
};

struct U
{
    float uVal1 { 0 }, uVal2 { 0 };
    float membFunc(const float& updVal)      //12
    {        
        std::cout << "U's uVal1 value: " << this->uVal1 << std::endl;
        this->uVal1 = updVal;
        std::cout << "U's uVal1 updated value: " << this->uVal1 << std::endl;
        while( std::abs(this->uVal2 - this->uVal1) > 0.001f )
        {
            this->uVal2 += 1;        
        }
        std::cout << "U's uVal2 updated value: " << this->uVal2 << std::endl;
        return this->uVal2 * this->uVal1;        
    }
};

struct W
{
    static float statFunc(U* that, const float& updtdVal )        //10
    {
        if( (that != nullptr) )
        {
            std::cout << "U's uVal1 value: " << that->uVal1 << std::endl;
            that->uVal1 = updtdVal;
            std::cout << "U's uVal1 updated value: " << that->uVal1 << std::endl;
            while( std::abs(that->uVal2 - that->uVal1) > 0.001f )
            {
                /* write something that makes the distance between that->uVal2 and that->uVal1 get smaller */
                that->uVal2 += 1;
            }
            std::cout << "U's uVal2 updated value: " << that->uVal2 << std::endl;
            return that->uVal2 * that->uVal1;
        }
        
        return 0;        
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 13, "hello" );                                             //6
    T t2( 4, "jello" );                                             //6
    
    X f;                                            //7
    auto* smaller = f.compare( &t1, &t2 );                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9    
    }
    else
    {
        std::cout << "nullptr was returned because the values are equal" << std::endl;
    }
    
    U u3;
    float updatedValue = 5.f;
    std::cout << "statFun u3's multiplied values: " << W::statFunc( &u3, updatedValue ) << std::endl;                  //11
    
    U u4;
    std::cout << "membFunc u4's multiplied values: " << u4.membFunc( updatedValue ) << std::endl;
}
