#include "Enemy.h"
#include "Player.h"
#include "GameScene.h"

/// <summary>
/// ������
/// </summary>
void Enemy::Initialize(Model* model, Vector3 trans) {
	// NULL�|�C���^�`�F�b�N
	assert(model);

	model_ = model;
	// �e�N�X�`���ǂݍ���

	//textureHandle_ = TextureManager::Load("ddddog.png");
	SetTexture();
	
	// �V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	worldTransform_.Initialize();

	worldTransform_.translation_ = trans;
	//worldTransform_.scale_ = {2,2,2};

	//�e�X�V
	//	Fire();

	//�ڋ߃t�F�[�Y������
	ApproachInitialize();
}


/// <summary>
/// �X�V
/// </summary>
void Enemy::Update(Model* model) {
	assert(model);

	// �f�X�t���O�̗������e���폜
	//bullets_.remove_if([](std::unique_ptr<EnemyBullet>& bullet) { return bullet->IsDead(); });

	//�s��X�V
	MatUpdate(worldTransform_);

	switch (phase_) {
	case Phase::None:

	case Phase::Approach:
	default:
		worldTransform_.translation_.z += -0.05f;
		if (worldTransform_.translation_.z < -30.0f) {
			phase_ = Phase::Leave;
		}

		fireTimer_--;

		if (fireTimer_ <= 0) {
			// �e�𔭎�
			Fire(model);
			// ���˃^�C�}�[��������
			fireTimer_ = kFireInterval;
		}

		break;
	case Phase::Leave:

		worldTransform_.translation_.x += -0.1f;
		worldTransform_.translation_.y += 0.1f;
		if (worldTransform_.translation_.x <= -50) {
			isDead_ = true;
		}

		break;
	}
	//�e�X�V
	/*for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Update();
	}*/

	debugText_->SetPos(10, 50);
	debugText_->Printf(
		"enemy : x,%f  y,%f z,%f,%f", worldTransform_.translation_.x, worldTransform_.translation_.y,
		worldTransform_.translation_.z, tribe);

}

/// <summary>
/// �`��
/// </summary>
void Enemy::Draw(ViewProjection viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);

	//�e�X�V
	/*for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Draw(viewProjection);
	}*/
}

/// <summary>
/// ���L�������؂�Ă���
/// </summary>
void Enemy::SetPlayer(Player* player) { player_ = player; }

/// <summary>
/// �s��X�V
/// </summary>
void Enemy::MatUpdate(WorldTransform& worldTransform_) {

	// �p�[�c�̍X�V

	// �R�ړ������s����v�Z
	worldTransform_.matWorld_ = Affin::matWorld(
		worldTransform_.translation_, worldTransform_.rotation_, worldTransform_.scale_);

	// �e�̍s����|���Z���
	if (worldTransform_.parent_ != nullptr) {
		worldTransform_.matWorld_ *= worldTransform_.parent_->matWorld_;
	}

	// �s��̓]��
	worldTransform_.TransferMatrix();
}

/// <summary>
/// �e����
/// </summary>
void Enemy::Fire(Model* model) {

	assert(player_);
	assert(model);

	//�e�̑��x
	const float kBulletSpeed = 0.5f;

	Vector3 playerPos = player_->GetWorldPosition();
	Vector3 enePos = GetWorldPosition();

	Vector3 a;
	a.x = playerPos.x - enePos.x;
	a.y = playerPos.y - enePos.y;
	a.z = playerPos.z - enePos.z;
	Vector3 nomal = MathUtility::Vector3Normalize(a);

	Vector3 velocity(nomal.x * kBulletSpeed, nomal.y * kBulletSpeed, nomal.z * kBulletSpeed);

	// ���x�x�N�g�������@�̌����ɍ��킹�ĉ�]������
	velocity = Affin::VecMat(velocity, worldTransform_.matWorld_);

	// �e�𐶐����A������
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(model, worldTransform_.translation_, velocity);

	// �e��o�^����
	//bullets_.push_back(std::move(newBullet));
	gameScene_->AddEnemyBullet(std::move(newBullet));
}

/// <summary>
/// �ڋ߃t�F�[�Y������
/// </summary>
void Enemy::ApproachInitialize() {
	// ���˃^�C�}�[��������
	fireTimer_ = kFireInterval;
}

/// <summary>
/// ���[���h���W���擾
/// </summary>
Vector3 Enemy::GetWorldPosition() {
	//
	Vector3 worldPos;
	//
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

/// <summary>
/// �Փ˂����m������Ăяo�����R�[���o�b�N�֐�
/// </summary>
void Enemy::OnCollision() {
	isDead_ = true;
	player_->AddPoint();
}

void Enemy::SetTexture() {
	switch (tribe)
	{
	case 0:
		textureHandle_ = TextureManager::Load("eneTex/0.png");
		break;
	case 1:
		textureHandle_ = TextureManager::Load("eneTex/1.png");
		break;
	case 2:
		textureHandle_ = TextureManager::Load("eneTex/2.png");
		break;
	case 3:
		textureHandle_ = TextureManager::Load("eneTex/3.png");
		break;
	case 4:
		textureHandle_ = TextureManager::Load("eneTex/4.png");
		break;
	case 5:
		textureHandle_ = TextureManager::Load("eneTex/5.png");
		break;
	case 6:
		textureHandle_ = TextureManager::Load("eneTex/6.png");
		break;
	case 7:
		textureHandle_ = TextureManager::Load("eneTex/7.png");
		break;
	case 8:
		textureHandle_ = TextureManager::Load("eneTex/8.png");
		break;
	case 9:
		textureHandle_ = TextureManager::Load("eneTex/9.png");
		break;
	case 10:
		textureHandle_ = TextureManager::Load("eneTex/10.png");
		break;
	}

	
}