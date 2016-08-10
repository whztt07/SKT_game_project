#include "MinionOwnedStates.h"
#include "SingletonClasses.h"

/*Wandering state*/
void WanderingState::Enter(EntityMinion* minion)
{
}

void WanderingState::Execute(EntityMinion* minion)
{
}

void WanderingState::Exit(EntityMinion* minion)
{
}

void WanderingState::Render(EntityMinion* minion)
{
}

bool WanderingState::OnMessage(EntityMinion* minion, const Telegram& telegram)
{
	return false;
}

WanderingState::WanderingState()
{
}

WanderingState::~WanderingState()
{
}

/*Global state*/
MinionGlobalState::MinionGlobalState()
{
}

MinionGlobalState::~MinionGlobalState()
{
}

void MinionGlobalState::Enter(EntityMinion* minion)
{
}

void MinionGlobalState::Execute(EntityMinion* minion)
{
	if (minion->IsDead() || !minion->IsActive() || minion->IsOutOfWall())
	{
		Dispatcher->DispatchMessageA(minion, GameInstance, MSG_CLEAN_UP, minion);
	}
}

void MinionGlobalState::Exit(EntityMinion* minion)
{
}

void MinionGlobalState::Render(EntityMinion* minion)
{
}

bool MinionGlobalState::OnMessage(EntityMinion* minion, const Telegram& telegram)
{
	if (telegram.Message == MSG_MINION_TAKE_DAMAGE)
	{
		auto damage = DereferenceToType<float>(telegram.ExtraInfo);
		minion->TakeDamage(damage);
		return true;
	}
	if (telegram.Message == MSG_EXPLODE)
	{
		minion->Explode();
		return true;
	}
	return false;
}


/* Dead State */
MinionDeadState::MinionDeadState()
{
}

MinionDeadState::~MinionDeadState()
{
}

void MinionDeadState::Enter(EntityMinion* minion)
{
}

void MinionDeadState::Execute(EntityMinion* minion)
{
}

void MinionDeadState::Exit(EntityMinion* minion)
{
}

void MinionDeadState::Render(EntityMinion* minion)
{
}

bool MinionDeadState::OnMessage(EntityMinion*, const Telegram&)
{
	return false;
}
