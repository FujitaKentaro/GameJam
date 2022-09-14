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

#include "Food.h"

// ���@�N���X�̑O���錾
class Player;
class GameScene;

enum class Phase {
	None,     // ��~
	Approach, // �ڋ�
	Leave,    // ���E
};

enum enemyID {
	Monkey,
	Pig,
	Cow,
	Chicken,
	Lettuce,
	Tomato,
	Potato,
	Carrot,
	Onion,
	Rice,
	Fire,
	Leave,
};

class Enemy {
  private:
	//	���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;

	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;

	// input
	Input* input_ = nullptr;
	// debugText
	DebugText* debugText_ = nullptr;

	// ���L����
	Player* player_ = nullptr;

	Food* food_ = nullptr;

	GameScene* gameScene_ = nullptr;

	//�f�X�t���O
	bool isDead_ = false;

	int enemyHp = 5;

	//�e
	std::list<std::unique_ptr<EnemyBullet>> bullets_;

	Phase phase_ = Phase::None;

	enemyID enemyID_ = enemyID::Monkey;
	// ���˃^�C�}�[
	int32_t fireTimer_ = 0;

	int tribe = 0;

	int hp;

	int damage = 1;

	int damageUp = 5;

  public:
	// ���ˊԊu
	static const int kFireInterval = 120;
	// �e���X�g���擾
	//const std::list<std::unique_ptr<EnemyBullet>>& GetBullets() { return bullets_; }
	float r = 1;

  public:
	void Initialize(Vector3 trans);
	void Initialize(Model* model, Vector3 trans);
	void Update(Model* model);
	void Draw(ViewProjection viewProjection);
	void SetPlayer(Player* player);

	/// <summary>
	/// �s��̌v�Z
	/// </summary>
	void MatUpdate(WorldTransform& worldTransfom);

	/// <summary>
	/// �e����
	/// </summary>
	void Fire(Model* model);

	/// <summary>
	/// �ڋ߃t�F�[�Y������
	/// </summary>
	void ApproachInitialize();

	void Tackle(WorldTransform& worldTransform);

	/// <summary>
	/// ���[���h���W���擾
	/// </summary>
	Vector3 GetWorldPosition();

	/// <summary>
	/// �Փ˂����m������Ăяo�����R�[���o�b�N�֐�
	/// </summary>
	void OnCollision();

	void OnCollition2();

	void SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }
	void SetTribe(int W) { tribe = W; }

	// texture ��ݒ�
	void SetTexture();
	void SetModel();

	bool IsDead() const { return isDead_; }
	void IsDeath() { isDead_ = true; }
};
