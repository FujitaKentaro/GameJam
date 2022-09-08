#include "Food.h"
#include "Affin.h"
#include <cassert>

/// <summary>
/// ������
/// </summary>
void Food::Initialize(Model* model, const Vector3& position) {
	// NULL�|�C���^�`�F�b�N
	assert(model);

	model_ = model;
	// �e�N�X�`���ǂݍ���
	// textureHandle_ = TextureManager::Load("ddddog.png");
	textureHandle_ = TextureManager::Load("ddddog.png");

	// ���[���h�g�����X�t�H�[��
	worldTransform_.Initialize();
	// �����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_ = position;
	//worldTransform_.scale_ = {2, 2, 2};

	// worldTransform_.TransferMatrix();
}

/// <summary>
/// �X�V
/// </summary>
void Food::Update() {

	// ���W���ړ������� (1�t���[�����̈ړ��ʂ𑫂�����)
	worldTransform_.translation_ += velocity_;

	// �s��̍X�V
	worldTransform_.matWorld_ = Affin::matWorld(
		worldTransform_.translation_, worldTransform_.rotation_, worldTransform_.scale_);
	worldTransform_.TransferMatrix();

	if (worldTransform_.translation_.y >= 50) {
		worldTransform_.translation_.z = 0.0f;
		velocity_ = { 0.0f, -0.2f,0.0f };
	}

	// ���Ԍo�߂Ńf�X
	if (--dethTimer_ <= 0) {
		isDead_ = true;
	}
}

/// <summary>
/// �`��
/// </summary>
void Food::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}

/// <summary>
/// �Փ˂����m������Ăяo�����R�[���o�b�N�֐�
/// </summary>
void Food::OnCollision() {
	// �f�X
	isDead_ = true;
}

/// <summary>
/// ���[���h���W���擾
/// </summary>
Vector3 Food::GetWorldPosition() {
	//
	Vector3 worldPos;
	//
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}