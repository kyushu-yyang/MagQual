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
    static MagQual::TMagQualLogger* GetInstance();
    void SetLogLevel(const MagQual::TMagQualLevel::ErrorType& level);

    // set the path to the log file
    void SetFilePath(const char* path);

    // write the message in log
    void Write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* format);

    // stauts
    void Status(const char* const filename, const char* const funcname, const int line, const char* message) const;

    // debug
    void Debug(const char* const filename, const char* const funcname, const int line, const char* message) const;

    // warning
    void Warn(const char* const filename, const char* const funcname, const int line, const char* message) const;

    // error
    void Error(const char* const filename, const char* const funcname, const int line, const char* message) const;


  private:
    // construtor
    TMagQualLogger();

    // write the message
    void write(const MagQual::TMagQualLevel::ErrorType& level, const char* filename, const char* funcname, const int line, const char* message) const;

    // check the input level is enabled or not
    bool isEnabled(const MagQual::TMagQualLevel::ErrorType& level) const;

    // return the date time
    std::string getDateTime() const;

};

// defined the gloabl function
#define LOG_LEVEL_SET(x)        MagQual::TMagQualLogger::GetInstance()->SetLogLevel(x);
#define LOG_FILE_PATH_SET(x)    MagQual::TMagQualLogger::GetInstance()->SetFilePath(x);

#ifdef _WIN32
#define LOG_STATUS(format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Status, __FILE__, __FUNCTION__, __LINE__, format);
#define LOG_DEBUG (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Debug , __FILE__, __FUNCTION__, __LINE__, format);
#define LOG_WARN  (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Warn  , __FILE__, __FUNCTION__, __LINE__, format);
#define LOG_ERROR (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Error , __FILE__, __FUNCTION__, __LINE__, format);
#else
#define LOG_STATUS(format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Status, __FILE__, __func__, __LINE__, format);
#define LOG_DEBUG (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Debug , __FILE__, __func__, __LINE__, format);
#define LOG_WARN  (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Warn  , __FILE__, __func__, __LINE__, format);
#define LOG_ERROR (format) MagQual::TMagQualLogger::GetInstance()->Write(MagQual::TMagQualLevel::Error , __FILE__, __func__, __LINE__, format);
#endif


#endif
