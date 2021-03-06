#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include "EntityKiBlast.h"
#include "EntityMinion.h"
#include "EntityPlayer.h"

class ContactListener : public b2ContactListener
{
public:
	ContactListener();
	~ContactListener();

	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;

private:
	static void KiBlastHitsMinion(EntityKiBlast* kiBlast, EntityMinion* minion);
	static void MinionHitsPlayer(EntityMinion* minion, EntityPlayer* player);
	static void KiBlastHitsPlayer(EntityKiBlast* kiBlast, EntityPlayer* player);
	static void KiBlastHitsKiBlast(EntityKiBlast* kiBlast1, EntityKiBlast* kiBlast2);
	static void HitsBarrier(Entity* entity);
};

