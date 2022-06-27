#include "TES3GameFile.h"

#include "TES3Util.h"

#include "TES3DataHandler.h"

namespace TES3 {
	const auto TES3_TES3File_ctor = reinterpret_cast<GameFile*(__thiscall *)(GameFile*, const char*, const char*, void*)>(0x4B3F10);
	const auto TES3_TES3File_dtor = reinterpret_cast<int(__thiscall *)(GameFile*)>(0x4B4140);
	const auto TES3_TES3File_delete = reinterpret_cast<void(__thiscall *)(GameFile*)>(0x4B48F0);
	const auto TES3_TES3File_readChunkData = reinterpret_cast<bool(__thiscall *)(GameFile*, void*, unsigned int)>(0x4B6880);
	const auto TES3_TES3File_writeChunkData = reinterpret_cast<int(__thiscall *)(GameFile*, unsigned int, const void*, unsigned int)>(0x4B6BA0);
	const auto TES3_TES3File_collectActiveMods2 = reinterpret_cast<bool(__thiscall *)(GameFile*, void *, bool)>(0x4B5BB0);
	const auto TES3_TES3File_loadByPath = reinterpret_cast<bool(__thiscall *)(GameFile*, const char*, const char*, int, bool)>(0x4B4530);
	const auto TES3_TES3File_setFilePointer = reinterpret_cast<bool(__thiscall *)(GameFile*, unsigned int)>(0x4B6520);

	using std::uint64_t;

	GameFile::GameFile(const char* path, const char* filename, void * unknown) {
		TES3_TES3File_ctor(this, path, filename, unknown);
	}

	GameFile::~GameFile() {
		TES3_TES3File_dtor(this);
	}

	void GameFile::deleteFile() {
		// Constrain to save games only
		size_t s = strlen(filename);
		if (s > 4) {
			const char *ext = filename + (s - 4);
			if (_stricmp(ext, ".ess") == 0) {
				TES3_TES3File_delete(this);
			}
		}
	}

	bool GameFile::readChunkData(void * data, unsigned int size) {
		return TES3_TES3File_readChunkData(this, data, size);
	}

	int GameFile::writeChunkData(unsigned int tag, const void * data, unsigned int size) {
		return TES3_TES3File_writeChunkData(this, tag, data, size);
	}

	const auto TES3_TES3File_writeRecordHeader = reinterpret_cast<int(__thiscall*)(GameFile*, unsigned int, unsigned int)>(0x4B6B00);
	int GameFile::writeRecordHeader(unsigned int tag, unsigned int flags) {
		return TES3_TES3File_writeRecordHeader(this, tag, flags);
	}

	const auto TES3_TES3File_endRecord = reinterpret_cast<int(__thiscall*)(GameFile*)>(0x4B6C50);
	int GameFile::endRecord() {
		return TES3_TES3File_endRecord(this);
	}

	const auto TES3_TES3File_getFirstSubrecord = reinterpret_cast<unsigned int(__thiscall*)(GameFile*)>(0x4B6750);
	unsigned int GameFile::getFirstSubrecord() {
		return TES3_TES3File_getFirstSubrecord(this);
	}

	const auto TES3_TES3File_hasNextSubrecord = reinterpret_cast<bool(__thiscall *)(GameFile*)>(0x4B67F0);
	bool GameFile::hasNextSubrecord() {
		return TES3_TES3File_hasNextSubrecord(this);
	}

	const auto TES3_TES3File_getNextSubrecord = reinterpret_cast<unsigned int(__thiscall *)(GameFile*)>(0x4B67C0);
	unsigned int GameFile::getNextSubrecord() {
		return TES3_TES3File_getNextSubrecord(this);
	}

	const auto TES3_TES3File_hasMoreRecords = reinterpret_cast<int(__thiscall*)(GameFile*)>(0x4B67F0);
	bool GameFile::hasMoreRecords() {
		return TES3_TES3File_hasMoreRecords(this);
	}

	bool GameFile::collectActiveMods(bool showMasterErrors) {
		return TES3_TES3File_collectActiveMods2(this, TES3::DataHandler::get()->nonDynamicData->gameFiles, showMasterErrors);
	}

	bool GameFile::load(int unknown1, bool unknown2) {
		return loadByPath(path, filename, unknown1, unknown2);
	}

	bool GameFile::loadByPath(const char* path, const char* filename, int unknown1, bool unknown2) {
		return TES3_TES3File_loadByPath(this, path, filename, unknown1, unknown2);
	}

	bool GameFile::setFilePointer(unsigned int offset) {
		return TES3_TES3File_setFilePointer(this, offset);
	}

	const auto TES3_TES3File_getMaster = reinterpret_cast<GameFile*(__thiscall*)(GameFile*, unsigned int)>(0x4B5CF0);
	GameFile* GameFile::getMaster(unsigned int index) {
		return TES3_TES3File_getMaster(this, index);
	}

	std::uint64_t GameFile::getFileSize() const {
		auto x = reinterpret_cast<const WIN32_FIND_DATAA*>(findData);
		uint64_t fileSize;

		fileSize = (uint64_t(x->nFileSizeHigh) << 32) + uint64_t(x->nFileSizeLow);
		return fileSize;
	}

	std::uint64_t GameFile::getModifiedTime() const {
		auto x = reinterpret_cast<const WIN32_FIND_DATAA*>(findData);
		uint64_t time;

		time = (uint64_t(x->ftLastWriteTime.dwHighDateTime) << 32) + uint64_t(x->ftLastWriteTime.dwLowDateTime);
		return time;
	}

	const char* GameFile::getFilename() const {
		return filename;
	}

	const char* GameFile::getPath() const {
		return path;
	}

	const char* GameFile::getAuthor() const {
		return author;
	}

	const char* GameFile::getDescription() const {
		return description;
	}

	float GameFile::getCurrentHealth() const {
		return gmdt.currentHealth;
	}

	float GameFile::getMaxHealth() const {
		return gmdt.maxHealth;
	}

	float GameFile::getGameHour() const {
		return gmdt.gameHour;
	}

	float GameFile::getDay() const {
		return gmdt.day;
	}

	float GameFile::getMonth() const {
		return gmdt.month;
	}

	float GameFile::getYear() const {
		return gmdt.year;
	}

	const char* GameFile::getCellName() const {
		return gmdt.cellName;
	}

	float GameFile::getDaysPassed() const {
		return gmdt.daysPassed;
	}

	const char* GameFile::getPlayerName() const {
		return gmdt.playerName;
	}

	std::span<GameFile*> GameFile::getMasters() {
		return std::span(arrayMasters, masterNames->size());
	}

}