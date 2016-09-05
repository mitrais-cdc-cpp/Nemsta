#include "../../inc/util/SnmpUtil.hpp"

using namespace Mitrais::Nemsta;
using namespace Mitrais::SNMP;

/*
 * Constructor of Snmp Util class
 */
SnmpUtil::SnmpUtil()
{

}

/*
 * Destructor of Snmp Util class
 */
SnmpUtil::~SnmpUtil()
{

}

/*
 * Set the SNMP
 *
 * @param PUD
 * @param IpAddress
 * @param mode
 *
 * @return Return status
 */
ReturnStatus SnmpUtil::set(PDU& pdu, std::string ipAddress, SnmpMode mode)
{
	// construct vector of variable binding
	std::vector<VariableBinding> vbs;

	// store into vector
	vbs.push_back(setVariableBinding(SYSTEM_DESCRIPTION));
	
	vbs.push_back(setVariableBinding(SYSTEM_UP_TIME));
	
	vbs.push_back(setVariableBinding(SYSTEM_NAME));

	vbs.push_back(setVariableBinding(RFC1213_MIB_SNMP_IN_PKTS));
	
	vbs.push_back(setVariableBinding(RFC1213_MIB_SNMP_IN_TRAPS));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_MEMORY_SIZE));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_PROCESSOR_FRW_ID));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_PROCESSOR_LOAD));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_PRINTER_STATUS));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_STORAGE_TYPE));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_STORAGE_DESCR));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_STORAGE_USED));
	
	vbs.push_back(setVariableBinding(HOST_RESOURCES_MIB_HR_STORAGE_ALLOCATION_UNITS));
	
	vbs.push_back(setVariableBinding(RFC1213_MIB_IF_PHYS_ADDRESS));

	// construct the target
	Target target;
	target.Ip.IpAddress = ipAddress;

	pdu.setBindingList(vbs);

	SNMP::SNMP snmp;
	ReturnStatus status = snmp.set(pdu, target, mode);

	return status;
}

/*
 * Set Variable Binding
 *
 * @param OID
 * @return Variable Binding
 */
VariableBinding SnmpUtil::setVariableBinding(std::string oid)
{
	// construct OID
	OID oidSnmp;
	oidSnmp.oid = oid;
	
	// construct Variable Binding
	VariableBinding vb;
	vb.setOID(oidSnmp);
	
	return vb;
}

