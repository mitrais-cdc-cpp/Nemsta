#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "inc/util/NemstaUtil.hpp"
#include "env/SNMPLib/inc/PDU.hpp"
#include "env/SNMPLib/inc/ReturnStatus.hpp"

using namespace Mitrais::SNMP;
using namespace Mitrais::Nemsta;

int main(int argc, char* argv[])
{
	NemstaUtil nemsta;
	PDU pdu;
	ReturnStatus status = nemsta.capture(argc, argv, pdu);

	return 0;
}
