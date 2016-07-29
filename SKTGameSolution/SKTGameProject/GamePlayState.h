#pragma once
#include <Common/FSM/State.h>
#include "EntityPlayer.h"
#include "Game.h"
#include "EntityMinion.h"

class GamePlayState : public State<Game>
{
public:
	~GamePlayState();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
	void Render(Game* game) override;
	void Init(const char* filePath);

	static GamePlayState* GetInstance();
	void Clear();
private:
	GamePlayState();
	EntityPlayer* m_Goku;
	EntityPlayer* m_Background;
	EntityPlayer* m_pButton;
	EntityMinion* m_pTestMinion;
};