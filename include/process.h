/* C++ utilities library - Strings
 *
 */

#include <string>


namespace util
{


	// Class for spawning and talking to another process
	class FriendProcess
	{
	public:
		FriendProcess(std::string process);

		// TODO: Read

		void Write(std::string data);
	private:
	#ifdef _WIN32
		void* pipe; // windows HANDLE, declare as pointer to avoid including windows.h here
	#else //_WIN32
	// TODO: Unix pipe
	#endif //_WIN32


};




}
 


