todo
- note down any questions and assumptions
- work with asynchronous code in multiple codebases

brief
- create c++ library
	- presents asynchronous public function with the signature indicated in the requirements section
- create build script
	- builds code as a library suitable for integration into an application
- create minimal console application
	- integrates the library
	- invokes the library's async function
- 2 hours, no longer than 4

requirements
- library providing a single public function
	- function params: arbitrary callable 'callback', int x
		- lambda for the callback i guess?
	- callable takes single int as param
	- func will invoke 'callback' after 10 seconds in an async fashion
		- passes back the value of 'x' provided in the callable param
	- func should not block the calling thread
- appropriate documentation comments within the code files
- provide a build script such that the library is built in a format that your minimal application can use
	- cmake preferred
- console app that integrates your library
	- should be written in c++
	- should provide source code and proj files so that this app can be built
	- app should link or otherwise integrate the library you've written
		- invoke the public function it provides

clarifications
- C or C++ interface to the library is acceptable
	- no need to worry about ABI issues (whatever those are)
- may choose how the 10-second delay and subsequent callback invocation is implemented

submission
- zip file
	- contain code for the task
	- build scripts
	- project files
	- notes
		- included in root as a 'README.md' or 'README.txt'

email to
- hr@mod.io
	- can be the zip or a link to github/equivalent repo
	- make sure file is accessible and viewed and run by anyone

assumption
- lambda for the arbitrary callable 'callback'
- wait before you call std::future
- then do some non-blocking work
- "func will invoke 'callback' after 10 seconds in an async fashion"
	- it will invoke the function asynchronously? or is the func also in a thread?
- std::async is invoked on the line where you call std::future<T> foo

future improvements:
- rename and reorganise project and solution files (done in v0.1.1)
- get CMake working
- add more test cases (positive, negative, 0, INT_MAX, INT_MIN)
- have main.cpp report the result of the async function, not have it reported inside the function
- add some feedback while we wait the 10 seconds