/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "battleroyal.h"

#include <game/server/entities/character.h>
#include <game/server/player.h>
#include <game/server/gamecontext.h>
#include <engine/shared/config.h>

CGameControllerBattleroyal::CGameControllerBattleroyal(CGameContext *pGameServer)
: IGameController(pGameServer)
{
  m_pGameServer = pGameServer;
  m_pGameType = "BR";
}

void CGameControllerBattleroyal::OnCharacterSpawn(CCharacter *pChar) {
  m_LivingPlayer++;
}

int CGameControllerBattleroyal::OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon)
{
  // CPlayer *pVictimPlayer = pVictim->GetPlayer();

  m_LivingPlayer -= 1;

  char aBuf[256];
  str_format(aBuf, sizeof(aBuf), "players alive %d", m_LivingPlayer);
  GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "DEBUG", aBuf);

  return IGameController::OnCharacterDeath(pVictim, pKiller, Weapon);
}

void CGameControllerBattleroyal::OnGameStart() {
  m_LivingPlayer = 	m_aTeamSize[TEAM_BLUE];
}

void CGameControllerBattleroyal::Tick() {
  IGameController::Tick();
}

void CGameControllerBattleroyal::Snap(int SnappingClient) {
  IGameController::Snap(SnappingClient);
}