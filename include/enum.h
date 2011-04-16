/* C++ utilities library
 *
 * Typesafe enum which isn't fraught with scoping problems like the C++ native enum.
 * Typical usage as below:
 *
 *	struct quality_def 
 *	{
 *		enum type { atrocious, bad, mediocre, average, great, awesome, mindblowing};
 *	};typedef ul_enum<quality_def> Quality;
 *
 *  Quality q = Quality::atrocious
 */


namespace util
{


template<typename enumDecl>
class ul_enum : public enumDecl
{
	typedef typename enumDecl::type underlyingType;
	underlyingType actualValue;
 
public:
	ul_enum(underlyingType value) 
		: actualValue(value) {}
 
	bool operator == (const ul_enum<enumDecl>& other) const { return actualValue == other.actualValue; }
	bool operator != (const ul_enum<enumDecl>& other) const { return actualValue != other.actualValue; }
	bool operator <  (const ul_enum<enumDecl>& other) const { return actualValue <  other.actualValue; }
	bool operator <= (const ul_enum<enumDecl>& other) const { return actualValue <= other.actualValue; }	
	bool operator >  (const ul_enum<enumDecl>& other) const { return actualValue >  other.actualValue; }
	bool operator >= (const ul_enum<enumDecl>& other) const { return actualValue >= other.actualValue; }
};
 





}
 


