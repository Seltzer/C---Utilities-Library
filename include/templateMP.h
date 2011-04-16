/* C++ utilities library - Template Meta-Programming
 *
 */




namespace util
{


// An IF predicate which evaluates to one of two types at compile-time
template <bool, class Type1, class Type2>
struct IF  
{
	typedef Type2 type; 
};

template <class Type1, class Type2>
struct IF<true, Type1, Type2> 
{
	typedef Type1 type; 
};




}
 


