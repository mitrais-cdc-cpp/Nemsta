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

	// construct OID
	OID oid1;
	oid1.oid = SYSTEM_DESCRIPTION;

	// insert OID into variable binding
	VariableBinding vb1;
	vb1.setOID(oid1);

	// store into vector
	vbs.push_back(vb1);

	// construct OID
	OID oid2;
	oid2.oid = SYSTEM_UP_TIME;

	// insert OID into variable binding
	VariableBinding vb2;
	vb2.setOID(oid2);

	// store into vector
	vbs.push_back(vb2);

	// construct OID
	OID oid3;
	oid3.oid = SYSTEM_NAME;

	// insert OID into variable binding
	VariableBinding vb3;
	vb3.setOID(oid3);

	// store into vector
	vbs.push_back(vb3);

	// construct the target
	Target target;
	target.Ip.IpAddress = ipAddress;

	pdu.setBindingList(vbs);

	SNMP::SNMP snmp;
	ReturnStatus status = snmp.set(pdu, target, mode);

	return status;
}


