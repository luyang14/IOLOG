#ifndef IOLOG_H
#define IOLOG_H

//#include <Arduino.h>
#include <stdio.h>
#include <string.h>

#define __DEBUG

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_4G
#endif

#define DEBUG_NONA     0
#define DEBUG_ERROR    1
#define DEBUG_WARN     2
#define DEBUG_DEBUG    3
#define DEBUG_INFO     4
#define DEBUG_4G       5
#define DEBUG_SCREEN   6

#ifndef DEBUG_INFO_SECTION
#define DEBUG_INFO_SECTION  "INFO"
#endif
#ifndef DEBUG_WARN_SECTION
#define DEBUG_WARN_SECTION  "WARN"
#endif
#ifndef DEBUG_ERROR_SECTION
#define DEBUG_ERROR_SECTION "ERROR"
#endif
#ifndef DEBUG_DEBUG_SECTION
#define DEBUG_DEBUG_SECTION "DEBUG"
#endif
#ifndef DEBUG_4G_SECTION
#define DEBUG_4G_SECTION    "4G"
#endif

int io_printf(const char *format,...);

#if defined(ESP8266) || defined(ESP32)
#define DEBUG_PRINT  log_printf  
#else 
#define DEBUG_PRINT printf
#endif
#define filename(x) strrchr(x,'\\')?strrchr(x,'\\')+1:x

#ifdef __DEBUG
/* Define Log print macro */
//#define log(fmt,args...)   printf("%s:%s:line-%d:",__FILE__,__func__,__LINE__);\
//                                   printf(fmt"\r\n" ,##args);printf("\n"); 
#if(DEBUG_LEVEL >= DEBUG_ERROR)
#define loge(fmt,args...) \
do{ \
    DEBUG_PRINT("[%-5s][%-13s][%04d]",DEBUG_ERROR_SECTION,filename( __FILE__ ),__LINE__);DEBUG_PRINT(fmt"\r\n" ,##args); \
}while(0)
#else
#define loge(fmt,args...)
#endif

#if(DEBUG_LEVEL >= DEBUG_WARN)
#define logw(fmt,args...) \
do{ \
    DEBUG_PRINT("[%-5s][%-13s][%04d]",DEBUG_WARN_SECTION,filename( __FILE__ ),__LINE__);DEBUG_PRINT(fmt"\r\n" ,##args); \
}while(0)
#else
#define logw(fmt,args...)
#endif

#if(DEBUG_LEVEL >= DEBUG_INFO)
#define logi(fmt,args...) \
    do{ \
        DEBUG_PRINT("[%-5s][%-13s][%04d]",DEBUG_INFO_SECTION,filename( __FILE__ ),__LINE__);DEBUG_PRINT(fmt"\r\n" ,##args); \
    }while(0)
#else
#define log(fmt,args...)
#endif

#if(DEBUG_LEVEL >= DEBUG_DEBUG)
#define logd(fmt,args...) \
    do{ \
        DEBUG_PRINT("[%-5s][%-13s][%04d]",DEBUG_DEBUG_SECTION,filename( __FILE__ ),__LINE__);DEBUG_PRINT(fmt"\r\n" ,##args); \
    }while(0)
#else
#define log(fmt,args...)
#endif
    
#if(DEBUG_LEVEL >= DEBUG_4G)
#define log4g(fmt,args...) \
do{ \
   DEBUG_PRINT("[%-5s][%-13s][%04d]",DEBUG_4G_SECTION,filename( __FILE__ ),__LINE__);DEBUG_PRINT(fmt"\r\n" ,##args); \
}while(0)
#else
#define log4g(fmt,args...)
#endif

#endif
#endif

