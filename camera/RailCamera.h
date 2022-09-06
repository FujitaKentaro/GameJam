#pragma once
#include "Affin.h"
#include "DebugText.h"
#include "Input.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Player;

/// <summary>
/// ���[���J����
/// </summary>
class RailCamera {
  private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	// �r���[�v���W�F�N�V����
	ViewProjection viewProjection_;

	DebugText* debugText_ = nullptr;
	Input* input_ = nullptr;

	float focalLengs = 60;

  public:
	// fov(��p�ύX)�֐�
	float FieldOfViewY(float focalLengs, float sensor);

	/// <summary>
	/// �`��
	/// </summary>
	void Initialize(Vector3 wTrans, Vector3 rad);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(Player* player);

	/// <summary>
	/// �ړ�
	/// </summary>
	void Move();

	/// <summary>
	/// ��]
	/// </summary>
	void Rotate();

	/// <summary>
	/// ���[���h���W���擾
	/// </summary>
	Vector3 GetWorldPosition();

	/// <summary>
	/// ���[���h���W���擾
	/// </summary>
	WorldTransform* GetWorldTransform() { return &worldTransform_; }

	/// <returns>�r���[�v���W�F�N�V����</returns>
	const ViewProjection& GetViewProjection() { return viewProjection_; }
};
