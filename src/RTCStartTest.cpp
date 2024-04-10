// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RTCStartTest.cpp
 * @brief RTC startup time measurement Component
 *
 */
// </rtc-template>

#include "RTCStartTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const rtcstarttest_spec[] =
#else
static const char* rtcstarttest_spec[] =
#endif
  {
    "implementation_id", "RTCStartTest",
    "type_name",         "RTCStartTest",
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
RTCStartTest::RTCStartTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_testservicePort("testservice")
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RTCStartTest::~RTCStartTest()
{
}



RTC::ReturnCode_t RTCStartTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer

  
  // Set service provider to Ports
  m_testservicePort.registerProvider("testserviceif", "TestService::TimeMeasurement", m_testserviceif);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_testservicePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("filename", m_filename, "output.txt");
  bindParameter("starttime_sec", m_starttime_sec, "0");
  bindParameter("starttime_nsec", m_starttime_nsec, "0");
  // </rtc-template>

	//m_testserviceif.setTime((uint64_t)m_starttime_sec, (uint64_t)m_starttime_nsec);
	m_testserviceif.setTime();
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RTCStartTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t RTCStartTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onExecute(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RTCStartTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void RTCStartTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(rtcstarttest_spec);
    manager->registerFactory(profile,
                             RTC::Create<RTCStartTest>,
                             RTC::Delete<RTCStartTest>);
  }
  
}
