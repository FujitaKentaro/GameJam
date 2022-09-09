#include "Food.h"
#include "Affin.h"
#include <cassert>

/// <summary>
/// ������
/// </summary>
void Food::Initialize(const Vector3& position, int tribe) {
	// ���f���ǂݍ���
	SetModel(tribe);

	// �e�N�X�`���ǂݍ���
	SetTexture(tribe);

	// ���[���h�g�����X�t�H�[��
	worldTransform_.Initialize();
	// �����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_ = position;

	worldTransform_.TransferMatrix();
}

/// <summary>
/// �X�V
/// </summary>
void Food::Update() {
	// �v���C���[��Z���W�ɍ��킹�A���H������
	if (worldTransform_.translation_.y >= 35) {
		worldTransform_.translation_.z = -40.0f;
		velocity_ = { 0.0f, -0.2f,0.0f };
	}

	// ���W���ړ������� (1�t���[�����̈ړ��ʂ𑫂�����)
	worldTransform_.translation_ += velocity_;

	// �s��̍X�V
	worldTransform_.matWorld_ = Affin::matWorld(
		worldTransform_.translation_, worldTransform_.rotation_, worldTransform_.scale_);
	worldTransform_.TransferMatrix();

	// ���Ԍo�߂Ńf�X
	if (worldTransform_.translation_.y <= -30.0f) {
		isDead_ = true;
	}
}

/// <summary>
/// �`��
/// </summary>
void Food::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
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
	Vector3 worldPos;

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Food::SetTexture(int tribe) {
	switch (tribe)
	{
	case 0:
		textureHandle_ = TextureManager::Load("materialTex/0.png");
		break;
	case 1:
		textureHandle_ = TextureManager::Load("materialTex/1.png");
		break;
	case 2:
		textureHandle_ = TextureManager::Load("materialTex/2.png");
		break;
	case 3:
		textureHandle_ = TextureManager::Load("materialTex/3.png");
		break;
	case 4:
		textureHandle_ = TextureManager::Load("materialTex/4.png");
		break;
	case 5:
		textureHandle_ = TextureManager::Load("materialTex/5.png");
		break;
	case 6:
		textureHandle_ = TextureManager::Load("materialTex/6.png");
		break;
	case 7:
		textureHandle_ = TextureManager::Load("materialTex/7.png");
		break;
	case 8:
		textureHandle_ = TextureManager::Load("materialTex/8.png");
		break;
	case 9:
		textureHandle_ = TextureManager::Load("materialTex/9.png");
		break;
	case 10:
		textureHandle_ = TextureManager::Load("materialTex/10.png");
		break;
	}
}

void Food::SetModel(int tribe) {
	switch (tribe) {
	case 0:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 1:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 2:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 3:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 4:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 5:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 6:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 7:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 8:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 9:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	case 10:
		model_ = Model::CreateFromOBJ("cube", true);
		break;
	}
}