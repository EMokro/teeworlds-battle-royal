/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_BATTLEROYAL_H
#define GAME_SERVER_GAMEMODES_BATTLEROYAL_H
#include <game/server/gamecontroller.h>
#include <game/server/entity.h>

class CGameControllerBattleroyal : public IGameController
{
  class CGameContext *m_pGameServer;
	EGameState m_GameState;
	int m_GameStateTimer;
  
	int m_aTeamSize[NUM_TEAMS];

  int m_LivingPlayer = 0;

protected:
	CGameContext *GameServer() const { return m_pGameServer; }

public:
	CGameControllerBattleroyal(class CGameContext *pGameServer);

  // events
	virtual void OnCharacterSpawn(class CCharacter *pChr);
  virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);

  void OnGameStart();

  // general
	virtual void Snap(int SnappingClient);
	virtual void Tick();
};

#endif
