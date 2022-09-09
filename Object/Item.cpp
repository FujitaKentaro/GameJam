#include "Item.h"
#include "Food.h"
#include <fstream>


void Item::Initialize() {
	for (int i = 0; i < 10; i++) {
		strage[5]->item = 0;
	}


}
void Item::Update() {


}
void Item::Draw() {

}
void Item::SpriteDraw() {

}

void Item::AddItem(int tribe) {
	if (strage[0]->item == false) {
		strage[0]->item = true;
		strage[0]->tribe = tribe;
	}
	else if (strage[1]->item == false) {
		strage[1]->item = true;
		strage[1]->tribe = tribe;
	}
	else if (strage[2]->item == false) {
		strage[2]->item = true;
	}
	else if (strage[3]->item == false) {
		strage[3]->item = true;
		strage[3]->tribe = tribe;
	}
	else if (strage[4]->item == false) {
		strage[4]->item = true;
		strage[4]->tribe = tribe;
	}

}

void Item::LoadItemData() {
	//�t�@�C�����J��
	std::ifstream file;
	file.open("Resources/enemyState.csv");
	assert(file.is_open());

	//�t�@�C���̓��e�𕶎���X�g���[���ɃR�s�[
	itemCommands << file.rdbuf();

	//�t�@�C�������
	file.close();
}

void Item::UpdateItemCommands(int num) {

	//�ҋ@����
	if (stay) {
		itemTime--;
		if (itemTime <= 0) {
			//�ҋ@����
			stay = false;
		}
		return;
	}

	// 1�s���̕����������
	std::string line;

	//�R�}���h���s���[�v
	while (getline(itemCommands, line)) {
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream line_stream(line);

		std::string word;
		//,��؂�ōs�̐擪��������擾
		getline(line_stream, word, ',');
		//"//"����n�܂�s�̓R�����g
		if (word.find("//") == 0) {
			//�R�����g�s���΂�
			continue;
		}
		// POP�R�}���h

		if (word.find("CURRY") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = curry;

		}

		if (word.find("SALAD") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = salada;
		}

		if (word.find("BBQ") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = yakiniku;
		}

		if (word.find("FRIEDEGG") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = medamayaki;
		}

		if (word.find("NIKUJAGA") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = nikujaga;
		}

		if (word.find("TOMATO") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = tomato;
		}

		if (word.find("OMURICE") == 0) {
			// x���W
			getline(line_stream, word, ',');
			int x = (int)std::atof(word.c_str());

			// ���
			int w = omuraisu;

		}

		if (word.find("WAIT") == 0) {
			getline(line_stream, word, ',');

			//�҂�����
			int32_t waitTime = atoi(word.c_str());

			//�ҋ@�J�n
			stay = true;

			itemTime = waitTime;
			//�R�}���h���[�v�𔲂���
			break;
		}


	}

}
