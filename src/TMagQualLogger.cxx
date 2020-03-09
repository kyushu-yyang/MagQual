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


void TMagQualLogger::Status(const char* const filename, const char* const funcname, const int line, const char* message) const
{
  this->write( MagQual::TMagQualLevel::Status, filename, funcname, line, message );
}


void TMagQualLogger::Debug(const char* const filename, const char* const funcname, const int line, const char* message) const
{
  this->write( MagQual::TMagQualLevel::Debug, filename, funcname, line, message );
}

void TMagQualLogger::Warn(const char* const filename, const char* const funcname, const int line, const char* message) const 
{
  this->write( MagQual::TMagQualLevel::Warn, filename, funcname, line, message );
}

void TMagQualLogger::Error(const char* const filename, const char* const funcname, const int line, const char* message) const
{
  this->write( MagQual::TMagQualLevel::Error, filename, funcname, line, message );
}


void TMagQualLogger::Write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* format)
{
  char message[512] = {0};
  va_list args;

#ifdef _WIN32
  vsprintf_s(message, format, args);
#else
  vsprintf(message, format, args);
#endif

  this->write(level, filename, funcname, line, message );
  va_end(args);
}

void TMagQualLogger::write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int iline, const char* message) const
{
  if ( !this->isEnabled(level) )
    return;

  // logger output
  std::ofstream ofs;
  ofs.open( this->fFilePath, std::ios::app );

  ofs << this->getDateTime() << " "
      << "[" << MagQual::TMagQualLevel::ToString(level) << "]"
      << "[" << filename << "]"
      << "[" << funcname << "]"
      << message << std::endl;

  ofs.close();
}


bool TMagQualLogger::isEnabled(const MagQual::TMagQualLevel::ErrorType& level) const
{
  return this->fErrorLevel <= level;
}

std::string TMagQualLogger::getDateTime() const
{
  std::ostringstream oss;
  return oss.str();
}
