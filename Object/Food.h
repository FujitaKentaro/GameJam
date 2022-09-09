#include "Model.h"
#include "WorldTransform.h"
#pragma once
class Item;

enum FoodID {
	curry,
	yakiniku,
	medamayaki,
	nikujaga,
	salada,
	siotomato,
	omuraisu,
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
	kome,
	banana,
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

	// ����<frm>
	static const int32_t kLifeTime = 60 * 5;

	// �f�X�^�C�}�[
	int32_t dethTimer_ = kLifeTime;
	// �f�X�t���O
	bool isDead_ = false;
	int tribe_ = 0;
	Item* item_ = nullptr;

public:
	bool IsDead() const { return isDead_; }
	void IsDeath() { isDead_ = true; }
	void SetTribe(int T);
	float r = 0.5;

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(Model* model, const Vector3& position);

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
