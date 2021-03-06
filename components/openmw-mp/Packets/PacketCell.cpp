//
// Created by koncord on 15.01.16.
//

#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketCell.hpp"


mwmp::PacketCell::PacketCell(RakNet::RakPeerInterface *peer) : BasePacket(peer)
{
    packetID = ID_GAME_CELL;
    priority = MEDIUM_PRIORITY;
    reliability = UNRELIABLE_SEQUENCED;
}

void mwmp::PacketCell::Packet(RakNet::BitStream *bs, mwmp::BasePlayer *player, bool send)
{
    BasePacket::Packet(bs, player, send);

    RW(player->GetCell()->mData.mFlags, send);

    if(player->GetCell()->isExterior())
    {
        RW(player->GetCell()->mCellId.mIndex.mX, send);
        RW(player->GetCell()->mCellId.mIndex.mY, send);
    }
    else
        RW(player->GetCell()->mName, send);
}
