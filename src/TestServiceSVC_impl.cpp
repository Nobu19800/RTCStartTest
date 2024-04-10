// -*-C++-*-
/*!
 * @file  TestServiceSVC_impl.cpp
 * @brief Service implementation code of TestService.idl
 *
 */

#include <chrono>
#include <iostream>
#include "TestServiceSVC_impl.h"

/*
 * Example implementational code for IDL interface TestService::TimeMeasurement
 */
TestService_TimeMeasurementSVC_impl::TestService_TimeMeasurementSVC_impl()
{
  // Please add extra constructor code here.
}


TestService_TimeMeasurementSVC_impl::~TestService_TimeMeasurementSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
RTC::Time TestService_TimeMeasurementSVC_impl::getTime()
{
  return m_startTime;
}

void TestService_TimeMeasurementSVC_impl::setTime(uint64_t sec, uint64_t nsec)
{
	//std::cout << __FILE__ << "\t" << __LINE__ << "\t" << sec << "\t" << nsec << std::endl;
	auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
	auto now_count = std::chrono::duration_cast<std::chrono::nanoseconds>(now);
	uint64_t start_count = sec * (uint64_t)1.0e+9 + nsec;
	//std::cout << __FILE__ << "\t" << __LINE__ << "\t" << start_count << "\t" << now_count.count() << std::endl;
	uint64_t diff = now_count.count() - start_count;
	m_startTime.sec = (CORBA::ULong)(diff / (uint64_t)1.0e+9);
	m_startTime.nsec = (CORBA::ULong)diff - m_startTime.sec*(CORBA::ULong)1.0e+9;
}



// End of example implementational code



