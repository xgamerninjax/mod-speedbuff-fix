/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */
 
#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "Chat.h"

// Add player scripts
class FixSpeedBuff : public PlayerScript
{
	
public:

    FixSpeedBuff() : PlayerScript("FixSpeedBuff") { }

	void OnLogin(Player* player) override {
		if (sConfigMgr->GetOption<bool>("SpeedBuff.AnnounceOnLogin", true))
            ChatHandler(player->GetSession()).SendSysMessage(sConfigMgr->GetOption<std::string>("SpeedBuff.OnLoginMessage", "This server is running a SpeedBuff Module.").c_str());
    }


private:
    


};

// Add all scripts in one
void AddSC_mod_speedbuff_fix()
{
    new FixSpeedBuff();
}
