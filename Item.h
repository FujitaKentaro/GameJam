#pragma once
#include "Affin.h"
#include "DebugText.h"
#include "EnemyBullet.h"
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <cassert>
#include <list>
#include <memory>

class Player;
class GameScene;


class Item
{
private:
	//	���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;

	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;

	std::unique_ptr<Sprite> sprite2DItem;

	// input
	Input* input_ = nullptr;
	// debugText
	DebugText* debugText_ = nullptr;

	// �O��
	Player* player_ = nullptr;
	GameScene* gameScene_ = nullptr;

	

public:
	void Initialize();
	void Update();
	void Draw();
};

