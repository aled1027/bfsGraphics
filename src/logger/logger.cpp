#include "logger.h"

Logger::Logger() {
	file_path = "";
}

Logger::Logger(const std::string& path) {
	file_path = path;
	open();

}

Logger::~Logger() {
	os.close();
}

void Logger::open() {
	try {
		os.open(file_path.c_str(), std::ios_base::app | std::ios_base::out);
	} catch (std::exception& e) {
		std::cout << "Couldn't open logger for " << file_path << std::endl;
		std::cout << e.what() << std::endl;
	}
}

void Logger::log(const LogLevel& level, const std::string& message) {
	os  << getCurrentDateTime() << "\t " 
		<< levelToString(level) << "\t "
		<< message << std::endl;
}



std::string Logger::levelToString(const LogLevel& level) {
	switch(level) {
		case Logger::logError: return "ERROR";
		case Logger::logWarning: return "WARNING";
		case Logger::logInfo: return "INFO";
		case Logger::logDebug: return "DEBUG";
		case Logger::logDebug1: return "DEBUG1";
		case Logger::logDebug2: return "DEBUG2";
		case Logger::logDebug3: return "DEBUG3";
		case Logger::logDebug4: return "DEBUG4";
		case Logger::none: return " ";
		default: return "NoLevel";
	}
}

const std::string Logger::getCurrentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

void operator<<(Logger& logger, const std::string& message) {
	logger.log(Logger::none, message);
}
