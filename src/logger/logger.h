/*
 *
 USE:
 * Logger logger;
 * logger(std::string("logs.txt"));
 *
 * logger.log("logError", "The error was this");
 * or
 * logger << "The error was this" // this sets the logLevel to none (ie " ")
 *
 *
 TO DO:
 * add consts and fix up
 *
 */


#ifndef _logger_h_
#define _logger_h_

#include <iostream>
#include <fstream>

#include <string.h>
#include <stdio.h>
#include <time.h>

class Logger {
public:
	enum LogLevel {logError, logWarning, logInfo, logDebug, logDebug1, logDebug2, logDebug3, logDebug4, none };
	// referenced with Logger::logError (for example)

	Logger(); 
	Logger(const std::string&); 
	~Logger();
	void log(const LogLevel&, const std::string&);

	friend void operator<<(Logger&, const std::string&);

private:
	// functions
	void open(); // opens ofstream os
	std::string levelToString(const LogLevel&); // converts enum LogLevel value to string 
	std::string getTime();
	const std::string getCurrentDateTime();

	// data
	std::ofstream os;
	std::string file_path;
};

#endif
