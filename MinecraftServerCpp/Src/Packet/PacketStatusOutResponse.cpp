#include "Packet/PacketStatusOutResponse.h"
#include "Packet/PacketEncoder.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace Minecraft;

PacketStatusOutResponse::PacketStatusOutResponse(std::string version, int protocol, int maxPlayers, int onlinePlayers, std::string description, std::string favicon) {

	Version = version;
	Protocol = protocol;
	MaxPlayers = maxPlayers;
	OnlinePlayers = onlinePlayers;
	Description = description;
	Favicon = favicon;
}

struct Packet PacketStatusOutResponse::BuildPacket() const {

	uint8_t packetId = 0x00;

	json j;
	j["version"]["name"] = Version;
	j["version"]["protocol"] = Protocol;
	j["players"]["max"] = MaxPlayers;
	j["players"]["online"] = OnlinePlayers;
	//j["players"]["sample"] = {};
	j["description"]["text"] = Description;
	//j["favicon"] = Favicon;

	std::string jsonDump = j.dump();
	size_t jsonLength = jsonDump.length();
	
	struct Packet packet(PacketEncoder::GetVarIntNumBytes(packetId) + PacketEncoder::GetVarIntNumBytes(jsonLength) + jsonLength);
	packet.AllocateData();

	PacketEncoder::WriteVarInt(packetId, packet);
	PacketEncoder::WriteString(jsonDump, packet);
	
	return packet;
}
