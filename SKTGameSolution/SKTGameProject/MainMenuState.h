#pragma once
#include <Common/FSM/State.h>
#include "Game.h"
#include "EntityStatic.h"
#include "../GraphicsEngine/InputManager.h"


class MainMenuState : public State<Game>
{
public:
	MainMenuState();
	~MainMenuState();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
	void Render(Game* game) override;
	void Init(const char* filePath);

	static MainMenuState* GetInstance();
	void Clear();
private:
	EntityStatic *m_Background;
	EntityStatic *m_Button_PlayGame;
	EntityStatic *m_Button_Option;
	EntityStatic *m_Button_Exit;
	InputManager *m_Mouse;
};