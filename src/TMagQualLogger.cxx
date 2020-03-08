#include <iostream>
#include <stdarg.h>
#include <sstream>
#include <fstream>
#include "TMagQualLogger.h"

using MagQual::TMagQualLogger;


TMagQualLogger::TMagQualLogger()
  : fErrorLevel( MagQual::TMagQualLevel::Status )
{
  this->fFilePath = "magqual_logger.log";
}

TMagQualLogger* TMagQualLogger::GetInstance()
{
  static TMagQualLogger instance;
  return &instance;
}

void TMagQualLogger::SetLogLevel(const MagQual::TMagQualLevel::ErrorType& level)
{
  this->fErrorLevel = level;
}

void TMagQualLogger::SetFilePath(const char* path)
{
  this->fFilePath = path;
}

void TMagQualLogger::Write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* format)
{
  char message[512] = {0};
  va_list args;

  vsprintf(message, format, args);

  this->write(level, filename, funcname, line, message );
  va_end(args);
}

void TMagQualLogger::write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int iline, const char* message)
{
  std::cout << "" << std::endl;
}
