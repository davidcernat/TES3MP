//
// Created by koncord on 07.01.16.
//

#ifndef OPENMW_BASEPLAYER_HPP
#define OPENMW_BASEPLAYER_HPP

#include <components/esm/npcstats.hpp>
#include <components/esm/loadcell.hpp>
#include <components/esm/loadnpc.hpp>
#include <components/esm/creaturestats.hpp>
#include <RakNetTypes.h>

namespace mwmp
{
    class Attack
    {
    public:
        RakNet::RakNetGUID target;
        RakNet::RakNetGUID attacker;
        char type; // 0 - melee, 1 - magic, 2 - throwable
        std::string refid; // id of spell (e.g. "fireball")
        char success;
        char block;
        float damage;
        char pressed;
        char knockdown;
    };

    struct Item
    {
        std::string refid;
        int count;
    };

    class BasePlayer
    {
    public:

        struct CGStage
        {
            int current, end;
        };

        BasePlayer(RakNet::RakNetGUID guid) : guid(guid)
        {

        }

        BasePlayer()
        {

        }

        virtual ESM::Position *Position()
        {
            return &pos;
        }
        virtual ESM::NPC *Npc()
        {
            return &npc;
        }
        virtual ESM::NpcStats *NpcStats()
        {
            return &npcStats;
        }
        virtual ESM::CreatureStats *CreatureStats()
        {
            return &creatureStats;
        }

        virtual unsigned int *MovementFlags()
        {
            return &movementFlags;
        }
        virtual ESM::Cell *GetCell()
        {
            return &cell;
        }

        virtual Item *EquipedItem(int id)
        {
            if(id >= 18) return &equipedItems[18];
            return &equipedItems[id];
        }

        virtual char *MovementAnim()
        {
            return &movementAnim;
        }

        virtual char *DrawState()
        {
            return &drawState;
        }

        virtual ESM::Position *Dir()
        {
            return &dir;
        }

        virtual Attack *GetAttack()
        {
            return &attack;
        }

        virtual std::string *BirthSign()
        {
            return &birthSign;
        }

        virtual std::string *ChatMessage()
        {
            return &chatMessage;
        }

        virtual CGStage *CharGenStage()
        {
            return &stage;
        }

        virtual std::string *GetPassw()
        {
            return &passw;
        }
        RakNet::RakNetGUID guid;

    protected:
        ESM::Position pos;
        ESM::Position dir;
        ESM::Cell cell;
        ESM::NPC npc;
        ESM::NpcStats npcStats;
        ESM::CreatureStats creatureStats;
        Item equipedItems[19];
        unsigned int movementFlags;
        char movementAnim;
        char drawState;
        Attack attack;
        std::string birthSign;
        std::string chatMessage;
        CGStage stage;
        std::string passw;

    };
}

#endif //OPENMW_BASEPLAYER_HPP
