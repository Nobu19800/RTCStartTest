// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RTCStartTestTest.cpp
 * @brief RTC startup time measurement Component (test code)
 *
 */
// </rtc-template>

#include "RTCStartTestTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const rtcstarttest_spec[] =
#else
static const char* rtcstarttest_spec[] =
#endif
  {
    "implementation_id", "RTCStartTestTest",
    "type_name",         "RTCStartTestTest",
    "description",       "RTC startup time measurement Component",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.filename", "output.txt",
    "conf.default.starttime_sec", "0",
    "conf.default.starttime_nsec", "0",

    // Widget
    "conf.__widget__.filename", "text",
    "conf.__widget__.starttime_sec", "text",
    "conf.__widget__.starttime_nsec", "text",
    // Constraints

    "conf.__type__.filename", "string",
    "conf.__type__.starttime_sec", "int",
    "conf.__type__.starttime_nsec", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RTCStartTestTest::RTCStartTestTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_testservicePort("testservice")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RTCStartTestTest::~RTCStartTestTest()
{
}



RTC::ReturnCode_t RTCStartTestTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_testservicePort.registerConsumer("testserviceif", "TestService::TimeMeasurement", m_testserviceif);
  
  // Set CORBA Service Ports
  addPort(m_testservicePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("filename", m_filename, "output.txt");
  bindParameter("starttime_sec", m_starttime_sec, "0");
  bindParameter("starttime_nsec", m_starttime_nsec, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RTCStartTestTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t RTCStartTestTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onExecute(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTestTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool RTCStartTestTest::runTest()
{
    return true;
}


extern "C"
{
 
  void RTCStartTestTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(rtcstarttest_spec);
    manager->registerFactory(profile,
                             RTC::Create<RTCStartTestTest>,
                             RTC::Delete<RTCStartTestTest>);
  }
  
}
