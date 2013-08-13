#pragma once

#include "GameCoreEntry.h"

class GCORE_ENTRY GmEntity
{
	DECLARE_ALLOC();

public:
	GmEntity();
	virtual ~GmEntity();

	void SetPosition(float x, float y, float z);
	void SetPosition(const Vec3 & v);
	Vec3 GetPosition() const;

	void SetOrientation(float x, float y, float z, float w);
	void SetOrientation(const Quat & q);
	Quat GetOrientation() const;

	void SetScale(float x);
	float GetScale();

	void SetVisible(bool b);
	bool IsVisible();

	Node * GetNode() { return mNode; }

protected:
	Node * mNode;
};
