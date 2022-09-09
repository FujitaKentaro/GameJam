#pragma once
#include "Affin.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <cassert>
#include <list>
#include <memory>

#include "PlayerBullet.h"

/// <summary>
/// ���L����
/// </summary>
class Player {
  private:
	//	���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	Model* bulletModel_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	//���e�B�N���p�e�N�X�`���擾
	uint32_t textureReticle = TextureManager::Load("reticle2D.png");

	// input
	Input* input_ = nullptr;
	// debugText
	DebugText* debugText_ = nullptr;

	// �e
	std::list<std::unique_ptr<PlayerBullet>> bullets_;

	// �J�������W�p
	WorldTransform cameraWorldTransform_;

	// 3D���e�B�N���p���[���h�g�����X�t�H�[��
	WorldTransform worldTransform3DReticle_;
	// 2D���e�B�N���p�X�v���C�g
	std::unique_ptr<Sprite> sprite2DReticle_;

	int hp = 100;
	int point = 0;
	bool isDead = false;

  public:
	float r = 1;

  public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(Model* model, uint32_t textureHandle);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(ViewProjection viewprojection, Model* model);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(ViewProjection viewProjection);

	/// <summary>
	/// ���s�ړ�
	/// </summary>
	void Move();
	/// <summary>
	/// ��]�ړ�
	/// </summary>
	void Rotate();

	/// <summary>
	/// �s��̌v�Z
	/// </summary>
	void MatUpdate(WorldTransform& worldTransfom);

	/// <summary>
	/// ���[���h���W���擾
	/// </summary>
	Vector3 GetWorldPosition();

	/// <summary>
	/// �U��
	/// </summary>
	void Attack(Model* model);

	/// <summary>
	/// �Փ˂����m������Ăяo�����R�[���o�b�N�֐�
	/// </summary>
	void OnCollision();

	/// <summary>
	/// �e�̎擾
	/// </summary>
	const std::list<std::unique_ptr<PlayerBullet>>& GetBullets() { return bullets_; }

	/// <summary>
	/// ���[���h�s��̎擾
	/// </summary>
	WorldTransform GetWorldTransform() { return worldTransform_; }

	/// <summary>
	/// �e�I�u�W�F�N�g�̐ݒ�
	/// </summary>
	void SetParent(WorldTransform* worldTransform) { worldTransform_.parent_ = worldTransform; };

	/// <summary>
	/// UI�`��
	/// </summary>
	void DrawUI();

	/// <summary>
	/// ���@�̃��[���h���W����3D���e�B�N���̃��[���h���W���v�Z
	/// </summary>
	void WorldReticle();

	// 3D���e�B�N���̃��[���h���W����2D���e�B�N���̃X�N���[�����W���v�Z
	void Reticle(ViewProjection viewprojection);

	//  ���Z
	void AddPoint();

	/// <summary>
	/// point
	/// </summary>
	int GetPoint() { return point; }

	bool IsDead() const { return isDead; }
};
