#pragma once
#include "../Utilities/utilities.h"
#include <vector>
#include "Texture.h"
#include "CubeTexture.h"
#include "Model.h"
#include "Shaders.h"

enum class TypeObject {OBJECT, SKYBOX, TERRAIN};

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Draw();
	void SetModel(Model *m) { m_pModel = m; };
	void SetShader(Shaders *s) { m_pShader = s; };
	void Add2dTexture(Texture *t) { m_vec2DTextures.push_back(t); }
	void AddCubeTexture(CubeTexture *c) { m_vecCubeTextures.push_back(c); }
	void SetWorldMatrix(Vector3 position, Vector3 rotation, Vector3 scale);
	void SetViewMatrix(Matrix matView);
	void SetProjectionMatrix(Matrix matProjection);
	void SetType(TypeObject type);
private:
	TypeObject m_typType;
	Model *m_pModel;
	std::vector<Texture*> m_vec2DTextures;
	std::vector<CubeTexture*> m_vecCubeTextures;
	Shaders *m_pShader;
	Matrix m_matWorld;
	Matrix m_matView;
	Matrix m_matProjection;
};
