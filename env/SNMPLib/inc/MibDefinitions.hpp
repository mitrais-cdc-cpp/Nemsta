/*
 * MibDefinitions.hpp
 * This OID taken from Nemsta VM for Sanur B/Jogja [172.19.12.29]
 *
 *  Created on: Aug 23, 2016
 *      Author: Ari Suarkadipa
 */

#ifndef INC_MIBDEFINITIONS_HPP_
#define INC_MIBDEFINITIONS_HPP_

#include <string>

// system description
#define SYSTEM_DESCRIPTION "1.3.6.1.2.1.1.1.0"

// system uptime
#define SYSTEM_UP_TIME "1.3.6.1.2.1.1.3.0"

// system name
#define SYSTEM_NAME "1.3.6.1.2.1.1.5.0"

// System location
#define SYSTEM_LOCATION "1.3.6.1.2.1.1.6.0"

// The total number of Messages delivered to the SNMP entity from the transport
// service.
#define RFC1213_MIB_SNMP_IN_PKTS "1.3.6.1.2.1.11.1.0"

// The total number of SNMP Trap PDUs which have been accepted and processed by
// the SNMP protocol entity.
#define RFC1213_MIB_SNMP_IN_TRAPS "1.3.6.1.2.1.11.19.0"

//  The amount of physical main memory contained by the host.
#define HOST_RESOURCES_MIB_HR_MEMORY_SIZE "1.3.6.1.2.1.25.2.2.0"

// The product ID of the firmware associated with the processor.
#define HOST_RESOURCES_MIB_HR_PROCESSOR_FRW_ID "1.3.6.1.2.1.25.3.3.1.1.3"

// The average, over the last minute, of the percentage of time that this
// processor was not idle.
#define HOST_RESOURCES_MIB_HR_PROCESSOR_LOAD "1.3.6.1.2.1.25.3.3.1.2.3"

/*  The current status of this printer device.
 *	When in the idle(1), printing(2), or warmup(3) state,
 *	the corresponding hrDeviceStatus should be
 *	running(2) or warning(3).  When in the unknown
 *	state, the corresponding hrDeviceStatus should be
 *	unknown(1).
 */
#define HOST_RESOURCES_MIB_HR_PRINTER_STATUS "1.3.6.1.2.1.25.3.5.1.1.1"

// The type of storage represented by this entry.
#define HOST_RESOURCES_MIB_HR_STORAGE_TYPE "1.3.6.1.2.1.25.2.3.1.2.5"

//  A description of the type and instance of the storage described by this
//  entry.
#define HOST_RESOURCES_MIB_HR_STORAGE_DESCR "1.3.6.1.2.1.25.2.3.1.3.2"

//  The amount of the storage represented by this entry that is allocated, in
//  units of hrStorageAllocationUnits.
#define HOST_RESOURCES_MIB_HR_STORAGE_USED "1.3.6.1.2.1.25.2.3.1.6.2"

/*  The size, in bytes, of the data objects allocated
 * from this pool.  If this entry is monitoring
 * sectors, blocks, buffers, or packets, for example,
 * this number will commonly be greater than one.
 * Otherwise this number will typically be one.
 */
#define HOST_RESOURCES_MIB_HR_STORAGE_ALLOCATION_UNITS \
  "1.3.6.1.2.1.25.2.3.1.4.4"

/* The interface's address at the protocol layer
 * immediately `below' the network layer in the
 * protocol stack.  For interfaces which do not have
 * such an address (e.g., a serial line), this object
 * should contain an octet string of zero length.
 * To Get the MAC ADDRESS
 */
#define RFC1213_MIB_IF_PHYS_ADDRESS "1.3.6.1.2.1.2.2.1.6.11"

// The MAC Address OID definition for local workstation
#ifndef LOCAL_RFC1213_MIB_IF_PHYS_ADDRESS
#	ifdef _WIN32
#		define LOCAL_RFC1213_MIB_IF_PHYS_ADDRESS "1.3.6.1.2.1.2.2.1.6.11"
#	elif __linux
#		define LOCAL_RFC1213_MIB_IF_PHYS_ADDRESS "1.3.6.1.2.1.2.2.1.6.2"
#	endif
#endif

/**
 * Function to get SNMP Object name by given OID
 * @param OID
 * @return SNMP Object name
 */
std::string getSNMPNameByOID(const std::string &OID);

#endif /* INC_MIBDEFINITIONS_HPP_ */
