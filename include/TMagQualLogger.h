#ifndef TMAGQUALLOGGER_HH
#define TMAGQUALLOGGER_HH

#include <string>

namespace MagQual
{
  class TMagQualLogger;
  class TMagQualLevel;
}


// class: TMagQualLevel
class MagQual::TMagQualLevel
{
  public:
    enum ErrorType {
      Status,
      Debug,
      Warn,
      Error
    };

    static std::string ToString( MagQual::TMagQualLevel::ErrorType level) {
      switch (level) {
        case MagQual::TMagQualLevel::Status:  return "STATUS";
        case MagQual::TMagQualLevel::Debug :  return "DEBUG";
        case MagQual::TMagQualLevel::Warn  :  return "WARN";
        case MagQual::TMagQualLevel::Error :  return "ERROR";
        default:                              return "UNKNOWN";
      }
    }

};


// class: TMagQualLogger
class MagQual::TMagQualLogger
{
  private:
    MagQual::TMagQualLevel::ErrorType fErrorLevel;
    std::string        fFilePath;


  public:
    static TMagQualLogger* GetInstance();
    void SetLogLevel(const MagQual::TMagQualLevel::ErrorType& level);

    // set the path to the log file
    void SetFilePath(const char* path);

    // write the message in log
    void Write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* format);

  protected:
    // construtor
    TMagQualLogger();

    // write the message
    void write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* message);

};


#endif
