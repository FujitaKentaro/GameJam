#include "Model.h"
#include "WorldTransform.h"
#pragma once

enum FoodID {
	curry,
	yakiniku,
	medamayaki,
	nikujaga,
	salada
};

enum materialID {
	butaniku,
	gyuuniku,
	toriniku,
	tamago,
	retasu,
	imo,
	tomato,
	ninnjinn,
	tamanegi,
	kome
};

/// <summary>
/// �����f�ޗp�N���X
/// </summary>
class Food {
private:
	// ���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	// ���f��
	Model* model_ = nullptr;
	// �e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;

	// ���x
	Vector3 velocity_ = { 0.0f,0.5f,0.0f };

	// �f�X�t���O
	bool isDead_ = false;


public:
	// ���a
	float r = 1.0f;

	bool IsDead() const { return isDead_; }
	void IsDeath() { isDead_ = true; }

	// texture ��ݒ�
	void SetTexture(int tribe);
	void SetModel(int tribe);

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(const Vector3& position, int tribe);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(const ViewProjection& viewProjection);

	/// <summary>
	/// �Փ˂����m������Ăяo�����R�[���o�b�N�֐�
	/// </summary>
	void OnCollision();

	/// <summary>
	/// ���[���h���W���擾
	/// </summary>
	Vector3 GetWorldPosition();
};
