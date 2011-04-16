
#include "../include/process.h"
#include <string>
#include <iostream>

#ifndef _WIN32
#error "Sorry, still working on other platform support"
#endif //_WIN32

// TODO: Move this platform specific stuff somewhere 
#include "windows.h"

#define BUFSIZE 512

namespace util
{

FriendProcess::FriendProcess(std::string process)
{
	// Create a named pipe for communication between the datasource and the display
	// TODO: No wait
	// TODO: How many instances
	pipe = CreateNamedPipeA("\\\\.\\pipe\\DisplayPipe",
		PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES,
		BUFSIZE, BUFSIZE, 0, NULL);

	if (pipe == INVALID_HANDLE_VALUE) 
		std::cout << "Create pipe failed: " << GetLastError() << std::endl;

	// Start the viewer process
	PROCESS_INFORMATION procInfo;
	STARTUPINFOA startupInfo = {0};
	startupInfo.cb = sizeof(STARTUPINFO);

	BOOL m_create = CreateProcessA(process.c_str(), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &procInfo);
	if (m_create == 0)
	{
		std::cout << "Create process failed: " << GetLastError() << std::endl;
	}

	bool connected = ConnectNamedPipe(pipe, NULL) ? true : (GetLastError() == ERROR_PIPE_CONNECTED);

	if (!connected)
		std::cout << "Connection failed!" << std::endl;
}

// TODO: Read

void FriendProcess::Write(std::string data)
{
	DWORD bytesWritten;
	BOOL success = WriteFile(pipe, &data[0], data.size(), &bytesWritten, NULL);
	if (!success)
		std::cout << "Failed to write to pipe " << GetLastError() << std::endl;
}

void PlatformSleep(float time)
{
	Sleep((int)(time * 1000));
}

}
